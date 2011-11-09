#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <winbase.h>
#include "rcx21.h"


//rcx21.cpp
//direct serial LEGO Mindstorms RCX control
//V 2.1 (c) 23.8.2005 by Daniel Berger (daniel.berger@tuebingen.mpg.de),
// under usage of docs of Kekoa Proudfood and the Win32 SDK.
// With kind help from Sudhanshu Gaur (Virginia Institute of Technology) for USB support.



volatile int RCX_stop=-1; //-1: not running, 0:running, 1:about to be stopped
volatile int RCX_finished=0;
volatile int RCX_error=0;  //error code 1: tower init failed, 2: robot communication failed

//////////////////////////////////
//input/output variables

// alive, sensor 1, sensor 2, sensor 3, battery
// motor A, motor B, motor C

volatile int RCX_sensor_on[5]={0,0,0,0,0};  //1 indicates a sensor that should be polled.
volatile int RCX_motor_on[3]={0,0,0};   //1 indicates a motor that should be updated (switched on)

volatile int RCX_sensor_val[5]={0,0,0,0,0}; //values of sensors; 0 .. 1024
volatile int RCX_motor_val[3]={8,8,8};  //values of motors; -8 .. 8, 0 is float

volatile int RCX_sensor_type[5]={0,0,0,0,0}; //types for sensors. Only sensors 1,2,3 are used.
//sensor types are: 0: raw, 1: touch, 2: temperature, 3: light, 4: rotation
volatile int RCX_sensor_mode[5]={0,0,0,0,0}; //modes for sensors. Only sensors 1,2,3 are used.
/*sensor modes are:
0: Raw - value in 0..1023
1: Boolean - Either 0 or 1
2: Edge count - Number of boolean transitions
3: Pulse count - Number of boolean transitions divided by two
4: Percentage - Raw value scaled to 0..100
5: Temperature in °C - 1/10ths of a degree, -19.8 .. 69.5
6: Temperature in °F - 1/10ths of a degree, -3.6 .. 157.1
7: Angle - 1/16ths of a rotation, represented as a signed short
*/

volatile int RCX_sound=0; //0: no sound, 1: blip, 2: beep beep, 3: downward tones, 4: upward tones, 5: low buzz, 6: fast upward tones

int init_wait_ms=1;
int wait_ms=1; //wait interval between message send and receive. Increase this value in case of communication problems

//////////////////////////////////
//internal variables

int work_sensor_type[5]={0,0,0,0,0};
int last_sensor_type[5]={0,0,0,0,0}; //sensor types are only used for sensors 1,2,3.
int work_sensor_mode[5]={0,0,0,0,0};
int last_sensor_mode[5]={0,0,0,0,0}; //sensor modes are only used for sensors 1,2,3.

int work_motor_on[3]={0,0,0};
int work_motor_val[3]={8,8,8};
int last_motor_on[3]={0,0,0};
int last_motor_val[3]={8,8,8};

int motor_on_ok[3]={0,0,0};
int motor_val_ok[3]={0,0,0};

int work_error=0;

DCB dcb;
COMMTIMEOUTS tout;
HANDLE RCX_port=0;
DWORD RCX_thread_id;
char portname[256];
int porttype=0;

int RCX_close(){
  return(CloseHandle(RCX_port));
};

