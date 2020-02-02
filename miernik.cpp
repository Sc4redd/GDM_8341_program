#include "miernik.h"
#include "ui_miernik.h"
#include "mainwindow.h"



miernik::miernik(QWidget *parent, polaczenie *Polaczeniee) :
    QDialog(parent),
    ui(new Ui::miernik)
{
    ui->setupUi(this);
    Polaczenie = Polaczeniee;
    timers();

    pytanie = "*IDN?\n";

    connect(Polaczenie->serial,SIGNAL(readyRead()),this,SLOT(SerialRecived()));
    connect(timer_refresh,SIGNAL(timeout()),this,SLOT(wyslijOdpytanie()));
    connect(timer_meas,SIGNAL(timeout()),this,SLOT(on_pushButton_ZAPISZ_POMIAR_clicked()));

    buduj_tabele();
}

void miernik::timers(){
    timer_refresh = new QTimer(this);
    timer_refresh->setInterval(100);
    timer_refresh->start();

    timer_meas = new QTimer(this);
    timer_meas->setInterval(100);

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

void miernik::on_pushButton_ZAPISZ_POMIAR_clicked()
{

    ui->table_wid_wyniki->insertRow( ui->table_wid_wyniki->rowCount() );
    ui->table_wid_wyniki->setItem( 0, wiersz_tabeli, new QTableWidgetItem(ui->label_wyswietlacz->text()));
    wiersz_tabeli++;



}

void miernik::buduj_tabele(){
        ui->table_wid_wyniki->setColumnCount(1);
}

void miernik::on_text_czestotliowsc_pomiaru_textChanged() // do poprawy
{

        if( ui->text_czestotliowsc_pomiaru->toPlainText().toInt() < 1){
            ui->text_czestotliowsc_pomiaru->setText("1");
                timer_refresh->setInterval(1);
        }
        else{
                timer_refresh->setInterval(ui->text_czestotliowsc_pomiaru->toPlainText().toInt());
        }


}

void miernik::on_radio_pomiar_czasowy_clicked()
{
    if( ui->radio_pomiar_czasowy->isChecked() ){
        timer_meas->start();
    }else{
        timer_meas->stop();
    }
}

void miernik::on_pushButton_EKSPORT_CSV_clicked()
{
    csv = new ToCsv();
    csv->exportt(wiersz_tabeli,ui->table_wid_wyniki);
}
