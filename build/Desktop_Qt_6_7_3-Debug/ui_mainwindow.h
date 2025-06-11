/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelLatitude;
    QLabel *labelAltitude;
    QLabel *labelSatellite;
    QLabel *labelLongitude;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *labelHora;
    QLabel *labelData;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setSizeIncrement(QSize(20, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 20, 131, 511));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelLatitude = new QLabel(gridLayoutWidget);
        labelLatitude->setObjectName("labelLatitude");
        labelLatitude->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelLatitude, 2, 0, 1, 1);

        labelAltitude = new QLabel(gridLayoutWidget);
        labelAltitude->setObjectName("labelAltitude");
        labelAltitude->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelAltitude, 4, 0, 1, 1);

        labelSatellite = new QLabel(gridLayoutWidget);
        labelSatellite->setObjectName("labelSatellite");
        labelSatellite->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelSatellite, 5, 0, 1, 1);

        labelLongitude = new QLabel(gridLayoutWidget);
        labelLongitude->setObjectName("labelLongitude");
        labelLongitude->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(labelLongitude, 3, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 20, 161, 111));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 160, 161, 101));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 280, 161, 111));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 410, 161, 111));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelHora = new QLabel(centralwidget);
        labelHora->setObjectName("labelHora");
        labelHora->setGeometry(QRect(720, 480, 67, 17));
        labelData = new QLabel(centralwidget);
        labelData->setObjectName("labelData");
        labelData->setGeometry(QRect(390, 50, 121, 61));
        labelData->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelLatitude->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelAltitude->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelSatellite->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelLongitude->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Latitude", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Longitude", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Altitude", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "N\302\260 de Satelites", nullptr));
        labelHora->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelData->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
