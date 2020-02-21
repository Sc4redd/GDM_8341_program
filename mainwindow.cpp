#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>


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
    Polaczenie = new polaczenie(ui->port_box->currentText().toUtf8(),ui->bould_box->currentIndex());

    if(Polaczenie->polaczono){
        hide();
        Miernik = new miernik(this, Polaczenie);
        Miernik->show();
    }
    else{
        Polaczenie = nullptr;
        QMessageBox msgBox;
        msgBox.setText("Nie można połączyć się z portem");
        msgBox.exec();
    }
}

