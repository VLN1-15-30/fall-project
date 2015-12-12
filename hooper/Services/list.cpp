#include <iostream>
#include "list.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>


using namespace std;

List::List(){
}



//return unordered computer table
vector<computer> List:: getComputers(){
    return computerR.getComputers();
}

//returns unordered connections table
vector<connection> List::getConnections() {
    return connectionR.getConnections();
}

//returns unordered person table
vector<person> List:: getPersons(){
    return personR.getPersons();
}

bool List::addPerson(person p){

    //initializing variables from user input
    string firstname = p.getFirstName();
    string lastname = p.getLastName();
    string sex = p.getSex();
    int born = p.getBorn();
    int died = p.getDied();

    //Calling data layer to add to database, returns false if unsuccessful
    bool add = personR.addNewPerson(firstname, lastname, sex, born, died);
    if(add) {
        return true;
    } else {
        return false;
    }
}

bool List::addComp(computer c){

    //initializing variables from user input
    string name = c.getName();
    string type = c.getType();
    int year = c.getYearMade();
    bool made = c.getWasMade();

    //Calling datalayer to add to database, returns false if unsuccessful
    bool add = computerR.addNewComputer(name, type, year, made);
    if(add) {
        return true;
    } else {
        return false;
    }
}


bool List::addConnection(string firstName, string lastName, string computerName){

   int personID = personR.getPersonID(lastName.c_str(), firstName.c_str());
   if( personID == -1 || personID == 0) {
       return false;
   }

   int computerID = computerR.getComputerByID(computerName.c_str());
   if( computerID == -1 || computerID == 0) {
       return false;
   }

   bool add = connectionR.addNewConnection(personID, computerID);
   if(add) {
       return  true;
   } else {
       return false;
   }
}

void List::printList(QSqlQuery q){

    int idCount = 0;
    while (q.next()){

        int ID = ++idCount;
        string first = q.value(1).toString().toStdString();
        string last = q.value(2).toString().toStdString();
        string sex = q.value(3).toString().toStdString();
        int born = q.value(4).toUInt();
        int died = q.value(5).toUInt();

        cout << "ID: " << ID << endl;
        cout << "First name: " << first << endl;
        cout << "Last name: " << last << endl;
        cout << "Sex: " << sex << endl;
        cout << "Born: " << born << endl;
        if(died != 0)
            cout << "Died: " << died << endl;
          else
              cout << "-";
          cout << endl << endl;
    }
}

void List::printComputerList(QSqlQuery q){

    int idCount = 0;
    while (q.next()){

        int ID = ++idCount;
        string name = q.value(1).toString().toStdString();
        string type = q.value(2).toString().toStdString();
        int year = q.value(3).toUInt();
        bool made = q.value(4).toBool();

        cout << "ID: " << ID << endl;
        cout << "Computer name: " << name << endl;
        cout << "Computer type: " << type << endl;
        cout << "Year made: " << year << endl;
        if(made == true)
            cout << "Was it made: Yes " << endl;
          else
              cout << "Was it made: No ";
          cout << endl << endl;
    }


}

void List::printConnectionsList(QSqlQuery q){

    while(q.next()){
        string lastName = q.value(0).toString().toStdString();
        string computerName = q.value(1).toString().toStdString();
        int yearMade = q.value(2).toUInt();

        cout << "Computer name: " << computerName << endl;
        cout << "Pioneers last name: " << lastName << endl;
        cout << "Year computer made: " << yearMade << endl;
        cout << endl;
    }
}

bool List:: computersDatabaseEmpty(){

    int count = countDatabase(1);

    if(count == 0){
        cout << "Database empty - start by adding a computer."<< endl;
        return true;
    }

    return false;
}

bool List::databaseEmpty() {


   int count = countDatabase(0);

    if(count == 0){
        cout << "Database empty - start by adding a pioneer."<< endl;
        return true;
    }

    return false;
}

vector<computer> List::orderbyComputers(int sort, int column){

    return computerR.getComputersSorted(sort, column);
}

vector<connection> List::orderbyConnections(int sort, int column){

    return connectionR.getConnectionsSorted(sort, column);
}

vector<person> List::orderbyPersons(int sort, int column){

    return personR.getPersonsSorted(sort, column);
}


char List:: ask_again(){

    char answer;
    cout << "Add another? (y/n)"<< endl;
    cin >> answer;

    return answer;
}


vector<person> List::getSearchPerson(string column, string target){

    return personR.searchPerson(column, target);
}

vector<computer> List::getSearchComputer(string column, string target){
    return computerR.searchComputer(column, target);
}

ostream& operator<< (ostream& stream,const List& p){

   for (unsigned int i = 0; i< p.characters.size(); i++) {
       person pers = p.characters[i];
       stream << pers;
       cout << "-----------------" << endl;
   }
   stream << endl;
   return stream;
}

int List:: countDatabase(int type){

    int result = utils::countDatabaseInput(type);
    return result;

}

person List:: discoverPerson(){
    return personR.getRandomPerson();
}

computer List::discoverComputer(){
    return computerR.getRandomComputer();
}

person List::returnNewPersonWith(string firstname,string lastname, string sex, int born, int died){

    person p;
    p.setFirstName(firstname);
    p.setLastName(lastname);
    p.setSex(sex);
    p.setBorn(born);
    p.setDied(died);

    return p;
}

computer List:: returnNewComputer(string name, string type, int year, bool made){
    computer c;
    c.setName(name);
    c.setType(type);
    c.setYearMade(year);
    c.setWasMade(made);

    return c;

}


void List:: deleteCharacterWithName(string lastname, int type){

    utils::deleteObj(type,lastname);

}

void List::closeDatabase() {
    utils::closeDBConnection();
}

void List::update(int identiy,string fieldName, string value, string tableName){
    utils::update(identiy,fieldName,value,tableName);
}


void List::updateConnection(int personID, int computerID, string fieldName, int newID){

    connectionR.updateConnection(personID, computerID, fieldName, newID);
}


int List::getPersonID(string lastName, string firstName) {
    int personID = personR.getPersonID(lastName.c_str(), firstName.c_str());

    if( personID == -1 || personID == 0) {
        return -1;
    }
    return personID;
}

//Use computername to get ID of cpu
int List::getComputerID(string computerName){

    int computerID = computerR.getComputerByID(computerName.c_str());
    if( computerID == -1 || computerID == 0) {
        return -1;
    }
    return computerID;
}

void List::removeConnection(string firstName, string lastName, string computerName) {

    int personID = personR.getPersonID(lastName.c_str(), firstName.c_str());

    if( personID == -1 || personID == 0) {
        cout << "Person not in database" << endl;
        return;
    }

    int computerID = computerR.getComputerByID(computerName.c_str());
    if( computerID == -1 || computerID == 0) {
        cout << "Computer not in database" << endl;
        return;
    }

    bool remove = connectionR.removeConnectionByID(personID, computerID);
    if(remove) {
        cout << "Succesfully removed connection" << endl;
    } else {
        cout << "ID's are not valid" << endl;
    }
}
