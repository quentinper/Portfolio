/********************************************************************************
** Form generated from reading UI file 'Logiciel_IHM_SAE_Quentin_Perbost.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGICIEL_IHM_SAE_QUENTIN_PERBOST_H
#define UI_LOGICIEL_IHM_SAE_QUENTIN_PERBOST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Calibration;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *On_Conn;
    QPushButton *Off_Conn;
    QLabel *label_6;
    QComboBox *Port_serie;
    QComboBox *Vitesse_Transmission;
    QTextBrowser *Terminal;
    QPushButton *Clear_Console;
    QFrame *frame_2;
    QLabel *label_3;
    QLabel *label_2;
    QLCDNumber *Affichage_Donnee;
    QTextBrowser *Carte_Detect;
    QTextBrowser *Unit_Detect;
    QRadioButton *Change_Unit;
    QFrame *frame_3;
    QPushButton *Copy_Console;
    QFrame *frame_4;
    QPushButton *On_LED;
    QPushButton *Off_LED;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *frame_5;
    QFrame *frame;
    QPushButton *Chek_Tension;
    QLabel *label_11;
    QLabel *label_12;
    QCommandLinkButton *Send_Temperature;
    QPlainTextEdit *Temperature_selected;
    QLCDNumber *Vcom;
    QLCDNumber *Vs;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(857, 784);
        MainWindow->setMaximumSize(QSize(1080000, 1920000));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Calibration = new QPushButton(centralwidget);
        Calibration->setObjectName("Calibration");
        Calibration->setGeometry(QRect(20, 160, 101, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 10, 61, 16));
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
        Terminal = new QTextBrowser(centralwidget);
        Terminal->setObjectName("Terminal");
        Terminal->setGeometry(QRect(510, 30, 321, 661));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setKerning(false);
        Terminal->setFont(font1);
        Terminal->setFrameShadow(QFrame::Plain);
        Terminal->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        Terminal->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Terminal->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        Clear_Console = new QPushButton(centralwidget);
        Clear_Console->setObjectName("Clear_Console");
        Clear_Console->setGeometry(QRect(510, 690, 161, 24));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 440, 331, 231));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 10, 49, 16));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 40, 49, 16));
        Affichage_Donnee = new QLCDNumber(frame_2);
        Affichage_Donnee->setObjectName("Affichage_Donnee");
        Affichage_Donnee->setEnabled(true);
        Affichage_Donnee->setGeometry(QRect(10, 70, 311, 141));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        Affichage_Donnee->setFont(font2);
        Affichage_Donnee->setInputMethodHints(Qt::ImhNone);
        Affichage_Donnee->setFrameShape(QFrame::Box);
        Affichage_Donnee->setFrameShadow(QFrame::Plain);
        Affichage_Donnee->setSmallDecimalPoint(false);
        Affichage_Donnee->setMode(QLCDNumber::Dec);
        Affichage_Donnee->setSegmentStyle(QLCDNumber::Flat);
        Affichage_Donnee->setProperty("intValue", QVariant(0));
        Carte_Detect = new QTextBrowser(frame_2);
        Carte_Detect->setObjectName("Carte_Detect");
        Carte_Detect->setGeometry(QRect(110, 10, 151, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        Carte_Detect->setFont(font3);
        Carte_Detect->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Unit_Detect = new QTextBrowser(frame_2);
        Unit_Detect->setObjectName("Unit_Detect");
        Unit_Detect->setGeometry(QRect(110, 40, 151, 21));
        Unit_Detect->setFont(font3);
        Unit_Detect->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Change_Unit = new QRadioButton(frame_2);
        Change_Unit->setObjectName("Change_Unit");
        Change_Unit->setGeometry(QRect(280, 40, 41, 22));
        Unit_Detect->raise();
        Carte_Detect->raise();
        label_3->raise();
        label_2->raise();
        Affichage_Donnee->raise();
        Change_Unit->raise();
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(500, 20, 341, 701));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        Copy_Console = new QPushButton(frame_3);
        Copy_Console->setObjectName("Copy_Console");
        Copy_Console->setGeometry(QRect(170, 670, 161, 24));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(10, 200, 181, 81));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        On_LED = new QPushButton(frame_4);
        On_LED->setObjectName("On_LED");
        On_LED->setGeometry(QRect(10, 30, 80, 24));
        Off_LED = new QPushButton(frame_4);
        Off_LED->setObjectName("Off_LED");
        Off_LED->setGeometry(QRect(90, 30, 80, 24));
        label = new QLabel(frame_4);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 0, 141, 20));
        label->raise();
        On_LED->raise();
        Off_LED->raise();
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setEnabled(true);
        label_7->setGeometry(QRect(290, 0, 201, 81));
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setFrameShape(QFrame::NoFrame);
        label_7->setPixmap(QPixmap(QString::fromUtf8("Iut_cergy_pontoise_logo.png")));
        label_7->setScaledContents(true);
        label_7->setOpenExternalLinks(false);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(-10, -25, 861, 761));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/new/Image/Fond.png")));
        label_8->setScaledContents(true);
        label_8->setOpenExternalLinks(false);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(-10, 0, 861, 741));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/new/Image/Fond.png")));
        label_9->setScaledContents(true);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(300, 0, 191, 71));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/new/Image/Logo.png")));
        label_10->setScaledContents(true);
        frame_5 = new QFrame(centralwidget);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(10, 0, 281, 191));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 290, 331, 141));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Chek_Tension = new QPushButton(frame);
        Chek_Tension->setObjectName("Chek_Tension");
        Chek_Tension->setGeometry(QRect(20, 30, 141, 24));
        label_11 = new QLabel(frame);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 10, 121, 16));
        label_12 = new QLabel(frame);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 70, 181, 16));
        Send_Temperature = new QCommandLinkButton(frame);
        Send_Temperature->setObjectName("Send_Temperature");
        Send_Temperature->setGeometry(QRect(180, 90, 31, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font4.setBold(false);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setStrikeOut(false);
        font4.setKerning(false);
        Send_Temperature->setFont(font4);
        Send_Temperature->setIconSize(QSize(30, 30));
        Send_Temperature->setCheckable(false);
        Send_Temperature->setChecked(false);
        Send_Temperature->setAutoDefault(false);
        Temperature_selected = new QPlainTextEdit(frame);
        Temperature_selected->setObjectName("Temperature_selected");
        Temperature_selected->setGeometry(QRect(20, 90, 151, 31));
        Temperature_selected->setFrameShape(QFrame::Box);
        Temperature_selected->setFrameShadow(QFrame::Plain);
        Temperature_selected->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Temperature_selected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Vcom = new QLCDNumber(frame);
        Vcom->setObjectName("Vcom");
        Vcom->setGeometry(QRect(180, 30, 64, 23));
        Vcom->setFrameShadow(QFrame::Plain);
        Vcom->setSegmentStyle(QLCDNumber::Flat);
        Vs = new QLCDNumber(frame);
        Vs->setObjectName("Vs");
        Vs->setGeometry(QRect(250, 30, 64, 23));
        Vs->setFrameShadow(QFrame::Plain);
        Vs->setSegmentStyle(QLCDNumber::Flat);
        label_13 = new QLabel(frame);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(190, 10, 49, 16));
        label_14 = new QLabel(frame);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(260, 10, 49, 16));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(0, 710, 181, 16));
        MainWindow->setCentralWidget(centralwidget);
        label_8->raise();
        label_9->raise();
        frame->raise();
        frame_4->raise();
        frame_5->raise();
        frame_3->raise();
        frame_2->raise();
        Calibration->raise();
        label_4->raise();
        label_5->raise();
        On_Conn->raise();
        Off_Conn->raise();
        label_6->raise();
        Port_serie->raise();
        Vitesse_Transmission->raise();
        Terminal->raise();
        Clear_Console->raise();
        label_7->raise();
        label_10->raise();
        label_15->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SAE Logiciel IHM Quentin Perbost", nullptr));
        Calibration->setText(QCoreApplication::translate("MainWindow", "Debut Calibration", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Port Serie", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Vitesse de transmission", nullptr));
        On_Conn->setText(QCoreApplication::translate("MainWindow", "Ouvrir Connexion", nullptr));
        Off_Conn->setText(QCoreApplication::translate("MainWindow", "Fermer Connexion", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Nouvelle Calibration", nullptr));
        Clear_Console->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Carte", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Unit\303\251", nullptr));
        Change_Unit->setText(QCoreApplication::translate("MainWindow", "\302\260F", nullptr));
        Copy_Console->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        On_LED->setText(QCoreApplication::translate("MainWindow", "Allumer Led", nullptr));
        Off_LED->setText(QCoreApplication::translate("MainWindow", "Eteindre Led", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Verification liason serie ", nullptr));
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        Chek_Tension->setText(QCoreApplication::translate("MainWindow", "Chek Tension Capteur ", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Maintenance Capteur ", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Temp\303\251rature de Calibration ", nullptr));
        Send_Temperature->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Vcom", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Vs", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Quentin Perbost Conception \302\251", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGICIEL_IHM_SAE_QUENTIN_PERBOST_H
