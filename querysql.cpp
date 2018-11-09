#include "querysql.h"

QuerySQL::QuerySQL()
{

}

QString QuerySQL::getSQL(QString Fields,QString QueryWhere, QString QueryOrder,QString QueryTable)
{
    if(QueryOrder == "" && QueryWhere  == "")
    {
        return "select "+ Fields + " from " + QueryTable; /*+ "  where  " +QueryWhere ;*/
    }
    if (QueryOrder == "" && QueryWhere != "")
    {
          return "select "+ Fields + " from " + QueryTable + "  where  " +QueryWhere ;
    }
    if (QueryOrder != "" && QueryWhere  == "")
    {
          return "select "+ Fields + " from " + QueryTable + "  order by " +QueryOrder ;
    }
    if (QueryOrder != "" && QueryWhere  != "")
    {
          return "select "+ Fields + " from " + QueryTable + "  where  " +QueryWhere + "  order by " +QueryOrder ;
    }
}
QString QuerySQL::getDatasources(QString DataSources)
{
   // this->DataSources = DataSources;
    return DataSources;
}

QString QuerySQL::getAccount(QString Account)
{
    //this->Account = Account;
    return Account;
}
QString QuerySQL::getPassword(QString Password)
{
   // this->Password = Password;
    return Password;
}

