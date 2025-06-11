// gpsreader.cpp - CORRIGIDO

#include "gpsreader.h"
#include <QDebug>

GpsReader::GpsReader(QObject *parent) : QObject(parent)
{
    m_serialPort = new QSerialPort(this);

    //conecta o sinal readyRead() da porta serial ao slot handlereadyread()
    connect(m_serialPort, &QSerialPort::readyRead, this, &GpsReader::handleReadyRead);
    connect(m_serialPort, &QSerialPort::errorOccurred, this, &GpsReader::handleError);
}

GpsReader::~GpsReader()
{
    disconnectFromGps();
}

// CORRIGIDO: Nome da função "connectToGps"
bool GpsReader::connectToGps(const QString &portName, qint32 baudRate)
{
    m_serialPort->setPortName(portName);
    m_serialPort->setBaudRate(baudRate); // A maioria dos gps usa 4800 ou 9600
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (m_serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << "Conectado com sucesso a" << portName;
        return true;
    } else {
        qDebug() << "Erro ao conectar a" << portName << ":" << m_serialPort->errorString();
        return false;
    }
}

// ADICIONADO: Implementação da função que faltava
void GpsReader::disconnectFromGps()
{
    if (m_serialPort->isOpen()) {
        m_serialPort->close();
    }
}


//leitor do gps
void GpsReader::handleReadyRead()
{
    //le todos os dados disponiveis e os adiciona ao nosso buffer
    m_readBuffer.append(m_serialPort->readAll());

    //Processa o buffer linha por linha
    //um loop é usado porque multiplos pacotes podem chegar de uma vez
    while (m_readBuffer.contains('\n')) {
        int newlineIndex = m_readBuffer.indexOf('\n');
        QByteArray line = m_readBuffer.left(newlineIndex + 1).trimmed();//pega uma linha e remove os espaços
        m_readBuffer.remove(0, newlineIndex + 1); // Remove a linha processada do buffer

        if (line.startsWith('$')) {
            parseNmeaSentence(line);
        }
    }
}

//função para fazer o parse(analise) da sentença NMEA
void GpsReader::parseNmeaSentence(const QByteArray &sentence)
{
    QString sentenceStr(sentence);
    QStringList parts = sentenceStr.split(',');

    if (parts.isEmpty()) return;

    //Foco na sntença $GPGGA, que é a mais completa
    if (parts[0] == "$GPGGA") {
        if (parts.size() > 10 && parts[6].toInt() > 0) { //Verifica se tem dados e se o fix é valido
            GpsData data;

            data.latitude = convertNmeaToDecimal(parts[2], parts[3]);
            data.longitude = convertNmeaToDecimal(parts[4], parts[5]);
            data.satelites = parts[7].toInt();
            data.altitude = parts[9].toDouble();

            //emite o sinal com os dados processados
            //qualquer outra parte do seu programa pode ouvir este sinal.
            emit newGpsDataReady(data);
        }
    }
    //pode ser colocar mais else if para parsear(analisar) outras sentença como o exemplo do $GPRMC
    else if (parts[0] == "$GPRMC") {
        //Verifica se o pacote é valido (Status "A") e se tem campo de data
        if (parts.size() > 9 && parts[2] == "A") {
            //Atualiza a data e a hora na nossa variavel membro
            m_currentGpsData.fixTime = QTime::fromString(parts[1], "hhmmss.z");
            m_currentGpsData.fixDate = QDate::fromString(parts[9], "ddMMyy");

            emit newGpsDataReady(m_currentGpsData);
        }
    }


}

//Função auxiliar para converter o formato NMEA (ddmm.mmmm) para graus decimais
double GpsReader::convertNmeaToDecimal(const QString &nmeaCoord, const QString &hemisphere)
{
    if (nmeaCoord.isEmpty()) return 0.0;

    int dotIndex = nmeaCoord.indexOf('.');
    if (dotIndex == -1) return 0.0;

    //Extrai os graus em minutos
    QString degreesStr = nmeaCoord.left(dotIndex - 2);
    QString minuteStr = nmeaCoord.mid(dotIndex - 2);

    double decimalDegrees = degreesStr.toDouble() + (minuteStr.toDouble() / 60.0);

    //ajusta o sinal baseado no hemisferio
    if (hemisphere == "S" || hemisphere == "W") {
        decimalDegrees *= -1.0;
    }

    return decimalDegrees;
}

void GpsReader::handleError(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError) {
        // CORRIGIDO: Erro de digitação "prta" -> "porta"
        qDebug() << "Ocorreu um erro na porta serial:" << m_serialPort->errorString();
    }
}
