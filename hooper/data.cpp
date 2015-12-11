#include <iostream>
#include "data.h"

using namespace std;

data::data(){

}

void data::initialize(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString database = "C:\\hooper\\hooper.sqlite";
    //QString database = "hooper.sqlite";

    db.setDatabaseName(database);
    bool db_ok = db.open();
    if(db_ok) {
        //cout << "Connection established" << endl;
    } else {
        cout << "Connection failed" << endl;
    }
}

//get all connections from database
QSqlQuery data::getConnections(){
    QSqlQuery q;
    QString query("SELECT P.lastname, C.name, C.yearMade "
                   "FROM invented I "
                   "    INNER JOIN persons P ON P.id = I.pID "
                   "    INNER JOIN computers C ON C.id = I.cID "
                   "WHERE I.Deleted = 'NO' "
                   "AND P.Deleted = 'NO' "
                   "AND C.Deleted = 'NO' ");
    if(q.prepare(query)) {
        q.exec();
        return q;
        }
    else {
        qDebug() << q.lastError() << endl;
        return q;
    }
}

//sorting connections from database and returning query result to datalayer
QSqlQuery data::getConnectionsSorted(int sort, int column){

    QSqlQuery q;
    QString orderby;
    QString col;

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
    QString query("SELECT P.lastname, C.name, C.yearMade "
                   "FROM invented I "
                   "    INNER JOIN persons P ON P.id = I.pID "
                   "    INNER JOIN computers C ON C.id = I.cID "
                   "WHERE I.Deleted = 'NO' "
                   "AND P.Deleted = 'NO' "
                   "AND C.Deleted = 'NO'"
                   "ORDER BY %1 %2");
    if(q.prepare(query.arg(col).arg(orderby))){
        q.exec();
        return q;
        }
    else{
        qDebug() << q.lastError() << endl;
        return q;
    }
}

