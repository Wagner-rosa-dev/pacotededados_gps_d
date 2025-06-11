// mainwindow.cpp - CORRIGIDO

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_gpsReader = new GpsReader(this);

    //Conecta o sinal da nossa classe GpsReader ao slot da MainWindow
    connect(m_gpsReader, &GpsReader::newGpsDataReady, this, &MainWindow::updateGpsData);

    //Tenta conectar ao GPS
    // CORRIGIDO: Nome da função "connectToGps"
    if (!m_gpsReader->connectToGps("/dev/ttyACM0")) {
        //Mostra mensagem de erro na ui se a conexão falhar
        ui->labelLatitude->setText("erro:GPS nao conectado");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//este slot sera chamado toda vez que o gpsreader emiti o sinal com novoc dados
void MainWindow::updateGpsData(const GpsData &data)
{
    //Atualiza os labels na sua interface grafica
    //o "f" indica o formato de ponto flutuante, com 6 casa de precisão
    ui->labelLatitude->setText(QString::number(data.latitude, 'f', 6));
    ui->labelLongitude->setText(QString::number(data.longitude, 'f', 6));
    ui->labelAltitude->setText(QString::number(data.altitude, 'f', 1) + " m");

    ui->labelSatellite->setText(QString::number(data.satelites));

    if (data.fixTime.isValid()) {
        ui->labelHora->setText(data.fixTime.toString("hh:mm:ss"));
    }
    if (data.fixDate.isValid()) {
        ui->labelData->setText(data.fixDate.toString("dd/MM/yyyy"));
    }
}
