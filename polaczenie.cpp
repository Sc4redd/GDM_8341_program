#include "polaczenie.h"
#include <QObject>
#include <QMetaObject>


polaczenie::polaczenie(const QByteArray &port,int Baud)
{
    SerialConnect(port,Baud);
}



void polaczenie::SerialConnect(const QByteArray &port,int Baud)
{
    Baud= Baud+1;

    serial = new QSerialPort();

    serial->setPortName(port);

    switch (Baud) {
   case 1:
        serial->setBaudRate(QSerialPort::Baud1200);
       break;
   case 2:
           serial->setBaudRate(QSerialPort::Baud2400);
          break;
   case 3:
           serial->setBaudRate(QSerialPort::Baud4800);
          break;
   case 4:
           serial->setBaudRate(QSerialPort::Baud9600);
          break;
   case 5:
           serial->setBaudRate(QSerialPort::Baud19200);
          break;
   case 6:
           serial->setBaudRate(QSerialPort::Baud38400);
          break;
   case 7:
           serial->setBaudRate(QSerialPort::Baud57600);
          break;
   case 8:
           serial->setBaudRate(QSerialPort::Baud115200);
          break;
   }

    serial->setDataBits(QSerialPort::Data8);

    serial->setParity(QSerialPort::NoParity);

    serial->setStopBits(QSerialPort::OneStop);

    serial->setFlowControl(QSerialPort::NoFlowControl);

    polaczono = serial->open(QIODevice::ReadWrite);
    if(polaczono) qDebug("Polaczono z portem %s ", port.toStdString().c_str());

}



void polaczenie::WriteData(const QByteArray &data)
{
    serial->write(data);
}




