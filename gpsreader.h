#ifndef GPSREADER_H
#define GPSREADER_H

#include <QObject>
#include <QSerialPort>
#include "gps_data.h"

class GpsReader : public QObject
{
    Q_OBJECT // macro obrigatorio para classes que usam slots e sinais

public:
    explicit GpsReader(QObject *parent = nullptr);
    ~GpsReader();

    //Metodo para iniciar a conexão com a porta serial
    bool connectToGps(const QString &portName, qint32 baudRate = 9600);
    void disconnectFromGps();

signals:
    //Sinal emitido sempre que novos dados de GPS são processados
    void newGpsDataReady(const GpsData &data);

private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);

private:
    void parseNmeaSentence(const QByteArray &sentence);
    double convertNmeaToDecimal(const QString &nmeaCoord, const QString &hemisphere);

    QSerialPort *m_serialPort; // Ponteiro para o objeto da porta serial
    QByteArray m_readBuffer; // Buffer para acumular dados parciais

    GpsData m_currentGpsData;  //para guardar o estado atual dos dados
};


#endif // GPSREADER_H
