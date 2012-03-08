#include "arduino.h"

ArduinoThread::ArduinoThread(QObject *parent) :
    QThread(parent)
  , m_port(0)
  , m_timer(0)
  , m_rts(false)
  , m_dtr(false)
{
    potRotation = 0;

    m_port = new SerialPort(this);
    m_port->setPort("COM22");

    if (m_port->open((QIODevice::OpenMode)1)) {
        qDebug("Arduino is running!\n");
    }
    else {
        qDebug("Could not use arduino port\n");
        m_port->close();
    }

    m_port->setRate(SerialPort::Rate9600);
    m_port->setDataBits(SerialPort::Data8);
    m_port->setParity(SerialPort::NoParity);
    m_port->setStopBits(SerialPort::OneStop);
    m_port->setFlowControl(SerialPort::UnknownFlowControl);
    m_port->setDataErrorPolicy(SerialPort::IgnorePolicy);

    qDebug() << "= Defaults parameters =";
    qDebug() << "Serial Port            : "  << m_port->portName();
    qDebug() << "Baud rate              : " << m_port->rate();
    qDebug() << "Data bits              : " << m_port->dataBits();
    qDebug() << "Parity                 : " << m_port->parity();
    qDebug() << "Stop bits              : " << m_port->stopBits();
    qDebug() << "Flow                   : " << m_port->flowControl();

    output();
}

ArduinoThread::~ArduinoThread()
{
        if (m_port->isOpen())
            m_port->close();
}


void ArduinoThread::set(double a, int t) {
    timer_interval = double(t);
    startupdating = true; // yTrans and zTrans can now be changed
    time.start();
}

int ArduinoThread::output()
{
    QByteArray garbage1;
    QByteArray garbage2;
    QByteArray data;

    if(m_port->bytesAvailable())
        garbage1 = m_port->readLine(8);

    if(m_port->bytesAvailable())
        data = m_port->readLine(8);
    else
        data = 0;

    if(m_port->bytesAvailable())
        garbage2 = m_port->readAll();

    m_port->flush();
    bool ok;
    data.chop(2);
    int returnVal = data.toInt(&ok, 10);
    //qDebug() << "-------------" << returnVal;

    return returnVal;
}

void ArduinoThread::UpdateArduino()
{
    emit sendPotRotation(potRotation);
}
