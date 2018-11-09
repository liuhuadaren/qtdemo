#include "opendb.h"

openDB::openDB()
{

}

bool openDB::openDBbsd(QString Database,QString Account,QString Pass)
{
    db = QSqlDatabase::addDatabase("QODBC");
    qDebug()<<"ODBC driver?"<<db.isValid();

//    db.setDatabaseName("SQLDrive");             //设置数据源名称
//    db.setUserName("sa");                               //登录用户
//    db.setPassword("123");
    db.setDatabaseName(Database);             //设置数据源名称
    db.setUserName(Account);                               //登录用户
    db.setPassword(Pass);
    if(!db.open())
    {
        return false;
    }
    return true;
}
