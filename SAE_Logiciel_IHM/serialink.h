#ifndef SERIALINK_H
#define SERIALINK_H

#include <QObject>

#include <QSerialPort>

class serialink : public QObject
{
    Q_OBJECT
public:
    explicit serialink(QObject *parent = nullptr);
    ~serialink();
     void openConnection(const QString &portName, qint32 baudRate);
    void closeConnection();
    void write(const char* messageToWrite);
    bool isOpen();
    bool isWritable();
    void startReading();
    QByteArray readAll();
public slots:


private slots:
    void newData();


signals:
    void gotNewData(QByteArray data);
     void readyRead(); // Déclaration du signal readyRead

private:
     QSerialPort _serial;
     qint32 baudRate;
};


#endif // SERIALINK_H
