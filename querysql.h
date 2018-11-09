#ifndef QUERYSQL_H
#define QUERYSQL_H
#include <QObject>

class QuerySQL
{
public:
    QuerySQL();
    QString getSQL(QString Fields,QString QueryWhere, QString QueryOrder,QString QueryTable);

    QString getDatasources(QString Datasources);
    QString getAccount(QString Account);
    QString getPassword(QString Password);

};

#endif // QUERYSQL_H
