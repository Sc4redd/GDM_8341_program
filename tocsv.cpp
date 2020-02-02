#include "tocsv.h"
#include <QFile>



ToCsv::ToCsv()
{ 
}

void ToCsv::exportt(int wiersze, QTableWidget *tabela){

    QString filename = "Data.csv";
       QFile file(filename);
       if (file.open(QIODevice::ReadWrite)) {
           QTextStream stream(&file);
           for(int i=0;i<wiersze;i++)
           {
           stream << tabela->item(i,0)->text() << endl;
           }
       }

}

