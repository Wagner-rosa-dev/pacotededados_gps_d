#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gpsreader.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//slot para receber e exibit os dados do GPS
    void updateGpsData(const GpsData &data);

private:
    Ui::MainWindow *ui;
    GpsReader *m_gpsReader; // objeto da classe de gps
};
#endif // MAINWINDOW_H