int RCX_open(int type, char *portname){
  //Opens the connections to the RCX via tower on serial or usb port.
  //type 1: serial port, type 2: USB port
  //portname for serial port is "COM1" for example
  //portname for USB port is "\\\\.\\LEGOTOWER1" for example
  //returns 0 if failed, 1 if successful

  if (type==1){//open serial port
    RCX_port = CreateFileA("COM6", GENERIC_READ | GENERIC_WRITE, 0, 0, CREATE_NEW, FILE_FLAG_WRITE_THROUGH, 0);

    if (RCX_port == INVALID_HANDLE_VALUE) return(0);

    //set data protocol format
    GetCommState(RCX_port,&dcb);
    FillMemory(&dcb, sizeof(dcb), 0);
    dcb.DCBlength = sizeof(dcb);
    dcb.BaudRate=CBR_2400;
    dcb.fBinary=1;
    dcb.fParity=1;
    dcb.fDtrControl=DTR_CONTROL_ENABLE;
    dcb.fRtsControl=RTS_CONTROL_ENABLE;
    dcb.ByteSize=8;
    dcb.Parity=ODDPARITY;
    dcb.StopBits=ONESTOPBIT;
    if (!SetCommState(RCX_port, &dcb)){
      RCX_close();
      return(0);
    }


    GetCommTimeouts(RCX_port,&tout);
    tout.ReadIntervalTimeout=250;
    tout.ReadTotalTimeoutConstant=10;
    tout.ReadTotalTimeoutMultiplier=10;
    tout.WriteTotalTimeoutConstant=10;
    tout.WriteTotalTimeoutMultiplier=10;
    SetCommTimeouts(RCX_port,&tout);

    SetupComm(RCX_port,65536,65536);
  } else { //type 2: open USB port
    RCX_port = CreateFileA(portname, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_FLAG_WRITE_THROUGH | FILE_FLAG_OVERLAPPED | FILE_FLAG_NO_BUFFERING, 0);
    if (RCX_port == INVALID_HANDLE_VALUE) return(0);

    GetCommTimeouts(RCX_port,&tout);
    tout.ReadIntervalTimeout=250;
    tout.ReadTotalTimeoutConstant=10;
    tout.ReadTotalTimeoutMultiplier=10;
    tout.WriteTotalTimeoutConstant=10;
    tout.WriteTotalTimeoutMultiplier=10;
    SetCommTimeouts(RCX_port,&tout);
  }


  return(1);
}


unsigned char sendbuf[256];
unsigned char recbuf[256];
OVERLAPPED ovl;

int RCX_send(unsigned char *message, int length){
  //sends a message to the RCX
  //returns 1 if write succeeded, 0 if failed
  //maximal length of message is 125 bytes
  int i;
  unsigned long res,ptr;
  int s=0;

  //create message to send
  sendbuf[0]=0x55;
  sendbuf[1]=0xff;
  sendbuf[2]=0x00;
  ptr=3;
  for (i=0; i<length; i++){
    sendbuf[ptr++]=message[i];
    sendbuf[ptr++]=message[i]^0xff;
    s+=message[i];
  }
  sendbuf[ptr++]=(unsigned char)s;
  sendbuf[ptr++]=((unsigned char)s)^0xff;

  res=0;
  ovl.Offset=0;
  ovl.OffsetHigh=0;
  ovl.hEvent=NULL;
  if(!WriteFile(RCX_port,sendbuf,ptr,&res,&ovl)){
    if (GetLastError()==ERROR_IO_PENDING){
      i=0;
      do{
        Sleep(10);
        i++;
      } while ((!HasOverlappedIoCompleted(&ovl))&&(i<50));
      if (i<50){
        return(1); //completed.
      } else {
        CancelIo(RCX_port); //cancel transmission.
        return(0); //not completed.
      }
    } else { //some error occured
      CancelIo(RCX_port); //cancel transmission.
      return(0);
    }
  }
  return(1);
}

int RCX_receive(unsigned char *rcbuf, unsigned long length){
  //attempts to read a message of specified length from the RCX
  unsigned long res=0;
  int i;

  ovl.Offset=0;
  ovl.OffsetHigh=0;
  ovl.hEvent=NULL;
  if (!ReadFile(RCX_port,rcbuf,length,&res,&ovl)){
    //return(0);
    if (GetLastError()==ERROR_IO_PENDING){
      i=0;
      do{
        Sleep(10);
        i++;
      } while ((!HasOverlappedIoCompleted(&ovl))&&(i<50));
      if (i<50){
        GetOverlappedResult(RCX_port,&ovl,&res,FALSE);
        return(res); //completed.
      } else {
        CancelIo(RCX_port); //cancel transmission.
        return(0); //not completed.
      }
    } else { //some error occured
      CancelIo(RCX_port); //cancel transmission.
      return(0);
    }
  }
  return(res);
}

