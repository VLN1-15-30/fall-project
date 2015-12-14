#include "personrepo.h"
#include "Utilities/utils.h"


personRepo::personRepo()
{
    //utils::getDatabaseConnection();
}

vector<person> personRepo::queryPerson(QString sqlQuery) {

    vector<person> persons;
//    db.open();

//    if (!db.isOpen())
//    {
//        return persons;
//    }

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

bool personRepo::addNewPerson(string firstname, string lastname, string sex, int born, int died){

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

int personRepo::getPersonID(QString lastName, QString firstName)
{
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

person personRepo::getRandomPerson(){
    QSqlQuery q;

    QString query("SELECT * FROM persons "
          "WHERE Deleted = 'NO' "
          "ORDER BY RANDOM() LIMIT 1");
    if(q.exec(query)){
        q.first();

        string firstName = q.value(1).toString().toStdString();
        string lastName = q.value(2).toString().toStdString();
        string sex = q.value(3).toString().toStdString();
        int yearBorn = q.value(4).toInt();
        int yearDied = q.value(5).toInt();

        return person(firstName, lastName, sex, yearBorn, yearDied);
    } else {
        qDebug() << q.lastError() << endl;
        return person();
    }
}

vector<person> personRepo::getPersons(){

    QString query("SELECT ID, firstname, lastname, sex, born, died "
                  "FROM persons "
                  "WHERE Deleted = 'NO' ");
    return queryPerson(query);
}

vector<person> personRepo::getPersonsSorted(int sort, int column){

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

vector<person> personRepo::searchPerson(string field, string obj){

    stringstream query;

    query << "SELECT P.ID, P.firstname, P.lastname, P.sex, P.born, P.died ";
    query << "FROM persons P ";
    query << "WHERE "<< field << " LIKE '%" << obj <<"%' ";
    query << "AND P.Deleted = 'NO' ";
    query << "ORDER BY P.lastname ASC";

    return  queryPerson(QString::fromStdString(query.str()));
}