int data::getPersonID(QString lastName, QString firstName){
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

vector<person> data::queryPerson(QString sqlQuery)
{
    vector<person> persons;
    db.open();

    if (!db.isOpen())
    {
        return persons;
    }

    QSqlQuery query(db);
    if(!query.exec(sqlQuery)){
        qDebug() << query.executedQuery() << endl;
        return persons;
    }
    qDebug() << query.executedQuery() << endl;
    while(query.next())
    {
        int id = query.value(0).toUInt();
        string firstName = query.value(1).toString().toStdString();
        string lastName = query.value(2).toString().toStdString();
        string sex = query.value(3).toString().toStdString();
        int yearBorn = query.value(4).toInt();
        int yearDied = query.value(5).toInt();

        persons.push_back(person(firstName, lastName, sex, yearBorn, yearDied));
    }

    return persons;
}

int data::getComputerByID(QString computerName){
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

bool data::addNewPerson(string firstname, string lastname, string sex, int born, int died){

    QString qfirstname(firstname.c_str());
    QString qlastname(lastname.c_str());
    QString qsex(sex.c_str());

    QSqlQuery add;
    QString query;

    //Death year becomes NULL if person still alive
    if(died != 0) {
        query = ("INSERT INTO persons VALUES(NULL, ?, ?, ?, ?, ?, 'NO')");
        if(add.prepare(query)){
            add.addBindValue(qfirstname);
            add.addBindValue(qlastname);
            add.addBindValue(qsex);
            add.addBindValue(born);
            add.addBindValue(died);
            return add.exec();
        }
    }
    else if(died == 0){
        query = "INSERT INTO persons(ID, firstname, lastname, sex, born)" "VALUES(NULL, ?, ?, ?, ?)";
        if(add.prepare(query)) {
            add.addBindValue(qfirstname);
            add.addBindValue(qlastname);
            add.addBindValue(qsex);
            add.addBindValue(born);
            return add.exec();
        }
    }
    else {
        qDebug() << add.lastError() << endl;
            return false;
    }
    return false;
}

bool data::addNewComputer(string name, string type, int year, bool made){

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

bool data::addNewConnection(int pid, int cid){
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

void data::update(int rowId, string fieldname, string value, string tableName){

    QSqlQuery query;
    QString s;

    s = ( "UPDATE '%1' SET '%2' = '%3' WHERE id = '%4'" );

    QString field = fieldname.c_str();
    QString table = tableName.c_str();
    QString change = value.c_str();

    query.exec(s.arg(table).arg(field).arg(change).arg(rowId));
}

QSqlQuery data::getComputers(){

    QSqlQuery q;
    QString query = ("SELECT ID, name, type, yearMade, wasMade "
                     "FROM computers "
                     "WHERE Deleted = 'NO'");
    if(q.prepare(query)){
        q.exec();
        return q;
    }
    else{
        qDebug() << q.lastError() << endl;
        return q;
    }

}

QSqlQuery data::getComputersSorted(int sort, int column){
    QSqlQuery q;
    QString orderby;
    QString col;

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
    QString query("SELECT C.ID, C.name, C.type, C.yearMade, C.wasMade "
                   "FROM computers C "
                   "WHERE C.Deleted = 'NO' "
                   "ORDER BY %1 %2");
    if(q.prepare(query.arg(col).arg(orderby))){
        q.exec();
        return q;
        }
    else{
        qDebug() << q.lastError() << endl;
        return q;
    }
}

vector<person> data::getPersons(){

    QString query("SELECT ID, firstname, lastname, sex, born, died "
                  "FROM persons "
                  "WHERE Deleted = 'NO' ");
    return queryPerson(query);
}

vector<person> data::getPersonsSorted(int sort, int column){

    string orderby;
    string col;

    if(column == 0){
        col = "P.lastname";
    }
    else if(column == 1){
        col = "P.born";
    }

    if(sort == 0) {
        orderby = "ASC";
    }
    else{
        orderby = "DESC";
    }

    stringstream query;
    query << "SELECT P.ID, P.lastname, P.firstname, P.sex, P.born, P.died ";
    query << "FROM persons P ";
    query << "WHERE P.Deleted = 'NO' ";
    query << "ORDER BY " << col << " " << orderby;

    return queryPerson(QString::fromStdString(query.str()));
}

int data::removeConnectionByID(int pid, int cid){
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

vector<person> data::searchPerson(string field, string obj){

    stringstream query;

    query << "SELECT P.ID, P.firstname, P.lastname, P.sex, P.born, P.died ";
    query << "FROM persons P ";
    query << "WHERE "<< field << " LIKE '" << obj <<"' ";
    query << "AND P.Deleted = 'NO' ";
    query << "ORDER BY lastname ASC";

    return  queryPerson(QString::fromStdString(query.str()));
}

QSqlQuery data::searchComputer(string field, string obj){

    QSqlQuery query;
    QString s;
    s = ( "SELECT C.ID, C.name, C.type, C.yearMade, C.wasMade "
          "FROM computers C "
          "WHERE %1 LIKE '%%2%' "
          "AND C.Deleted = 'NO' "
          "ORDER BY name ASC" );

    QString val = obj.c_str();
    QString by = field.c_str();

    query.exec(s.arg(by).arg(val));

    return query;
}
int data::countDatabaseInput(int type){

    QSqlQuery query;
    QString s;
    if(type == 0){
        s = ("SELECT Count(*) FROM persons WHERE deleted = 'NO'");
    }
    else if (type == 1){
        s = ("SELECT Count(*) FROM computers WHERE deleted = 'NO'");
    }
    query.exec(s);
    query.first();

    return query.value(0).toInt();
}

void data::closeDBConnection() {
    db.close();
}

QSqlQuery data::getRandom(int type){
    QSqlQuery q;
    QString col;

    if(type == 0) {
        col = "persons";
    } else if(type == 1) {
        col = "computers";
    }
    QString query("SELECT * FROM %1 "
          "WHERE Deleted = 'NO' "
          "ORDER BY RANDOM() LIMIT 1");
    if(q.prepare(query.arg(col))) {
        q.exec();
        q.first();
        return q;
    } else {
        qDebug() << q.lastError() << endl;
        return q;
    }
}

void data:: deleteObj(int type, string name){

    QSqlQuery query;
    QString s;

    if(type == 0){

         s = ( "UPDATE persons SET deleted = 'YES' WHERE lastname = '%1'" );
         query.exec(s.arg(QString(name.c_str())));

    }
    else if (type == 1){

        s = ( "UPDATE computers SET deleted = 'YES' WHERE name = '%1'" );
        query.exec(s.arg(QString(name.c_str())));
    }
}

void data::updateConnection(int personID, int computerID, string fieldName, int newID){
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
