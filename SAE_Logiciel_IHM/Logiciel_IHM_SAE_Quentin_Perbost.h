#ifndef LOGICIEL_IHM_SAE_QUENTIN_PERBOST_H
#define LOGICIEL_IHM_SAE_QUENTIN_PERBOST_H

#include <QMainWindow>
#include "serialink.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:


private slots:
    void On_Conn();
    void Off_Conn();
    void Port_serie(const QString &arg1);
    void Vitesse_Transmission(const QString &arg1);
    void Lecture_Donnee();
    void Clear_Console();
    void Copy_Console();
    void Calibration();
    void On_LED();
    void Off_LED();
    void Chek_Tension();
    void Change_Unit(bool Valide);
    void Send_Temperature();
    void Temperature_selected();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    serialink *SAE;
    QSerialPort serialPort;
    bool connectionEstablished = false;
    double temperatureValue;

};

#endif // LOGICIEL_IHM_SAE_QUENTIN_PERBOST_H
