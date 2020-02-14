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
    timer_refresh->setInterval(3000);
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

   Polaczenie->WriteData("VAL1?\n");

}

miernik::~miernik()
{
    delete ui;
}



void miernik::on_pushButton_VAC_clicked()
{
   // pytanie = "CONF:VOLT:AC\n"; //+ mozna dodac zakresy
    Polaczenie->WriteData("MEAS:VOLT:AC?\n");
   // pytanie = "MEAS:VOLT:AC?\n";
    //VAL1? ->zwraca wartosc wyswietlacza
    //SYSTem:REMote -> sterowanie zdalne aby powrocic 2nd button or local button
    //SYSTem:RWLock inny powrót
    //*CLS czysci error
}

void miernik::on_pushButton_VDC_clicked()
{
   // pytanie = "CONF:VOLT:DC\n";
   // pytanie = "MEAS:VOLT:DC?\n";
    Polaczenie->WriteData("MEAS:VOLT:DC?\n");
}

void miernik::on_pushButton_VACDC_clicked()
{
    //pytanie = "CONF:VOLT:DCAC\n";
    //pytanie = "MEAS:VOLT:DCAC?";
    Polaczenie->WriteData("MEAS:VOLT:DCAC?\n");
}

void miernik::on_pushButton_A_clicked()
{
    //pytanie = "CONF:CURR:DCAC\n";
    //pytanie = "MEAS:CURR:DCAC?";
    Polaczenie->WriteData("MEAS:CURR:DCAC?\n");
}

void miernik::on_pushButton_A_AC_clicked()
{
    //pytanie = "CONF:CURR:AC\n";
    //pytanie = "MEAS:CURR:AC?";
    Polaczenie->WriteData("MEAS:CURR:AC?\n");
}

void miernik::on_pushButton_A_DC_clicked()
{
    //pytanie = "CONF:CURR:DC\n";
    //pytanie = "MEAS:CURR:DC?\n";
    Polaczenie->WriteData("MEAS:CURR:DC?\n");
}

void miernik::on_pushButton_OHM_clicked()
{
    //pytanie = "CONF:RES\n";
    //pytanie = "MEAS:RES?\n";
     Polaczenie->WriteData("MEAS:RES?\n");
}

void miernik::on_pushButton_DIODE_clicked()
{
    //pytanie = "CONF:DIOD\n";
    //pytanie = "MEAS:DIOD?\n";
    Polaczenie->WriteData("MEAS:DIOD?\n");
}

void miernik::on_pushButton_FREQ_clicked()
{
    //pytanie = "MEAS:FREQ\n";
    //pytanie = "MEAS:FREQ?\n";
    Polaczenie->WriteData("MEAS:FREQ?\n");
}

void miernik::on_pushButton_CAPACITY_clicked()
{
    //pytanie = "CONF:CAP\n";
    //pytanie = "MEAS:CAP?\n";
    Polaczenie->WriteData("MEAS:CAP?\n");
}

void miernik::on_pushButton_TEMP_clicked()
{
    //pytanie = "CONF:TEMP:TCO T\n";
    //pytanie = "MEAS:TEMP?\n";
    Polaczenie->WriteData("MEAS:TEMP?\n");
}

void miernik::on_pushButton_PERIOD_clicked()
{
    //pytanie = "CONF:PER\n";
    //pytanie = "MEAS:PER?";
    Polaczenie->WriteData("MEAS:PER?\n");
}

void miernik::on_pushButton_CONTINUITY_clicked()
{
    //pytanie = "CONF:CONT\n";
    //pytanie = "MEAS:CONT?\n";
    Polaczenie->WriteData("MEAS:CONT?\n");
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
                timer_meas->setInterval(1);
        }
        else{
                timer_meas->setInterval(ui->text_czestotliowsc_pomiaru->toPlainText().toInt());
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














