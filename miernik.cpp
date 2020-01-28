#include "miernik.h"
#include "ui_miernik.h"
#include "mainwindow.h"



miernik::miernik(QWidget *parent, polaczenie *Polaczeniee) :
    QDialog(parent),
    ui(new Ui::miernik)
{
    ui->setupUi(this);
    Polaczenie = Polaczeniee;


    connect(Polaczenie->serial,SIGNAL(readyRead()),this,SLOT(SerialRecived()));
}

void miernik::SerialRecived()
{
    QByteArray ba;
    ba = Polaczenie->serial->readAll();
    ui->label_wyswietlacz->setText(ba);

}

miernik::~miernik()
{

    delete ui;
}



void miernik::on_pushButton_VAC_clicked()
{
    Polaczenie->WriteData("xxx");
}

void miernik::on_pushButton_VDC_clicked()
{
      Polaczenie->WriteData("MEAS:VOLT:DC?\n");
}

void miernik::on_pushButton_A_clicked()
{
     Polaczenie->WriteData("xxx");
}

void miernik::on_pushButton_OHM_clicked()
{
     Polaczenie->WriteData("xxx");
}

void miernik::on_pushButton_DIODE_clicked()
{
     Polaczenie->WriteData("xxx");
}
