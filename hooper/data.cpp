#include "data.h"


data::data() {

}

void data::initialize() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    //QString database = "C:\\hooper\\hooper.sqlite";
    QString database = "hooper.sqlite";

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


