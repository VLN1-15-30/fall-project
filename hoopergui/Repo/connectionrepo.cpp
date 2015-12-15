#include "connectionrepo.h"
#include "Utilities/utils.h"

connectionRepo::connectionRepo()
{
    //utils::getDatabaseConnection();
}

bool connectionRepo::addNewConnection(int pid, int cid) {
    QSqlQuery q;
    QString query = "INSERT INTO invented VALUES(?, ?, 'NO')";
    if(q.prepare(query)) {
        q.addBindValue(pid);
        q.addBindValue(cid);
        return q.exec();
    } else {
        qDebug() << q.lastError() << endl;
        return false;
    }
}

void connectionRepo::updateConnection(int personID, int computerID, string fieldName, int newID){
    QSqlQuery q;
    QString query("UPDATE invented SET %1 = %2 "
                  "WHERE pID = %3 "
                  "AND cID = %4 ");
    if(q.prepare(query.arg(fieldName.c_str()).arg(newID).arg(personID).arg(computerID))) {
        q.exec();
        return;
    } else {

    }
}

int connectionRepo::removeConnectionByID(int pid, int cid){

    QSqlQuery q;
    QString query("UPDATE invented SET deleted = 'YES' "
                  "WHERE pid = %1 AND cid = %2" );
    if(q.prepare(query.arg(pid).arg(cid))){
        q.exec();
        return 1;
    }
    else{
        qDebug() << q.lastError() << endl;
        return 0;
     }
}

vector<connection> connectionRepo::getConnections(){
    QSqlQuery q;
    QString query("SELECT P.firstname, P.lastname, C.name, C.yearMade "
                   "FROM invented I "
                   "    INNER JOIN persons P ON P.id = I.pID "
                   "    INNER JOIN computers C ON C.id = I.cID "
                   "WHERE I.Deleted = 'NO' "
                   "AND P.Deleted = 'NO' "
                   "AND C.Deleted = 'NO' ");
    return queryConnection(query);
}

vector<connection> connectionRepo::getConnectionsSorted(int sort, int column){

    string orderby;
    string col;

    if(column == 0){
        col = "P.lastname";
    }
    else if(column == 1){
        col = "C.name";
    }
    else{
        col = "C.yearMade";
    }

    if( sort == 0){
        orderby = "ASC";
    }
    else{
        orderby = "DESC";
    }

    stringstream query;
    query << "SELECT P.firstname, P.lastname, C.name, C.yearMade ";
    query << "FROM invented I ";
    query << "    INNER JOIN persons P ON P.id = I.pID ";
    query << "    INNER JOIN computers C ON C.id = I.cID ";
    query << "WHERE I.Deleted = 'NO' AND P.Deleted = 'NO' ";
    query << "AND C.Deleted = 'NO' ";
    query << "ORDER BY " << col << " " << orderby;

    return queryConnection(QString::fromStdString(query.str()));
}

connection connectionRepo::getRandomConnection()
{

    QSqlQuery q;

    stringstream querystring;
    querystring << "SELECT P.firstname, P.lastname, C.name, C.yearMade ";
    querystring << "FROM invented I ";
    querystring << "    INNER JOIN persons P ON P.id = I.pID ";
    querystring << "    INNER JOIN computers C ON C.id = I.cID ";
    querystring << "WHERE I.Deleted = 'NO' AND P.Deleted = 'NO' ";
    querystring << "AND C.Deleted = 'NO' ";
    querystring << "ORDER BY RANDOM() LIMIT 1";


    QString query(QString::fromStdString(querystring.str()));

    if(q.exec(query)){
        q.first();

        string firstName = q.value(0).toString().toStdString();
        string lastName = q.value(1).toString().toStdString();
        string computer = q.value(2).toString().toStdString();
        int yearmade = q.value(3).toInt();

        return connection(firstName,lastName,computer,yearmade);

    } else {
        qDebug() << q.lastError() << endl;
        return connection();
    }
}

vector<connection> connectionRepo::searchConnection(string field, string obj)
{
    stringstream query;

    query << "SELECT P.firstname, P.lastname, C.name, C.yearMade ";
    query << "FROM invented I ";
    query << "    INNER JOIN persons P ON P.id = I.pID ";
    query << "    INNER JOIN computers C ON C.id = I.cID ";
    query << "WHERE "<< field << " LIKE '%" << obj <<"%' ";
    query << "AND I.Deleted = 'NO' AND P.Deleted = 'NO' ";
    query << "AND C.Deleted = 'NO' ";
    query << "ORDER BY C.name ASC";

    return queryConnection(QString::fromStdString(query.str()));
}

vector<connection> connectionRepo::queryConnection(QString sqlQuery){

    vector<connection> connections;
//    db.open();

//    if(!db.isOpen()) {
//        return connections;
//    }

    QSqlQuery query(db);
    if(!query.exec(sqlQuery)) {
       // qDebug() << query.executedQuery() << endl;
        return connections;
    }
    //qDebug() << query.executedQuery() << endl;

    while(query.next()) {
        string firstName = query.value(0).toString().toStdString();
        string lastName = query.value(1).toString().toStdString();
        string computerName = query.value(2).toString().toStdString();
        int yearInvented = query.value(3).toUInt();

        connections.push_back(connection(firstName, lastName, computerName, yearInvented));
    }

    return connections;
}



