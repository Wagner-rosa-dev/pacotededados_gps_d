/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelLatitude;
    QLabel *labelLongitude;
    QLabel *labelSatellite;
    QLabel *labelAltitude;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setSizeIncrement(QSize(20, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelLatitude = new QLabel(centralwidget);
        labelLatitude->setObjectName(QString::fromUtf8("labelLatitude"));
        labelLatitude->setGeometry(QRect(80, 120, 101, 31));
        labelLatitude->setAlignment(Qt::AlignCenter);
        labelLongitude = new QLabel(centralwidget);
        labelLongitude->setObjectName(QString::fromUtf8("labelLongitude"));
        labelLongitude->setGeometry(QRect(300, 120, 101, 31));
        labelLongitude->setAlignment(Qt::AlignCenter);
        labelSatellite = new QLabel(centralwidget);
        labelSatellite->setObjectName(QString::fromUtf8("labelSatellite"));
        labelSatellite->setGeometry(QRect(300, 260, 101, 31));
        labelSatellite->setAlignment(Qt::AlignCenter);
        labelAltitude = new QLabel(centralwidget);
        labelAltitude->setObjectName(QString::fromUtf8("labelAltitude"));
        labelAltitude->setGeometry(QRect(80, 260, 101, 31));
        labelAltitude->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelLatitude->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelLongitude->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelSatellite->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelAltitude->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