int lastdecodedlength=0;

int RCX_decode(unsigned char *recbuf, int len){
//tries to decode bytestream in recbuf up to length len.
//returns -1 if failed, else decoded value
  int pos=0;
  int val=0;

  if (porttype==1){ //decode message from serial port
    if (len<4){lastdecodedlength=0; return(-1);}
    if (recbuf[0]!=0x55){lastdecodedlength=0; return(-1);}
    if (recbuf[1]!=0xff){lastdecodedlength=1; return(-1);}
    if (recbuf[2]!=0x00){lastdecodedlength=2; return(-1);}
    switch(recbuf[3]){
    case 0x10:
    case 0x18: //alive
      pos=7;
      if (len!=14){
        lastdecodedlength=4;
        val=0;
      }
      break;
    case 0x12: //get value
    case 0x1a:
      pos=11;
      break;
    case 0x30:
    case 0x38: //get battery power
      pos=7;
      break;
    }

    if (len<(pos+3)){
      lastdecodedlength=3;
      return(-1);
    }
    if (recbuf[pos]!=0x55){lastdecodedlength=pos; return(-1);}
    if (recbuf[pos+1]!=0xff){lastdecodedlength=pos+1; return(-1);}
    if (recbuf[pos+2]!=0x00){lastdecodedlength=pos+2; return(-1);}
    switch(recbuf[pos+4]){
    case 0x10:
    case 0x18: //alive
      val=1;
      lastdecodedlength=pos+4;
      break;
    case 0x12: //get sensor value
    case 0x1a:
      val=(((int)recbuf[pos+7])<<8)+recbuf[pos+5];
      lastdecodedlength=pos+8;
      break;
    case 0x30:
    case 0x38: //get battery power
      val=(((int)recbuf[pos+7])<<8)+recbuf[pos+5];
      lastdecodedlength=pos+8;
      break;
    }
  } else { //decode message from USB port
    if (len<5){lastdecodedlength=0; return(-1);} //only messages longer than 3 bytes will be processed correctly furtheron
    if (recbuf[0]!=0x55){lastdecodedlength=0; return(-1);}
    if (recbuf[1]!=0xff){lastdecodedlength=1; return(-1);}
    if (recbuf[2]!=0x00){lastdecodedlength=2; return(-1);}
    switch(recbuf[4]){
    case 0x10:
    case 0x18: //alive
      val=1;
      lastdecodedlength=5;
      break;
    case 0x12: //get sensor value
    case 0x1a:
      val=(((int)recbuf[7])<<8)+recbuf[5];
      lastdecodedlength=8;
      break;
    case 0x30:
    case 0x38: //get battery power
      val=(((int)recbuf[7])<<8)+recbuf[5];
      lastdecodedlength=8;
      break;
    default: //unknown message!
      lastdecodedlength=3;
      return(-1);
      break;
    }
  }
  return(val);
}


