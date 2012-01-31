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


    qDebug("made it here");
    m_port->setPort("COM20");

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

    qDebug("outputting\n");
    output();

    bool flag = false;
}

ArduinoThread::~ArduinoThread()
{
        if (m_port->isOpen())
            m_port->close();
}

void ArduinoThread::run()
{
    m_port = new SerialPort(this);

    qDebug("made it here");
    m_port->setRate(SerialPort::Rate(3));
    m_port->setDataBits(SerialPort::DataBits(3));
    m_port->setParity(SerialPort::Parity(0));
    m_port->setStopBits(SerialPort::StopBits(0));
    m_port->setFlowControl(SerialPort::FlowControl(-1));
    m_port->setDataErrorPolicy(SerialPort::DataErrorPolicy(2));

    if (m_port->open((QIODevice::OpenMode)1)) {
        qDebug("Arduino is running!!!\n");
    }
    else {
        qDebug("Could not use arduino port\n");
        m_port->close();
    }


    bool flag = false;
    do {
        time.restart();
        output();

    } while (!flag);
    exec();
}

void ArduinoThread::set(double a, int t) {
    timer_interval = double(t);
    startupdating = true; // yTrans and zTrans can now be changed
    time.start();
}

void ArduinoThread::output()
{

    QByteArray data = m_port->readAll();
    qDebug() << "Pot value:     " << data;
}

void ArduinoThread::UpdateArduino()
{
    emit sendPotRotation(potRotation);
}
