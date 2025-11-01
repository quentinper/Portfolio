#include "Logiciel_IHM_SAE_Quentin_Perbost.h"
#include "ui_Logiciel_IHM_SAE_Quentin_Perbost.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connexions des signaux et des slots
    connect(ui->Vitesse_Transmission, &QComboBox::currentTextChanged, this, &MainWindow::Vitesse_Transmission);
    connect(ui->Port_serie, &QComboBox::currentTextChanged, this, &MainWindow::Port_serie);
    connect(ui->Clear_Console, &QPushButton::clicked, this, &MainWindow::Clear_Console);
    connect(ui->Copy_Console, &QPushButton::clicked, this, &MainWindow::Copy_Console);
    connect(ui->Calibration, &QPushButton::clicked, this, &MainWindow::Calibration);
    connect(ui->On_Conn, &QPushButton::clicked, this, &MainWindow::On_Conn);
    connect(ui->Off_Conn, &QPushButton::clicked, this, &MainWindow::Off_Conn);

    // Configuration de la liste des vitesses de transmission
    QStringList baudRates = {"9600", "19200", "38400", "57600", "115200", "230400", "256000"};
    ui->Vitesse_Transmission->addItems(baudRates);

    // Configuration de la liste des ports série disponibles
    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : availablePorts) {
        ui->Port_serie->addItem(portInfo.portName());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Vitesse_Transmission(const QString &arg1)
{
    QString selectedBaudRate = arg1;
    // Vous pouvez ajouter le traitement ici
}

void MainWindow::Port_serie(const QString &arg1)
{
    QString selectedPortName = arg1;
    // Vous pouvez ajouter le traitement ici
}

void MainWindow::Clear_Console()
{
    ui->Terminal->clear();
}

void MainWindow::Copy_Console()
{
    ui->Terminal->selectAll();
    ui->Terminal->copy();
}

void MainWindow::Calibration()
{
    // Vous pouvez ajouter le traitement ici
}

void MainWindow::On_Conn()
{
    QString selectedPortName = ui->Port_serie->currentText();
    // Vous pouvez ajouter le traitement ici pour établir la connexion
}

void MainWindow::Off_Conn()
{
    // Vous pouvez ajouter le traitement ici pour fermer la connexion
}
