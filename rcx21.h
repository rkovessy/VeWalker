#ifndef RCX21_H
#define RCX21_H

//rcx21.h
//header file for rcx21.cpp
//V 2.1 (c) 23.8.2005 by Daniel Berger (daniel.berger@tuebingen.mpg.de)


//types for sensors. Only sensor types 1,2,3 are used.
//sensor types are: 0: raw, 1: touch, 2: temperature, 3: light, 4: rotation
extern volatile int RCX_sensor_type[5];
extern volatile int RCX_sensor_mode[5];
/*modes for sensors. Only sensors 1,2,3 are used. Sensor modes are:
0: Raw - value in 0..1023
1: Boolean - Either 0 or 1
2: Edge count - Number of boolean transitions
3: Pulse count - Number of boolean transitions divided by two
4: Percentage - Raw value scaled to 0..100
5: Temperature in °C - 1/10ths of a degree, -19.8 .. 69.5
6: Temperature in °F - 1/10ths of a degree, -3.6 .. 157.1
7: Angle - 1/16ths of a rotation, represented as a signed short
*/

extern volatile int RCX_sensor_on[5];
extern volatile int RCX_motor_on[3];

extern volatile int RCX_sensor_val[5];
extern volatile int RCX_motor_val[3];

extern volatile int RCX_sound;
extern volatile int RCX_stop;
extern volatile int RCX_error;

int RCX_start(int type, char *portname); //type 1: serial, type 2: USB

#endif // RCX21_H
