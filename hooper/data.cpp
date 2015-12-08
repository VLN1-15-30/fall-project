#include <iostream>
#include "data.h"

using namespace std;

data::data() {

}

void data::initialize() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString database = "C:\\hooper\\hooper.sqlite";
    //QString database = "hooper.sqlite";

    db.setDatabaseName(database);
    bool db_ok = db.open();
    if(db_ok) {
        cout << "Connection established" << endl;
    } else {
        cout << "Connection failed" << endl;
    }
}

//get all connections from database
QSqlQuery data::getConnections() {
    QSqlQuery q;
    QString query("SELECT P.lastname, C.name, C.yearMade "
                   "FROM invented I "
                   "    INNER JOIN persons P ON P.id = I.pID "
                   "    INNER JOIN computers C ON C.id = I.cID "
                   "WHERE I.Deleted = 'NO'");
    if(q.prepare(query)) {
        q.exec();
        return q;
        }
    else {
        qDebug() << q.lastError() << endl;
        return q;
    }
}

QSqlQuery data::getConnectionsSorted(int sort, int column) {
    QSqlQuery q;
    QString orderby;
    QString col;

    if(column == 0){
        col = "P.lastname";
    } else if(column == 1) {
        col = "C.name";
    } else {
        col = "C.yearMade";
    }

    if( sort == 0) {
       orderby = "ASC";
    } else {
       orderby = "DESC";
    }
    QString query("SELECT P.lastname, C.name, C.yearMade "
                   "FROM invented I "
                   "    INNER JOIN persons P ON P.id = I.pID "
                   "    INNER JOIN computers C ON C.id = I.cID "
                   "WHERE I.Deleted = 'NO' "
                   "ORDER BY %1 %2");
    if(q.prepare(query.arg(col).arg(orderby))) {
        q.exec();
        return q;
        }
    else {
        qDebug() << q.lastError() << endl;
        return q;
    }
}

int data::getPersonID(QString lastName, QString firstName) {
    QSqlQuery q;
    QString query("SELECT P.ID FROM persons P "
                  "WHERE P.lastname = '%1' "
                  "AND P.firstname = '%2' "
                  "AND P.Deleted = 'NO'");
    if(q.prepare(query.arg(lastName).arg(firstName)))
    {
       q.exec();
       q.first();
       return q.value(0).toInt();
    } else {
        return -1;
    }
}

int data::getComputerByID(QString computerName) {
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

bool data::addNewConnection(int pid, int cid) {
    QSqlQuery q;
    QString query = "INSERT INTO invented VALUES(?, ?)";
    if(q.prepare(query)) {
        q.addBindValue(pid);
        q.addBindValue(cid);
        return q.exec();
    } else {
        qDebug() << q.lastError() << endl;
        return false;
    }
}

void data::Update(int rowId, string fieldname, string value, string tableName){

    QSqlQuery query;
    QString s;

    s = ( "UPDATE '%1' SET '%2' = '%3' WHERE id = '%4'" );

    QString field = fieldname.c_str();
    QString table = tableName.c_str();
    QString change = value.c_str();

    query.exec(s.arg(table).arg(field).arg(change).arg(rowId));
    qDebug()<< query.executedQuery();


}

QSqlQuery data::getComputers(){

    QSqlQuery q;
    QString query = ("SELECT ID, name, type, yearMade, wasMade FROM computers");

    if(q.prepare(query)){
        q.exec();
        return q;
    }
    else{
        qDebug() << q.lastError() << endl;
        return q;
    }

}

QSqlQuery data::getComputersSorted(int sort, int column) {
    QSqlQuery q;
    QString orderby;
    QString col;

    if(column == 0){
        col = "C.name";
    }
    else if(column == 1){
        col = "C.type";
    }

    if( sort == 0) {
       orderby = "ASC";
    }
    else{
       orderby = "DESC";
    }
    QString query("SELECT C.ID, C.name, C.type, C.yearMade, C.wasMade "
                   "FROM computers C "
                   "ORDER BY %1 %2");
    if(q.prepare(query.arg(col).arg(orderby))) {
        q.exec();
        return q;
        }
    else {
        qDebug() << q.lastError() << endl;
        return q;
    }
}

QSqlQuery data::getPersons(){

    QSqlQuery q;
    QString query = ("SELECT ID, lastname, firstname, sex, born, died FROM persons ");

    if(q.prepare(query)){
        q.exec();
        return q;
    }
    else{
        qDebug() << q.lastError() << endl;
        return q;
    }

}

QSqlQuery data::getPersonsSorted(int sort, int column) {
    QSqlQuery q;
    QString orderby;
    QString col;

    if(column == 0){
        col = "P.lastname";
    }
    else if(column == 1){
        col = "P.born";
    }

    if( sort == 0) {
       orderby = "ASC";
    }
    else{
       orderby = "DESC";
    }
    QString query("SELECT P.ID, P.lastname, P.firstname, P.sex, P.born, P.died "
                   "FROM persons P "
                   "ORDER BY %1 %2");
    if(q.prepare(query.arg(col).arg(orderby))) {
        q.exec();
        return q;
        }
    else {
        qDebug() << q.lastError() << endl;
        return q;
    }
}

int data::removeConnectionByID(int pid, int cid) {
    QSqlQuery q;
    QString query("UPDATE invented SET deleted = 'YES' "
                  "WHERE pid = %1 AND cid = %2" );
    if(q.prepare(query.arg(pid).arg(cid))){
        q.exec();
        return 1;
     } else {
        qDebug() << q.lastError() << endl;
        return 0;
     }
}

