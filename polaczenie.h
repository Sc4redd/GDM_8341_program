#ifndef POLACZENIE_H
#define POLACZENIE_H

#include <QSerialPort>


class polaczenie : public QObject
{


public:
    polaczenie(const QByteArray &port, int Baud);
     QSerialPort *serial;
     void WriteData(const QByteArray &data);
  void SerialConnect(const QByteArray &port,int Baud);
    bool polaczono;
};

#endif // POLACZENIE_H
