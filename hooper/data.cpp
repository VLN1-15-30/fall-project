#include <iostream>
#include "data.h"

using namespace std;

data::data() {

}

void data::initialize() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString database = "C:\\hooper\\hooper.sqlite";
   // QString database = "hooper.sqlite";

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
                   "    INNER JOIN computers C ON C.id = I.cID");
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
    if(q.prepare(query.arg(lastName).arg(firstName))) {
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
    QString query("SELECT C.ID C.name, C.type, C.yearMade, C.wasMade "
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



