/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Led_On;
    QPushButton *Led_Off;
    QLCDNumber *lcd_byte_received;
    QLabel *label;
    QDateEdit *dateEdit;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *On_Conn;
    QPushButton *Off_Conn;
    QLabel *label_6;
    QComboBox *Port_serie;
    QComboBox *Vitesse_Transmission;
    QLCDNumber *Affichage_Donnee;
    QTextBrowser *Terminal;
    QTextBrowser *Unite_Detection;
    QLabel *label_2;
    QTextBrowser *Carte_Detection;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(824, 759);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Led_On = new QPushButton(centralwidget);
        Led_On->setObjectName("Led_On");
        Led_On->setGeometry(QRect(20, 210, 80, 24));
        Led_Off = new QPushButton(centralwidget);
        Led_Off->setObjectName("Led_Off");
        Led_Off->setGeometry(QRect(110, 210, 80, 24));
        lcd_byte_received = new QLCDNumber(centralwidget);
        lcd_byte_received->setObjectName("lcd_byte_received");
        lcd_byte_received->setGeometry(QRect(20, 130, 171, 23));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 110, 101, 16));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(670, 0, 151, 25));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 10, 49, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 60, 141, 16));
        On_Conn = new QPushButton(centralwidget);
        On_Conn->setObjectName("On_Conn");
        On_Conn->setGeometry(QRect(20, 160, 80, 24));
        Off_Conn = new QPushButton(centralwidget);
        Off_Conn->setObjectName("Off_Conn");
        Off_Conn->setGeometry(QRect(110, 160, 80, 24));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 190, 91, 16));
        Port_serie = new QComboBox(centralwidget);
        Port_serie->setObjectName("Port_serie");
        Port_serie->setGeometry(QRect(20, 30, 251, 24));
        Vitesse_Transmission = new QComboBox(centralwidget);
        Vitesse_Transmission->setObjectName("Vitesse_Transmission");
        Vitesse_Transmission->setGeometry(QRect(20, 80, 251, 24));
        Affichage_Donnee = new QLCDNumber(centralwidget);
        Affichage_Donnee->setObjectName("Affichage_Donnee");
        Affichage_Donnee->setGeometry(QRect(10, 510, 311, 141));
        Terminal = new QTextBrowser(centralwidget);
        Terminal->setObjectName("Terminal");
        Terminal->setGeometry(QRect(560, 30, 261, 661));
        Unite_Detection = new QTextBrowser(centralwidget);
        Unite_Detection->setObjectName("Unite_Detection");
        Unite_Detection->setGeometry(QRect(60, 480, 256, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 480, 49, 16));
        Carte_Detection = new QTextBrowser(centralwidget);
        Carte_Detection->setObjectName("Carte_Detection");
        Carte_Detection->setGeometry(QRect(60, 450, 256, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 450, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 824, 21));
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
        Led_On->setText(QCoreApplication::translate("MainWindow", "On", nullptr));
        Led_Off->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Bytes received", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Port Serie", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Vitesse de transmission", nullptr));
        On_Conn->setText(QCoreApplication::translate("MainWindow", "Open_Conn", nullptr));
        Off_Conn->setText(QCoreApplication::translate("MainWindow", "Close_Conn", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Led_test_Com", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Unit\303\251", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Carte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
