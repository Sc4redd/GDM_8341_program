#ifndef MIERNIK_H
#define MIERNIK_H

#include <QDialog>
#include <QTimer>
#include "polaczenie.h"


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
    QTimer *timer;
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

private:
    Ui::miernik *ui;

};

#endif // MIERNIK_H
