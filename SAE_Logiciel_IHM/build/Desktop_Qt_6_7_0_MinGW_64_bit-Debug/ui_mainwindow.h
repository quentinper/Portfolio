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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
    QPushButton *Calibration;
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
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *Clear_Console;
    QPushButton *Copy_Console;
    QTextBrowser *Unite_detecte;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QMenu *menuSAE_Logiciel_IHM_Quentin_Perbost;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(824, 759);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Calibration = new QPushButton(centralwidget);
        Calibration->setObjectName("Calibration");
        Calibration->setGeometry(QRect(20, 160, 81, 24));
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
        On_Conn->setGeometry(QRect(20, 110, 111, 24));
        Off_Conn = new QPushButton(centralwidget);
        Off_Conn->setObjectName("Off_Conn");
        Off_Conn->setGeometry(QRect(160, 110, 111, 24));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 140, 101, 16));
        Port_serie = new QComboBox(centralwidget);
        Port_serie->setObjectName("Port_serie");
        Port_serie->setGeometry(QRect(20, 30, 251, 24));
        Vitesse_Transmission = new QComboBox(centralwidget);
        Vitesse_Transmission->setObjectName("Vitesse_Transmission");
        Vitesse_Transmission->setGeometry(QRect(20, 80, 251, 24));
        Affichage_Donnee = new QLCDNumber(centralwidget);
        Affichage_Donnee->setObjectName("Affichage_Donnee");
        Affichage_Donnee->setGeometry(QRect(10, 510, 311, 141));
        Affichage_Donnee->setFrameShape(QFrame::Box);
        Terminal = new QTextBrowser(centralwidget);
        Terminal->setObjectName("Terminal");
        Terminal->setGeometry(QRect(520, 30, 301, 661));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 480, 49, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 450, 49, 16));
        Clear_Console = new QPushButton(centralwidget);
        Clear_Console->setObjectName("Clear_Console");
        Clear_Console->setGeometry(QRect(520, 690, 151, 24));
        Copy_Console = new QPushButton(centralwidget);
        Copy_Console->setObjectName("Copy_Console");
        Copy_Console->setGeometry(QRect(670, 690, 151, 24));
        Unite_detecte = new QTextBrowser(centralwidget);
        Unite_detecte->setObjectName("Unite_detecte");
        Unite_detecte->setGeometry(QRect(60, 480, 256, 21));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(60, 450, 251, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 824, 21));
        menuSAE_Logiciel_IHM_Quentin_Perbost = new QMenu(menubar);
        menuSAE_Logiciel_IHM_Quentin_Perbost->setObjectName("menuSAE_Logiciel_IHM_Quentin_Perbost");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSAE_Logiciel_IHM_Quentin_Perbost->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Calibration->setText(QCoreApplication::translate("MainWindow", "On", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Port Serie", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Vitesse de transmission", nullptr));
        On_Conn->setText(QCoreApplication::translate("MainWindow", "Ouvrir Connexion", nullptr));
        Off_Conn->setText(QCoreApplication::translate("MainWindow", "Fermer Connexion", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "New Calibration", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Unit\303\251", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Carte", nullptr));
        Clear_Console->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        Copy_Console->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        menuSAE_Logiciel_IHM_Quentin_Perbost->setTitle(QCoreApplication::translate("MainWindow", "SAE_Logiciel_IHM_Quentin_Perbost", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
