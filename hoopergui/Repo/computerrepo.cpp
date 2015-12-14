#include "computerrepo.h"
#include "Utilities/utils.h"

computerRepo::computerRepo()
{
   // utils::getDatabaseConnection();
}


bool computerRepo::addNewComputer(string name, string type, int year, bool made){

    QString qcname(name.c_str());
    QString qctype(type.c_str());

    QSqlQuery add;
    QString query;

    query = ("INSERT INTO computers VALUES(NULL, ?, ?, ?, ?, 'NO')");
    if(add.prepare(query)) {
        add.addBindValue(qcname);
        add.addBindValue(qctype);
        add.addBindValue(year);
        add.addBindValue(made);
        return add.exec();
    }
    else {
        qDebug() << add.lastError() << endl;
        return false;
    }
}

int computerRepo::getComputerByID(QString computerName){
    QSqlQuery q;
    QString query("SELECT C.ID FROM computers C "
                  "WHERE C.name = '%1' "
                  "AND C.Deleted = 'NO'");
    if(q.prepare(query.arg(computerName))) {
        q.exec();
        q.first();
        return q.value(0).toInt();
    } else {
        return -1;
    }
}

computer computerRepo::getRandomComputer(){
    QSqlQuery q;

    QString query("SELECT * FROM computers "
          "WHERE Deleted = 'NO' "
          "ORDER BY RANDOM() LIMIT 1");
    if(q.exec(query)){
        q.first();
        string name = q.value(1).toString().toStdString();
        string type = q.value(2).toString().toStdString();
        int year = q.value(3).toUInt();
        bool made = q.value(4).toBool();
        return computer(name,type,year,made);
    } else {
        qDebug() << q.lastError() << endl;
        return computer();
    }
}

vector<computer> computerRepo::getComputers(){

    QString query("SELECT ID, name, type, yearMade, wasMade "
                     "FROM computers "
                     "WHERE Deleted = 'NO'");
    return queryComputer(query);

}

vector<computer> computerRepo::getComputersSorted(int sort, int column){

    string orderby;
    string col;

    if(column == 0){
        col = "C.name";
    }
    else if(column == 1){
        col = "C.type";
    }
    if(sort == 0) {
        orderby = "ASC";
    }
    else{
        orderby = "DESC";
    }

    stringstream query;
    query << "SELECT C.ID, C.name, C.type, C.yearMade, C.wasMade ";
    query << "FROM computers C ";
    query << "WHERE C.Deleted = 'NO' ";
    query << "ORDER BY " << col << " " << orderby;

    return queryComputer(QString::fromStdString(query.str()));
}

vector<computer> computerRepo::queryComputer(QString sqlQuery) {

    vector<computer> computers;
//    db.open();

//    if (!db.isOpen())
//    {
//        return computers;
//    }

    QSqlQuery query(db);
    if(!query.exec(sqlQuery)){
        //qDebug() << query.executedQuery() << endl;
        return computers;
    }
        //qDebug() << query.executedQuery() << endl;
    while(query.next())
    {
        int id = query.value(0).toUInt();
        string name = query.value(1).toString().toStdString();
        string type = query.value(2).toString().toStdString();
        int yearMade = query.value(3).toInt();
        bool wasMade = query.value(4).toInt();

        computers.push_back(computer(name, type, yearMade, wasMade));
    }

    return computers;
}

vector<computer> computerRepo::searchComputer(string field, string obj){

    stringstream query;

    query << "SELECT C.ID, C.name, C.type, C.yearMade, C.wasMade ";
    query << "FROM computers C ";
    query << "WHERE "<< field << " LIKE '%" << obj <<"%' ";
    query << "AND C.Deleted = 'NO' ";
    query << "ORDER BY C.name ASC";

    return queryComputer(QString::fromStdString(query.str()));
}
