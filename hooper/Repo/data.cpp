#include <iostream>
#include "data.h"

using namespace std;

data::data(){

}

void data::initialize(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString database = "hooper.sqlite";

    db.setDatabaseName(database);
    bool db_ok = db.open();
    if(db_ok) {
        //cout << "Connection established" << endl;
    } else {
        cout << "Connection failed" << endl;
    }
}

//get all connections from database
vector<connection> data::getConnections(){
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

//sorting connections from database and returning query result to datalayer
vector<connection> data::getConnectionsSorted(int sort, int column){

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

vector<person> data::queryPerson(QString sqlQuery) {

    vector<person> persons;
    db.open();

    if (!db.isOpen())
    {
        return persons;
    }

    QSqlQuery query(db);
    if(!query.exec(sqlQuery)){
        return persons;
    }
        //qDebug() << query.executedQuery() << endl;
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

vector<computer> data::queryComputer(QString sqlQuery) {

    vector<computer> computers;
    db.open();

    if (!db.isOpen())
    {
        return computers;
    }

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

vector<connection> data::queryConnection(QString sqlQuery)
{
    vector<connection> connections;
    db.open();

    if(!db.isOpen()) {
        return connections;
    }

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

vector<computer> data::getComputers(){

    QString query("SELECT ID, name, type, yearMade, wasMade "
                     "FROM computers "
                     "WHERE Deleted = 'NO'");
    return queryComputer(query);

}

vector<computer> data::getComputersSorted(int sort, int column){

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
    query << "WHERE "<< field << " LIKE '%" << obj <<"%' ";
    query << "AND P.Deleted = 'NO' ";
    query << "ORDER BY P.lastname ASC";

    return  queryPerson(QString::fromStdString(query.str()));
}

vector<computer> data::searchComputer(string field, string obj){

    stringstream query;

    query << "SELECT C.ID, C.name, C.type, C.yearMade, C.wasMade ";
    query << "FROM computers C ";
    query << "WHERE "<< field << " LIKE '%" << obj <<"%' ";
    query << "AND C.Deleted = 'NO' ";
    query << "ORDER BY C.name ASC";

    return queryComputer(QString::fromStdString(query.str()));
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