DWORD WINAPI RCX_loop(LPVOID lpParameter){
//void RCX_loop(){
//main routine for serial/usb I/O thread
  int i,len,val,chunksize;
  unsigned char switchbit=0;
  unsigned char mess[256];

  if (porttype==1){chunksize=16;} else {chunksize=7;} //serial and usb send different amounts of data
  RCX_finished=0;
  RCX_error=0;

  //open port to lego infrared tower
  if (!RCX_open(porttype,portname)){
    RCX_stop=-1;
    RCX_error=1;
    return(0);
  }

  //initialize: set transmitter range to 'large'
  mess[0]=0x31 | switchbit;
  switchbit^=0x08;
  mess[1]=1; //long range
  RCX_send(mess,2);
  Sleep(init_wait_ms);
  len=RCX_receive(recbuf,chunksize);
  if (len!=chunksize){
    RCX_close();
    RCX_stop=-1;
    RCX_error=2;
    return(0);
  }

  //initialize: switch motors off
  mess[0]=0x21 | switchbit;
  switchbit^=0x08;
  mess[1]=0x47; //switch off all motors
  RCX_send(mess,2);
  Sleep(init_wait_ms);
  if (RCX_receive(recbuf,chunksize)!=chunksize){
    RCX_close();
    RCX_stop=-1;
    RCX_error=2;
    return(0);
  }

  //initialize: set to forward
  mess[1]=0x87; //set to forward
  mess[0]=0xe1 | switchbit;
  switchbit^=0x08;
  RCX_send(mess,2);
  Sleep(init_wait_ms);
  if (RCX_receive(recbuf,chunksize)!=chunksize){
    RCX_close();
    RCX_stop=-1;
    RCX_error=2;
    return(0);
  }

  //initialize: set motors power level to 7
  mess[0]=0x13 | switchbit; //set motor power level
  switchbit^=0x08;
  mess[1]=7; //motors A,B,C
  mess[2]=2; //set by immediately following value
  mess[3]=7; //set all motors to initialized value (8)
  RCX_send(mess,4);
  Sleep(init_wait_ms);
  if (porttype==1) chunksize=20;  //serial port sends 20 bytes on this message, usb sends 7 as above
  if (RCX_receive(recbuf,chunksize)!=chunksize){
    RCX_close();
    RCX_stop=-1;
    RCX_error=2;
    return(0);
  }

  //initialize: set sensor types to raw
  if (porttype==1) chunksize=18;
  for (i=0; i<3; i++){
    mess[0]=0x32 | switchbit; //set sensor type
    switchbit^=0x08;
    mess[1]=i; //sensor 0,1,2
    mess[2]=0; //set to raw mode
    RCX_send(mess,3);
    Sleep(init_wait_ms);
    len=RCX_receive(recbuf,chunksize);
    if (len!=chunksize){
      RCX_close();
      RCX_stop=-1;
      RCX_error=2;
      return(0);
    }
  }

  //initialize: set sensor modes to raw
  if (porttype==1) chunksize=18;
  for (i=0; i<3; i++){
    mess[0]=0x42 | switchbit; //set sensor mode
    switchbit^=0x08;
    mess[1]=i; //sensor 0,1,2
    mess[2]=0; //set to raw mode, bool switch detection slope 0
    RCX_send(mess,3);
    Sleep(init_wait_ms);
    len=RCX_receive(recbuf,chunksize);
    if (len!=chunksize){
      RCX_close();
      RCX_stop=-1;
      RCX_error=2;
      return(0);
    }
  }

  RCX_motor_val[0]=8;
  RCX_motor_val[1]=8;
  RCX_motor_val[2]=8;

  last_motor_on[0]=0;
  last_motor_on[1]=0;
  last_motor_on[2]=0;
  last_motor_val[0]=8;
  last_motor_val[1]=8;
  last_motor_val[2]=8;

  RCX_stop=0;

  while(!RCX_stop){
    //this loop handles the interface-RCX communication
    //(in parallel with the main program, since it runs in an extra task)

    work_error=0;

    if (RCX_sound!=0){ //transmit signals for sounds
      mess[0]=0x51 | switchbit;
      mess[1]=RCX_sound-1;
      switchbit^=0x08;
      RCX_send(mess,2);
      Sleep(wait_ms);
      if (porttype==1){chunksize=16;} else {chunksize=7;}
      if (RCX_receive(recbuf,chunksize)==chunksize){ //check if success
        RCX_sound=0;
      } else {
        work_error=1;
      }
    }

    if (RCX_sensor_on[0]){ //read alive
      mess[0]=0x10 | switchbit;
      switchbit^=0x08;
      RCX_send(mess,1);
      Sleep(wait_ms);
      if (porttype==1){chunksize=14;} else {chunksize=7;}
      len=RCX_receive(recbuf,chunksize);
      if (len!=chunksize) work_error=2;
      val=RCX_decode(recbuf,len);
      if (val>=0) RCX_sensor_val[0]=val; //use data only if decoding worked
    }

    if (RCX_sensor_on[1]){ //read sensor 1
      mess[0]=0x12 | switchbit; //get value
      switchbit^=0x08;
      mess[1]=9; //get value  //12; //raw sensor value
      mess[2]=0; //sensor 1
      RCX_send(mess,3);
      Sleep(wait_ms);
      if (porttype==1){chunksize=22;} else {chunksize=11;}
      len=RCX_receive(recbuf,chunksize);
      if (len!=chunksize) work_error=2;
      val=RCX_decode(recbuf,len);
      if (val>=0) RCX_sensor_val[1]=val; //use data only if decoding worked
    }

    if (RCX_sensor_on[2]){ //read sensor 2
      mess[0]=0x12 | switchbit; //get value
      switchbit^=0x08;
      mess[1]=9; //get value //12; //raw sensor value
      mess[2]=1; //sensor 2
      RCX_send(mess,3);
      Sleep(wait_ms);
      if (porttype==1){chunksize=22;} else {chunksize=11;}
      len=RCX_receive(recbuf,chunksize);
      if (len!=chunksize) work_error=2;
      val=RCX_decode(recbuf,len);
      if (val>=0) RCX_sensor_val[2]=val; //use data only if decoding worked
    }

    if (RCX_sensor_on[3]){ //read sensor 3
      mess[0]=0x12 | switchbit; //get value
      switchbit^=0x08;
      mess[1]=9; //get value //12; //raw sensor value
      mess[2]=2; //sensor 3
      RCX_send(mess,3);
      Sleep(wait_ms);
      if (porttype==1){chunksize=22;} else {chunksize=11;}
      len=RCX_receive(recbuf,chunksize);
      if (len!=chunksize) work_error=2;
      val=RCX_decode(recbuf,len);
      if (val>=0) RCX_sensor_val[3]=val; //use data only if decoding worked
    }

    if (RCX_sensor_on[4]){ //read battery
      mess[0]=0x30 | switchbit;
      switchbit^=0x08;
      RCX_send(mess,1);
      Sleep(wait_ms);
      if (porttype==1){chunksize=18;} else {chunksize=11;}
      len=RCX_receive(recbuf,chunksize);
      if (len!=chunksize) work_error=2;
      val=RCX_decode(recbuf,len);
      if (val>=0) RCX_sensor_val[4]=val; //use data only if decoding worked
    }

    //sensor type handling
    if (porttype==1){chunksize=18;} else {chunksize=7;}
    for (i=1; i<=3; i++){
      work_sensor_type[i]=RCX_sensor_type[i];
      if ((work_sensor_type[i]<0)||(work_sensor_type[i]>4)){ //only sensor type values 0..4 allowed.
        work_sensor_type[i]=0;
        RCX_sensor_type[i]=0; //in this case, force 0
      }

      if (work_sensor_type[i]!=last_sensor_type[i]){
        mess[0]=0x32 | switchbit; //get value
        switchbit^=0x08;
        mess[1]=i-1; //sensor 0,1,2
        mess[2]=work_sensor_type[i]; //set type
        RCX_send(mess,3);
        Sleep(wait_ms);
        len=RCX_receive(recbuf,chunksize);
        if (len!=chunksize){
          work_error=2;
        } else {
          last_sensor_type[i]=work_sensor_type[i];
        }
      }
    }

    //sensor mode handling
    if (porttype==1){chunksize=18;} else {chunksize=7;}
    for (i=1; i<=3; i++){
      work_sensor_mode[i]=RCX_sensor_mode[i];
      if ((work_sensor_mode[i]<0)||(work_sensor_mode[i]>7)){ //only sensor mode values 0..7 allowed.
        work_sensor_mode[i]=0;
        RCX_sensor_mode[i]=0; //in this case, force 0
      }

      if (work_sensor_mode[i]!=last_sensor_mode[i]){
        mess[0]=0x42 | switchbit; //get value
        switchbit^=0x08;
        mess[1]=i-1; //sensor 0,1,2
        mess[2]=(work_sensor_mode[i])<<5; //bits 5-7 code the mode
        RCX_send(mess,3);
        Sleep(wait_ms);
        len=RCX_receive(recbuf,chunksize);
        if (len!=chunksize){
          work_error=2;
        } else {
          last_sensor_mode[i]=work_sensor_mode[i];
        }
      }
    }

    //motor_val handling

    //motor value changes (direction changes, may come from float but not go to float)
    //set motor direction

    motor_on_ok[0]=1;
    motor_on_ok[1]=1;
    motor_on_ok[2]=1;
    motor_val_ok[0]=1;
    motor_val_ok[1]=1;
    motor_val_ok[2]=1;

    work_motor_val[0]=RCX_motor_val[0];  //fixate values in work_motor_val (prevents problems when task switches happen and the main task changes the value)
    work_motor_val[1]=RCX_motor_val[1];
    work_motor_val[2]=RCX_motor_val[2];

    work_motor_on[0]=RCX_motor_on[0];  //fixate values in work_motor_val
    work_motor_on[1]=RCX_motor_on[1];
    work_motor_on[2]=RCX_motor_on[2];

    if (porttype==1){chunksize=16;} else {chunksize=7;}

    mess[1]=0;
    //set directions to forward in case some motors were in floating mode or backward mode and are now set to forward
    if ((work_motor_val[0]>0)&&(last_motor_val[0]<=0)) mess[1]+=1;
    if ((work_motor_val[1]>0)&&(last_motor_val[1]<=0)) mess[1]+=2;
    if ((work_motor_val[2]>0)&&(last_motor_val[2]<=0)) mess[1]+=4;
    if (mess[1]>0){
      mess[1]+=0x80; //set to forward
      mess[0]=0xe1 | switchbit; //get value
      switchbit^=0x08;

      RCX_send(mess,2);
      Sleep(wait_ms);
      if(RCX_receive(recbuf,chunksize)!=chunksize){ //check if failed
        if((mess[1]&1)!=0) motor_val_ok[0]=0;
        if((mess[1]&2)!=0) motor_val_ok[1]=0;
        if((mess[1]&4)!=0) motor_val_ok[2]=0;
        work_error=2;
      }
    }

    mess[1]=0;
    //set directions to backward in case some motors were in floating mode or forward mode and are now set to backward
    if ((work_motor_val[0]<0)&&(last_motor_val[0]>=0)) mess[1]+=1;
    if ((work_motor_val[1]<0)&&(last_motor_val[1]>=0)) mess[1]+=2;
    if ((work_motor_val[2]<0)&&(last_motor_val[2]>=0)) mess[1]+=4;
    if (mess[1]>0){
      mess[1]+=0x00; //set to backward
      mess[0]=0xe1 | switchbit; //get value
      switchbit^=0x08;

      RCX_send(mess,2);
      Sleep(wait_ms);
      if(RCX_receive(recbuf,chunksize)!=chunksize){ //check if failed
        if((mess[1]&1)!=0) motor_val_ok[0]=0;
        if((mess[1]&2)!=0) motor_val_ok[1]=0;
        if((mess[1]&4)!=0) motor_val_ok[2]=0;
        work_error=2;
      }
    }

    //motor value changes (power changes, may come from floating but not go to floating)
    //set motor power. Set several motors with one command if they are set to equal values to minimize number of messages

    if (porttype==1){chunksize=20;} else {chunksize=7;}

    mess[1]=0;
    if ((abs(work_motor_val[0])!=abs(last_motor_val[0])) && (work_motor_val[0]!=0)){
      mess[1]+=1;
      if (abs(work_motor_val[1])==abs(work_motor_val[0])) mess[1]+=2;
      if (abs(work_motor_val[2])==abs(work_motor_val[0])) mess[1]+=4;

      mess[0]=0x13 | switchbit; //get value
      switchbit^=0x08;
      mess[2]=2;
      mess[3]=abs(work_motor_val[0]);
      mess[3]--;

      RCX_send(mess,4);
      Sleep(wait_ms);
      if(RCX_receive(recbuf,chunksize)!=chunksize){
        if((mess[1]&1)!=0) motor_val_ok[0]=0;
        if((mess[1]&2)!=0) motor_val_ok[1]=0;
        if((mess[1]&4)!=0) motor_val_ok[2]=0;
        work_error=2;
      }
    }

    mess[1]=0;
    if ((abs(work_motor_val[1])!=abs(last_motor_val[1])) && (abs(work_motor_val[1])!=abs(work_motor_val[0])) && (work_motor_val[1]!=0)){
      mess[1]+=2;
      if (abs(work_motor_val[2])==abs(work_motor_val[1])) mess[1]+=4;

      mess[0]=0x13 | switchbit; //get value
      switchbit^=0x08;
      mess[2]=2;
      mess[3]=abs(work_motor_val[1]);
      mess[3]--;

      RCX_send(mess,4);
      Sleep(wait_ms);
      if(RCX_receive(recbuf,chunksize)!=chunksize){
        if((mess[1]&1)!=0) motor_val_ok[0]=0;
        if((mess[1]&2)!=0) motor_val_ok[1]=0;
        if((mess[1]&4)!=0) motor_val_ok[2]=0;
        work_error=2;
      }
    }

    mess[1]=0;
    if ((abs(work_motor_val[2])!=abs(last_motor_val[2]))
     && ((abs(work_motor_val[2])!=abs(work_motor_val[1])) || (abs(work_motor_val[1])==abs(last_motor_val[1])))
     && ((abs(work_motor_val[2])!=abs(work_motor_val[0])) || (abs(work_motor_val[0])==abs(last_motor_val[0])))
     && (work_motor_val[2]!=0)){
      mess[1]+=4;

      mess[0]=0x13 | switchbit; //get value
      switchbit^=0x08;
      mess[2]=2;
      mess[3]=abs(work_motor_val[2]);
      mess[3]--;

      RCX_send(mess,4);
      Sleep(wait_ms);
      if(RCX_receive(recbuf,chunksize)!=chunksize){
        if((mess[1]&1)!=0) motor_val_ok[0]=0;
        if((mess[1]&2)!=0) motor_val_ok[1]=0;
        if((mess[1]&4)!=0) motor_val_ok[2]=0;
        work_error=2;
      }
    }

    //motor_on handling

    if (porttype==1){chunksize=16;} else {chunksize=7;}

    //switch motors from off to on or motor leaves float, motor is on
    mess[1]=0;
    if (((work_motor_on[0]!=0) && (last_motor_on[0]==0) && (work_motor_val[0]!=0))
     || ((work_motor_val[0]!=0) && (last_motor_val[0]==0) && (work_motor_on[0]!=0))) mess[1]+=1;
    if (((work_motor_on[1]!=0) && (last_motor_on[1]==0) && (work_motor_val[1]!=0))
     || ((work_motor_val[1]!=0) && (last_motor_val[1]==0) && (work_motor_on[1]!=0))) mess[1]+=2;
    if (((work_motor_on[2]!=0) && (last_motor_on[2]==0) && (work_motor_val[2]!=0))
     || ((work_motor_val[2]!=0) && (last_motor_val[2]==0) && (work_motor_on[2]!=0))) mess[1]+=4;
    if (mess[1]>0){
      mess[1]+=0x80; //switch on motors
      mess[0]=0x21 | switchbit; //get value
      switchbit^=0x08;

      RCX_send(mess,2);
      Sleep(wait_ms);
      if(RCX_receive(recbuf,chunksize)!=chunksize){
        if((mess[1]&1)!=0) motor_on_ok[0]=0;
        if((mess[1]&2)!=0) motor_on_ok[1]=0;
        if((mess[1]&4)!=0) motor_on_ok[2]=0;
        work_error=2;
      }
    }

    //switch motors from off to float mode or motor is on and val goes to 0 (float)
    mess[1]=0;
    if (((work_motor_on[0]!=0) && (last_motor_on[0]==0) && (work_motor_val[0]==0))
     || ((work_motor_val[0]==0) && (last_motor_val[0]!=0) && (work_motor_on[0]!=0))) mess[1]+=1;
    if (((work_motor_on[1]!=0) && (last_motor_on[1]==0) && (work_motor_val[1]==0))
     || ((work_motor_val[1]==0) && (last_motor_val[1]!=0) && (work_motor_on[1]!=0))) mess[1]+=2;
    if (((work_motor_on[2]!=0) && (last_motor_on[2]==0) && (work_motor_val[2]==0))
     || ((work_motor_val[2]==0) && (last_motor_val[2]!=0) && (work_motor_on[2]!=0))) mess[1]+=4;
    if (mess[1]>0){
      mess[1]+=0x00; //switch on in float mode
      mess[0]=0x21 | switchbit;
      switchbit^=0x08;

      RCX_send(mess,2);
      Sleep(wait_ms);
      if(RCX_receive(recbuf,chunksize)!=chunksize){
        if((mess[1]&1)!=0) motor_on_ok[0]=0;
        if((mess[1]&2)!=0) motor_on_ok[1]=0;
        if((mess[1]&4)!=0) motor_on_ok[2]=0;
        work_error=2;
      }
    }

    //switch motors off?
    if (((work_motor_on[0]==0)&&(last_motor_on[0]!=0))||((work_motor_on[1]==0)&&(last_motor_on[1]!=0))||((work_motor_on[2]==0)&&(last_motor_on[2]!=0))){
      //some motors have to be switched off
      mess[0]=0x21 | switchbit;
      switchbit^=0x08;
      mess[1]=0;
      if (work_motor_on[0]==0) mess[1]+=1;
      if (work_motor_on[1]==0) mess[1]+=2;
      if (work_motor_on[2]==0) mess[1]+=4;
      mess[1]+=0x40; //switch off motors

      RCX_send(mess,2);
      Sleep(wait_ms);
      if(RCX_receive(recbuf,chunksize)!=chunksize){
        if((mess[1]&1)!=0) motor_on_ok[0]=0;
        if((mess[1]&2)!=0) motor_on_ok[1]=0;
        if((mess[1]&4)!=0) motor_on_ok[2]=0;
        work_error=2;
      }
    }

    //store current state for use in the next loop
    if (motor_on_ok[0]) last_motor_on[0]=work_motor_on[0];
    if (motor_on_ok[1]) last_motor_on[1]=work_motor_on[1];
    if (motor_on_ok[2]) last_motor_on[2]=work_motor_on[2];

    if (motor_val_ok[0]) last_motor_val[0]=work_motor_val[0];
    if (motor_val_ok[1]) last_motor_val[1]=work_motor_val[1];
    if (motor_val_ok[2]) last_motor_val[2]=work_motor_val[2];

    RCX_error=work_error;

  }
  len=RCX_close();
  RCX_stop=0;
  RCX_finished=1;
  return(1);
}


int RCX_start(int type, char *in_portname){
  //forks task for serial/usb port handling and returns 1 if success, 0 if failed
  //type 1: serial port, type 2: USB port
  //portname for serial port is "COM1" for example
  //portname for USB port is "\\\\.\\LEGOTOWER1" for example
  //to stop thread, set global variable RCX_stop to 1

  int i=0;
  while(in_portname[i]!=0){
    portname[i]=in_portname[i];
    i++;
  }
  portname[i]=0;
  porttype=type;
  RCX_stop=1;
  CreateThread(NULL,0,&RCX_loop,0,0,&RCX_thread_id); //fork thread
  while(RCX_stop==1) Sleep(10); //wait until thread has been initialized
  if (RCX_stop==-1) return(0);
  return(1);
}


