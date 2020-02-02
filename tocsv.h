#ifndef TOCSV_H
#define TOCSV_H

#include <QTextStream>
#include <QTableWidget>

class ToCsv
{
public:
    ToCsv();
    void exportt(int wiersze, QTableWidget *tabela);

};

#endif // TOCSV_H
