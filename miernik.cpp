#include "miernik.h"
#include "ui_miernik.h"
#include "mainwindow.h"



miernik::miernik(QWidget *parent, polaczenie *Polaczeniee) :
    QDialog(parent),
    ui(new Ui::miernik)
{
    ui->setupUi(this);
    Polaczenie = Polaczeniee;
    timer = new QTimer(this);
    timer->setInterval(100);
    timer->start();
    pytanie = "*IDN?\n";

    connect(Polaczenie->serial,SIGNAL(readyRead()),this,SLOT(SerialRecived()));
    connect(timer,SIGNAL(timeout()),this,SLOT(wyslijOdpytanie()));
}

void miernik::SerialRecived()
{
    QByteArray ba;
    ba = Polaczenie->serial->readAll();
    ui->label_wyswietlacz->setText(ba);

}

void miernik::wyslijOdpytanie()
{
   Polaczenie->WriteData(pytanie.toUtf8());

}

miernik::~miernik()
{

    delete ui;
}



void miernik::on_pushButton_VAC_clicked()
{
    pytanie = "MEAS:VOLT:AC?\n";
}

void miernik::on_pushButton_VDC_clicked()
{
    pytanie = "MEAS:VOLT:DC?\n";
}

void miernik::on_pushButton_A_clicked()
{
     Polaczenie->WriteData("xxx");
}

void miernik::on_pushButton_OHM_clicked()
{
    pytanie = "MEAS:RES?\n";
}

void miernik::on_pushButton_DIODE_clicked()
{
     Polaczenie->WriteData("xxx");
}

void miernik::on_pushButton_FREQ_clicked()
{
    pytanie = "MEAS:FREQ?\n";
}
