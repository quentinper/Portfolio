#include "Logiciel_IHM_SAE_Quentin_Perbost.h"
#include "serialink.h"
#include "ui_Logiciel_IHM_SAE_Quentin_Perbost.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QScrollBar>
#include <QLineEdit>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QByteArray buffer;
bool Valide = false;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SAE = new serialink;

    // Initialisation des listes déroulantes et des connexions
    QStringList baudRates;
    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

    for (const QSerialPortInfo &portInfo : availablePorts)
    {
        ui->Port_serie->addItem(portInfo.portName());
    }

    baudRates << "9600" << "19200" << "38400" << "57600" << "115200" << "230400" << "256000";
    ui->Vitesse_Transmission->addItems(baudRates);

    connect(ui->Vitesse_Transmission, &QComboBox::currentTextChanged, this, &MainWindow::Vitesse_Transmission);
    connect(ui->Port_serie, &QComboBox::currentTextChanged, this, &MainWindow::Port_serie);
    connect(ui->Clear_Console, &QPushButton::clicked, this, &MainWindow::Clear_Console);
    connect(ui->Copy_Console, &QPushButton::clicked, this, &MainWindow::Copy_Console);
    connect(ui->Calibration, &QPushButton::clicked, this, &MainWindow::Calibration);
    connect(ui->Off_Conn, &QPushButton::clicked, this, &MainWindow::Off_Conn);
    connect(ui->On_Conn, &QPushButton::clicked, this, &MainWindow::On_Conn);
    connect(ui->On_LED, &QPushButton::clicked, this, &MainWindow::On_LED);
    connect(ui->Off_LED, &QPushButton::clicked, this, &MainWindow::Off_LED);
    connect(ui->Chek_Tension, &QPushButton::clicked, this, &MainWindow::Chek_Tension);
    connect(SAE, &serialink::readyRead, this, &MainWindow::Lecture_Donnee);
    connect(ui->Change_Unit, &QPushButton::clicked, this, [this]() {
    Change_Unit(Valide);
    });
    connect(ui->Send_Temperature, &QPushButton::clicked, this, &MainWindow::Send_Temperature);
}



MainWindow::~MainWindow()
{
    delete ui;
}

