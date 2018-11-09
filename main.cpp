#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    QString Account = "sa";
    QString Password = "123";
    QString DataSources = "SQLDrive";
    QString Fileds = " TOP  100  * ";
    QString QueryWhere1 = " (DateTime >=' 2018-10-12 00:00:00' and DateTime <= '2018-10-13 00:00:00') and (EquipID = 12 or EquipID = 8 or EquipID = 7) ";
    //QString QueryWhere2 = " (EquipID = 12 or EquipID = 8 or EquipID = 7) ";
    QString QueryOrder = " DateTime desc";
    QString QueryTable = "[FMCSDataBase].[dbo].[temm]";

    QList<QStringList> list = m.query(DataSources,Account,Password,Fileds,QueryWhere1,QueryOrder,QueryTable);
    m.createTable(list);






    m.show();

    return a.exec();
}
