#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    view = new QTableView;
//    model = new QSqlTableModel;
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete view;

    opendb.db.close();
}


 QList<QStringList> MainWindow::query(QString Database,QString Account,QString Pass,QString Fileds,QString QueryWhere,QString QueryOrder,QString QueryTable)
{

    QList<QStringList> qlist;

    qlist.clear();
    QString qsql = querySQL.getSQL(Fileds,QueryWhere,QueryOrder,QueryTable);
    qDebug()<<qsql<<"\n";
    if(opendb.openDBbsd(Database,Account,Pass))
    {
        QSqlQuery que;
        bool success = que.exec(qsql);
        if(!success)
        {
            printf("query to server fa\n");
        }
        while (que.next())
        {
            QStringList list;
             list.clear();
            QSqlRecord rec = que.record(); //

            for(int i=0;i<rec.count();++i)//将每行的每一列结果得出来
            {
                //list.append();
                 list.append(que.value(i).toString());
               qDebug() << que.value(i).toString()<<"\n";
            }
            qlist.append(list);
        }
    }

    return qlist;

}

void MainWindow::createTable(QList<QStringList> list)
{
    QStringList headerList;
    headerList <<"ID"<<"EquipID"<<"Equipment"<<"TagName"<<"TagValue"<<"DateTime";
    createView(ui->tableWidget,list.size(),headerList.size(),headerList,list);
}


void MainWindow::createView(QTableWidget *tableWidge, int row, int coulmn,QStringList headList_row, QList<QStringList> list)
{

    tableWidge->setColumnCount(coulmn);
    tableWidge->setRowCount(row);
    tableWidge->setHorizontalHeaderLabels(headList_row);
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<coulmn;j++)
        {
            QTableWidgetItem *itemID = new QTableWidgetItem();
            itemID->setBackground(QColor(232,232,232));
            itemID->setText(list[i][j]);
            tableWidge->setItem(i,j,itemID);
        }
    }
}

void MainWindow::createLineChart()
{




}

