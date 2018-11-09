#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opendb.h"
#include <QTableWidget>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createTable(QList<QStringList> list);
    void createLineChart();
    QList<QStringList> query(QString Database,QString Account,QString Pass,QString Fileds,QString QueryWhere,QString QueryOrder,QString QueryTable);

private:
    Ui::MainWindow *ui;
    openDB opendb;
    QuerySQL querySQL;

    void createView(QTableWidget *tableWidge,int row, int coulmn,QStringList headList_row,QList<QStringList> list);


};

#endif // MAINWINDOW_H
