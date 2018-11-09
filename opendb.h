#ifndef OPENDB_H
#define OPENDB_H

#include <QtSql/QtSql>
#include "querysql.h"

class openDB
{
public:
    openDB();

    bool openDBbsd(QString Database,QString Account,QString Pass);

     QSqlDatabase  db;
     QuerySQL querySql;

};

#endif // OPENDB_H