// Ouvrir la connexion avec le port spécifié
void MainWindow::On_Conn()
{
    QString portName = ui->Port_serie->currentText();
    qint32 baudRate = ui->Vitesse_Transmission->currentText().toInt();
    SAE->openConnection(portName, baudRate);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::Off_Conn()
{
    if (SAE->isOpen()) {
        SAE->closeConnection();
        qDebug() << "Connexion série arrêtée.";
    } else {
        qDebug() << "Le port série n'est pas ouvert.";
    }

    if (!connectionEstablished) {
        qDebug() << "Veuillez d'abord établir une connexion en appuyant sur le bouton 'On_Conn'.";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::Port_serie(const QString &arg1)
{
    QString selectedPortName = arg1;

    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : availablePorts) {
        if (portInfo.portName() == selectedPortName) {
            qDebug() << "Port sélectionné : " << portInfo.portName();
            ui->Terminal->insertHtml(QString("Port sélectionné : %1<br>").arg(portInfo.portName()));
            qDebug() << "Fabricant : " << portInfo.manufacturer();
            ui->Terminal->insertHtml(QString("Fabricant : %1<br>").arg(portInfo.manufacturer()));
            qDebug() << "Description : " << portInfo.description();
            ui->Terminal->insertHtml(QString("Description : %1<br>").arg(portInfo.description()));
            return;
        }
    }

    if (!connectionEstablished) {
        qDebug() << "Veuillez d'abord établir une connexion en appuyant sur le bouton 'On_Conn'.";
    }

    qDebug() << "Port sélectionné non trouvé : " << selectedPortName;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::Vitesse_Transmission(const QString &arg1)
{
    QString selectedBaudRate = arg1;

    QHash<QString, qint32> baudRateMap;
    baudRateMap["9600"] = QSerialPort::Baud9600;
    baudRateMap["19200"] = QSerialPort::Baud19200;
    baudRateMap["38400"] = QSerialPort::Baud38400;
    baudRateMap["57600"] = QSerialPort::Baud57600;
    baudRateMap["115200"] = QSerialPort::Baud115200;

    if (baudRateMap.contains(selectedBaudRate)) {
        qint32 baudRate = baudRateMap.value(selectedBaudRate);
        qDebug() << "Vitesse de transmission en bauds sélectionnée :" << baudRate;
        ui->Terminal->insertHtml(QString("Vitesse de Transmission sélectionnée : %1<br>").arg(baudRate));
    } else {
        qDebug() << "Vitesse de transmission en bauds non valide :" << selectedBaudRate;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::Lecture_Donnee()
{
    // Assurez-vous que le port série est ouvert
    if (!SAE->isOpen()) {
        qDebug() << "Le port série n'est pas ouvert.";
        return;
    }

    // Lecture des données série
    QByteArray data = SAE->readAll();

    // Ajouter les données lues au buffer
    buffer.append(data);

    // Rechercher le caractère de fin de ligne "\n"
    int newlineIndex = buffer.indexOf('\n');

    // Tant qu'il y a des nouvelles lignes dans le buffer
    while (newlineIndex != -1) {
        // Extraire la ligne jusqu'au caractère de fin de ligne
        QByteArray message = buffer.left(newlineIndex + 1);

        // Convertir les données en une chaîne de caractères
        QString messageString = QString::fromUtf8(message);

        // Afficher le message dans le terminal
        ui->Terminal->insertPlainText(messageString);

        // Faire défiler automatiquement vers le bas
        ui->Terminal->verticalScrollBar()->setValue(ui->Terminal->verticalScrollBar()->maximum());

        // Supprimer la ligne traitée du tampon
        buffer.remove(0, newlineIndex + 1);

        // Trouver l'index de la prochaine fin de ligne
        newlineIndex = buffer.indexOf('\n');
        // Analyser les données JSON pour détecter le type de carte
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(message);
                if (jsonError.error == QJsonParseError::NoError && jsonDoc.isObject()) {
            QVariantMap dataMap = jsonDoc.object().toVariantMap();
            QString UnitType = dataMap["unit"].toString();
            if (dataMap.contains("board")) {
                QString boardType = dataMap["board"].toString();
                if (boardType == "Temperature") {
                    if (!ui->Carte_Detect->toPlainText().contains("Distance"))
                        ui->Carte_Detect->clear();
                    if (!ui->Carte_Detect->toPlainText().contains("Luminosite"))
                        ui->Carte_Detect->clear();
                    // Vérifier si "Temperature" n'a pas encore été inséré dans ui->Carte_Detect
                    if (!ui->Carte_Detect->toPlainText().contains("Temperature")) {
                        ui->Carte_Detect->insertPlainText("Temperature");
                    }
                    // Vérifier si l'unité est "Celsius"
                    if (UnitType == "Celsius")
                    {
                        // Effacer le contenu du widget si "Fahrenheit" n'est pas présent
                        /*
                        if(ui->Unit_Detect->toPlainText().contains("Lux"))
                            ui->Unit_Detect->clear();
                        if (!ui->Unit_Detect->toPlainText().contains("Centimetre"))
                            ui->Unit_Detect->clear();
                        */
                        if(ui->Unit_Detect->toPlainText().contains("Fahrenheit"))
                            ui->Unit_Detect->clear();
                        if (!ui->Unit_Detect->toPlainText().contains("Celsius"))
                            ui->Unit_Detect->insertPlainText("Celsius");

                    }
                    // Vérifier si l'unité est "Fahrenheit"
                    if (UnitType == "Fahrenheit")
                    {
                        if(ui->Unit_Detect->toPlainText().contains("Celsius"))
                            ui->Unit_Detect->clear();
                        if (!ui->Unit_Detect->toPlainText().contains("Fahrenheit"))
                            ui->Unit_Detect->insertPlainText("Fahrenheit");

                    }
                    if (dataMap.contains("Tension_Vcom"))
                    {
                        double Tension_Vcom = dataMap["Tension_Vcom"].toDouble();
                        ui->Vcom->display(Tension_Vcom);
                    }
                    if (dataMap.contains("Tension_Vs"))
                    {
                        double Tension_Vs = dataMap["Tension_Vs"].toDouble();
                        ui->Vs->display(Tension_Vs);
                    }
                    // Si la carte détectée est de type "Temperature", afficher dans le LCDNumber
                    if (dataMap.contains("value")) {
                        double temperatureValue = dataMap["value"].toDouble();
                        ui->Affichage_Donnee->display(temperatureValue);
                    } else {
                        qDebug() << "La clé 'value' est manquante dans les données JSON pour la carte Temperature.";
                    }
                } else if (boardType == "Luminosite") {
                    if (!ui->Carte_Detect->toPlainText().contains("Distance"))
                        ui->Carte_Detect->clear();
                    if (!ui->Carte_Detect->toPlainText().contains("Temperature"))
                        ui->Carte_Detect->clear();
                    if (!ui->Carte_Detect->toPlainText().contains("Luminosite")) {
                        ui->Carte_Detect->insertPlainText("Luminosite");
                    }
                    if (!ui->Unit_Detect->toPlainText().contains("Lux")) {
                        ui->Unit_Detect->insertPlainText("Lux");
                    }
                    // Si la carte détectée est de type "Luminosite", afficher dans le LCDNumber
                    if (dataMap.contains("value")) {
                        double luminositeValue = dataMap["value"].toDouble();
                        ui->Affichage_Donnee->display(luminositeValue);
                    } else {
                        qDebug() << "La clé 'value' est manquante dans les données JSON pour la carte Luminosite.";
                    }
                } else if (boardType == "Distance") {
                    if (!ui->Carte_Detect->toPlainText().contains("Luminosite"))
                        ui->Carte_Detect->clear();
                    if (!ui->Carte_Detect->toPlainText().contains("Temperature"))
                        ui->Carte_Detect->clear();
                    if (!ui->Carte_Detect->toPlainText().contains("Distance")) {
                        ui->Carte_Detect->insertPlainText("Distance");
                    }
                    if(ui->Unit_Detect->toPlainText().contains("Fahrenheit"))
                        ui->Unit_Detect->clear();
                    if(ui->Unit_Detect->toPlainText().contains("Lux"))
                        ui->Unit_Detect->clear();
                    if(ui->Unit_Detect->toPlainText().contains("Celsius"))
                        ui->Unit_Detect->clear();
                    if (!ui->Unit_Detect->toPlainText().contains("Centimetre")) {
                        ui->Unit_Detect->insertPlainText("Centimetre");
                    }
                    // Si la carte détectée est de type "Distance", afficher dans le LCDNumber
                    if (dataMap.contains("value")) {
                        double distanceValue = dataMap["value"].toDouble();
                        ui->Affichage_Donnee->display(distanceValue);
                    } else {
                        qDebug() << "La clé 'value' est manquante dans les données JSON pour la carte Distance.";
                    }
                } else {
                    // Autre type de carte détectée, afficher dans le terminal
                    qDebug() << "Carte détectée : " << boardType;
                }
            } else {
                qDebug() << "La clé 'board' est manquante dans les données JSON.";
            }
        } else {
            qDebug() << "Erreur lors de l'analyse des données JSON a la lecture :" << jsonError.errorString();
        }

        // Supprimer les données traitées du buffer
        buffer.remove(0, newlineIndex + 1);

        // Rechercher le prochain caractère de fin de ligne
        newlineIndex = buffer.indexOf('\n');
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::Clear_Console()
{
    ui->Terminal->clear();
}

void MainWindow::Copy_Console()
{
    // Sélectionner tout le texte dans le terminal
    ui->Terminal->selectAll();

    // Copier le texte sélectionné dans le presse-papiers
    ui->Terminal->copy();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::Calibration()
{

    if (SAE->isWritable())
    {
        SAE->write ("{ Cal:1}");
    }
    else qDebug()<<"impossible";
}

void MainWindow::On_LED()
{
    if (SAE->isWritable())
    {
        SAE->write ("{ led:1}");
    }
    else qDebug()<<"impossible";
}


void MainWindow::Off_LED()
{

    if (SAE->isWritable())
    {
        SAE->write ("{ led:0}");
    }
    else qDebug()<<"impossible";
}

void MainWindow::Chek_Tension()
{
    if (SAE ->isWritable()){
        SAE-> write ("{ Upd:1} ");
    }
    else
        qDebug()<<"impossible";
}

void MainWindow::Change_Unit(bool /*Valide*/) { // Nous n'utilisons pas Valide dans cette version
    static bool sendingSix = true; // Variable statique pour suivre l'état actuel (envoyer 6 ou 7)
    if (SAE->isWritable()) {
        SAE->write(sendingSix ? "{ Fah:1}" : "{ Fah:0}"); // Envoyer '6' si sendingSix est vrai, sinon envoyer '7'
        sendingSix = !sendingSix;        // Inverser l'état pour la prochaine fois
    } else {
        qDebug() << "Impossible d'écrire sur SAE";
    }
}

// Définir la fonction slot pour traiter les changements de texte dans Temperature_selected
void MainWindow::Temperature_selected()
{
    // Récupérer le texte actuel de la zone de texte Temperature_selected
    QString temperature = ui->Temperature_selected->toPlainText();

    // Afficher le texte dans le terminal
    ui->Terminal->insertPlainText(temperature);
}

void MainWindow::Send_Temperature() {
    // Récupérer le texte actuel de la zone de texte Temperature_selected
    QString temperature = ui->Temperature_selected->toPlainText();

    // Ajouter les accolades autour de la température
    QString message =  temperature;

    // Afficher le texte dans le terminal
    ui->Terminal->insertPlainText(message);

    // Effacer le contenu de la zone de texte Temperature_selected
    ui->Temperature_selected->clear();

    // Vérifier si SAE est prêt à écrire
    if (SAE->isWritable()) {
        // Envoyer la température via SAE
        SAE->write(message.toUtf8());
    } else {
        qDebug() << "Impossible d'écrire sur SAE";
    }
}

void MainWindow::on_pushButton_clicked()
{

}

