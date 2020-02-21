#ifndef MIERNIK_H
#define MIERNIK_H

#include <QDialog>
#include <QTimer>
#include "polaczenie.h"
#include "tocsv.h"


namespace Ui {
class miernik;
}

class miernik : public QDialog
{
    Q_OBJECT

public:
    explicit miernik(QWidget *parent = nullptr,polaczenie *Polaczeniee = nullptr);
    ~miernik();
    polaczenie *Polaczenie;
    QTimer *timer_refresh;
    QTimer *timer_meas;
    QTimer *timer_odbioru;
    QString pytanie;


public slots:
    void SerialRecived();
    void wyslijOdpytanie();

private slots:

    void on_pushButton_VAC_clicked();

    void on_pushButton_VDC_clicked();

    void on_pushButton_A_clicked();

    void on_pushButton_OHM_clicked();

    void on_pushButton_DIODE_clicked();

    void on_pushButton_FREQ_clicked();

    void on_pushButton_ZAPISZ_POMIAR_clicked();

    void on_text_czestotliowsc_pomiaru_textChanged();

    void on_radio_pomiar_czasowy_clicked();

    void on_pushButton_EKSPORT_CSV_clicked();

    void on_pushButton_VACDC_clicked();

    void on_pushButton_A_AC_clicked();

    void on_pushButton_A_DC_clicked();

    void on_pushButton_CAPACITY_clicked();

    void on_pushButton_TEMP_clicked();

    void on_pushButton_PERIOD_clicked();

    void on_pushButton_CONTINUITY_clicked();

    void on_pushButton_clicked();

    void onTimerOdbioruTimeout();

private:
    Ui::miernik *ui;
    void buduj_tabele();
    void timers();
    int wiersz_tabeli = 0;
    ToCsv *csv;
    QByteArray odebraneDane;
    QByteArray Dane;

};

#endif // MIERNIK_H
