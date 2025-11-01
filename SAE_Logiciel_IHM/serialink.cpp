// Dans serialink.cpp

#include "serialink.h"
#include <QDebug>
serialink::serialink(QObject *parent) : QObject(parent)
{
    _serial.setDataBits(QSerialPort::Data8);
    _serial.setParity(QSerialPort::NoParity);
    _serial.setStopBits(QSerialPort::OneStop);
    _serial.setFlowControl(QSerialPort::NoFlowControl);

    // Connexion du signal readyRead pour recevoir de nouvelles données
    connect(&_serial, &QSerialPort::readyRead, this, &serialink::newData);
}

serialink::~serialink()
{
    closeConnection();
}

void serialink::openConnection(const QString &portName, qint32 baudRate)
{
    _serial.setPortName(portName);
    _serial.setBaudRate(baudRate);

    if (_serial.open(QIODevice::ReadWrite)) {
        qDebug() << "Connexion au port série réussie : " << _serial.portName();
    } else {
        qDebug() << "Impossible d'ouvrir le port série :" << _serial.portName();
    }
}

void serialink::write(const char* messageToWrite)
{
    _serial.write(messageToWrite);
}

void serialink::closeConnection()
{
    _serial.close();
}

bool serialink::isOpen()
{
    return _serial.isOpen();
}

bool serialink::isWritable()
{
    return _serial.isWritable();
}

void serialink::newData()
{
    emit readyRead(); // Émet le signal readyRead lorsque de nouvelles données sont disponibles
    emit gotNewData(_serial.readAll()); // Émet également un signal avec les nouvelles données
}

QByteArray serialink::readAll() // Définition de la fonction readAll()
{
    return _serial.readAll();
}
