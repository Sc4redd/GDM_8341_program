#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    QString ba =ui->port_box->currentText();
    int bb = ui->bould_box->currentIndex();
    Polaczenie = new polaczenie(ba.toUtf8(),bb);


   hide();
   Miernik = new miernik(this, Polaczenie);
   Miernik->show();

}

