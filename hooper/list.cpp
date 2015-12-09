#include <iostream>
#include "list.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>


using namespace std;

List::List(){
}

void List:: initialize(){

    db.initialize();
}

//return unordered computer table
QSqlQuery List:: getComputers(){
    return db.getComputers();
}

//returns unordered connections table
QSqlQuery List::getConnections() {
    return db.getConnections();
}

//returns unordered person table
QSqlQuery List:: getPersons(){
    return db.getPersons();
}

void List::addData(person p){

    //initializing variables from user input
    string firstname = p.getFirstName();
    string lastname = p.getLastName();
    string sex = p.getSex();
    int born = p.getBorn();
    int died = p.getDied();

    //Calling data layer to add to database, returns false if unsuccessful
    bool add = db.addNewPerson(firstname, lastname, sex, born, died);
    if(add) {
        cout << "Succesfully added new pioneer" << endl;
    } else {
        cout << "Error in adding a pioneer" << endl;
    }
}

void List::addComp(computer c){

    //initializing variables from user input
    string name = c.getName();
    string type = c.getType();
    int year = c.getYearMade();
    bool made = c.getWasMade();

    //Calling datalayer to add to database, returns false if unsuccessful
    bool add = db.addNewComputer(name, type, year, made);
    if(add) {
        cout << "Succesfully added new computer" << endl;
    } else {
        cout << "Error in adding a computer" << endl;
    }
}


void List::addConnection(string firstName, string lastName, string computerName){

   int personID = db.getPersonID(lastName.c_str(), firstName.c_str());

   if( personID == -1 || personID == 0) {
       cout << "Person not in database" << endl;
       return;
   }

   int computerID = db.getComputerByID(computerName.c_str());
   if( computerID == -1 || personID == 0) {
       cout << "Computer not in database" << endl;
       return;
   }

   bool add = db.addNewConnection(personID, computerID);
   if(add) {
       cout << "Succesfully added new connections" << endl;
   } else {
       cout << "ID's are not valid" << endl;
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

void List:: printComputerTable(QSqlQuery q){

    computerTableBegin();

    const char separator    = ' ';
    const int nameWidth     = 30;
    const int numWidth      = 10;

    int idCount = 0;
    while (q.next()){

        int ID = ++idCount;
        string name = q.value(1).toString().toStdString();
        string type = q.value(2).toString().toStdString();
        int year = q.value(3).toUInt();
        bool made = q.value(4).toBool();

          cout << left << setw(5) << setfill(separator) << ID;
          cout << left << setw(nameWidth) << setfill(separator) << name;
          cout << left << setw(nameWidth-12) << setfill(separator) << type;
          cout << left << setw(numWidth) << setfill(separator) << year;
          if(made == true)
              cout << left << setw(numWidth) << setfill(separator) << "YES";
          else
              cout << left << setw(numWidth) << setfill(separator) << "NO";
          cout << endl;
     }

     cout << endl;
}

void List::printConnectionsTable(QSqlQuery q) {

    connectionsTableBegin();

    const char separator    = ' ';
    const int nameWidth     = 30;
    const int numWidth      = 15;

    while(q.next()){
        string lastName = q.value(0).toString().toStdString();
        string computerName = q.value(1).toString().toStdString();
        int yearMade = q.value(2).toUInt();


        cout << left << setw(nameWidth) << setfill(separator) << computerName;
        cout << left << setw(nameWidth) << setfill(separator) << lastName;
        cout << left << setw(numWidth) << setfill(separator) << yearMade;
        cout << endl;
    }
}



void List::printTable(QSqlQuery q) {

    tableBegin();

    const char separator    = ' ';
    const int nameWidth     = 15;
    const int numWidth      = 15;
    const int genderWidth   = 10;

    int idCount = 0;
    while (q.next()) {

        int ID = ++idCount;
        string first = q.value(1).toString().toStdString();
        string last = q.value(2).toString().toStdString();
        string sex = q.value(3).toString().toStdString();
        int born = q.value(4).toUInt();
        int died = q.value(5).toUInt();

        cout << left << setw(5) << setfill(separator) << ID;
        cout << left << setw(nameWidth) << setfill(separator) << last;
        cout << left << setw(nameWidth) << setfill(separator) << first;
        cout << left << setw(genderWidth) << setfill(separator) << sex;
        cout << left << setw(numWidth) << setfill(separator) << born;
        if(died != 0)
            cout << left << setw(numWidth) << setfill(separator) << died;
        else
            cout << left << setw(numWidth) << setfill(separator) << " - ";
        cout << endl;
     }

}

void List::orderbyComputers(int sort, int column, int view){
    q = db.getComputersSorted(sort, column);
    if(view == 0){
        printComputerList(q);
    }
    else{
        printComputerTable(q);
    }

}

void List::orderbyConnections(int sort, int column){
    q = db.getConnectionsSorted(sort, column);
    printConnectionsTable(q);
}

void List::orderbyPersons(int sort, int column, int view){
    q = db.getPersonsSorted(sort, column);
    if(view == 0){
        printList(q);
    }
    else{
       printTable(q);
    }

}

void List::showOrdered(int choice, int column, int order, int view){
    //order person table
   if (choice == 1){
        orderbyPersons(order, column, view);
   }
   //order computer table
   else if(choice == 2){
      orderbyComputers(order, column, view);

    //order connections table
   }
   else{
           orderbyConnections(order, column);
   }

}

char List:: ask_again(){

    char answer;
    cout << "Add another? (y/n)"<< endl;
    cin >> answer;

    return answer;
}

void List::search(string table){

    char ask;
    cin >> ask;
    if(ask == 'a'||ask == 'b'||ask == 'c'||ask == 'd')
        performSearchBasedOn(ask,table);
}

void List:: performSearchBasedOn(const char& selection, string& table){

    string searchby;
    bool personquery = true;

    if(table == "persons"){

        switch(selection){
            case 'a': cout << "Last name: ";
                      searchby = "lastname";
            break;
            case 'b': cout << "m/f: ";
                      searchby = "sex";
            break;
            case 'c': cout << "Enter year: ";
                      searchby = "born";

            break;
            case 'd': cout << "Enter year: ";
                      searchby = "died";
            break;
        }



    }
    else if(table == "computers"){

        personquery = false;

        switch(selection){
            case 'a': cout << "Enter name: ";
                      searchby = "name";
            break;
            case 'b': cout << "Enter type: ";
                      searchby = "type";
            break;
            case 'c': cout << "Enter year: ";
                      searchby = "yearMade";

            break;
            case 'd': cout << "Enter 1/0: ";
                      searchby = "wasMade";
            break;
        }

    }


    string target;
    cin >> target;



    if(personquery){
        QSqlQuery query = db.search(searchby,target);
        cout <<endl;
        cout << "Found the following results: "<< endl;
        printTable(query);

    }
    else{
        QSqlQuery query = db.searchComputer(searchby,target);
        cout <<endl;
        cout << "Found the following results: "<< endl;
        printComputerTable(query);
    }

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

    int result = db.countDatabaseInput(type);
    return result;

}

void List:: discover(int type){

    QSqlQuery query;

    if(type == 0){
        //get random person
        query = db.getRandom(type);

        string first = query.value(1).toString().toStdString();
        string last = query.value(2).toString().toStdString();
        string sex = query.value(3).toString().toStdString();
        int born = query.value(4).toUInt();
        int died = query.value(5).toUInt();

        person p = returnNewPersonWith(first,last,sex,born,died);
        cout << p;
    }
    else if (type == 1){
        //get random computer
        query = db.getRandom(type);

        string first = query.value(1).toString().toStdString();
        string type = query.value(2).toString().toStdString();
        int year = query.value(3).toUInt();
        bool made = query.value(4).toBool();

        computer c = returnNewComputer(first,type,year,made);
        cout << c;

    }

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


void List:: removeComputer(){

    string name;
    cin >> name;

    deleteCharacterWithName(name,1);

}

void List:: removeCharacter(){

    string name;
    cin >> name;

    deleteCharacterWithName(name,0);


}


void List:: deleteCharacterWithName(string lastname, int type){

    db.deleteObj(type,lastname);

}


void List:: tableBegin(){

    const char separator    = ' ';
    const int nameWidth     = 15;
    const int numWidth      = 15;
    const int genderWidth   = 10;

    cout << left << setw(5) << setfill(separator) << "Nr.";
    cout << left << setw(nameWidth) << setfill(separator) << "Last name";
    cout << left << setw(nameWidth) << setfill(separator) << "First name";
    cout << left << setw(genderWidth) << setfill(separator) << "Gender";
    cout << left << setw(numWidth) << setfill(separator) << "Year of birth";
    cout << left << setw(numWidth) << setfill(separator) << "Year of death";
    cout << endl;

    cout << left << setw(5) << setfill(separator) << "---";
    cout << left << setw(nameWidth) << setfill(separator) << "---------";
    cout << left << setw(nameWidth) << setfill(separator) << "---------";
    cout << left << setw(genderWidth) << setfill(separator) << "-----";
    cout << left << setw(numWidth) << setfill(separator) << "-------------";
    cout << left << setw(numWidth) << setfill(separator) << "-------------";
    cout << endl;

}

void List:: computerTableBegin(){

    const char separator    = ' ';
    const int nameWidth     = 30;
    const int numWidth      = 10;

    cout << left << setw(5) << setfill(separator) << "Nr.";
    cout << left << setw(nameWidth) << setfill(separator) << "Name";
    cout << left << setw(nameWidth-12) << setfill(separator) << "Type";
    cout << left << setw(numWidth) << setfill(separator) << "Year";
    cout << left << setw(numWidth) << setfill(separator) << "Was Made";
    cout << endl;

    cout << left << setw(5) << setfill(separator) << "---";
    cout << left << setw(nameWidth) << setfill(separator) << "----";
    cout << left << setw(nameWidth-12) << setfill(separator) << "----";
    cout << left << setw(numWidth) << setfill(separator) << "----";
    cout << left << setw(numWidth) << setfill(separator) << "--------";
    cout << endl;

}

void List:: connectionsTableBegin(){
    const char separator    = ' ';
    const int nameWidth     = 30;
    const int numWidth      = 15;

    cout << left << setw(nameWidth) << setfill(separator) << "Computer";
    cout << left << setw(nameWidth) << setfill(separator) << "Inventor";
    cout << left << setw(numWidth) << setfill(separator) << "Year Invented";
    cout << endl;

    cout << left << setw(nameWidth) << setfill(separator) << "--------";
    cout << left << setw(nameWidth) << setfill(separator) << "--------";
    cout << left << setw(numWidth) << setfill(separator) << "-------------";
    cout << endl;
}

void List:: updateComputer(int row ,QSqlQuery& cquery){


    int i = 0;

    while (cquery.next()) {

        if(i == row-1){

            string name = cquery.value(1).toString().toStdString();
            string type = cquery.value(2).toString().toStdString();
            int year = cquery.value(3).toUInt();
            bool made = cquery.value(4).toBool();

            computer c = returnNewComputer(name, type, year, made);
            cout <<endl;
            cout <<c;
            cout <<endl;

            char update = 'Y';

            while (update == 'Y'|| update == 'y'){

                cout << "Choose action: \n"
                        "1) New name. \n"
                        "2) New type. \n"
                        "3) New year built. \n"
                        "4) New was made. \n" << endl;

                cout << "Your choice: ";
                int option;
                cin>> option;

                string fieldName;

                if(option >0 && option <5){

                    switch(option){

                    case 1:{
                          cout << "New name: ";
                          fieldName ="name";
                             }
                    break;
                    case 2:{
                        cout << "New type: ";
                        fieldName ="type";
                    }
                    break;
                    case 3:{
                        cout << "New year invented: ";
                        fieldName ="yearMade";
                    }
                    break;
                    case 4:{
                        cout << "New was made(YES/NO): ";
                        fieldName ="wasMade";
                    }
                    break;

                    }

                    string obj;
                    cin >> obj;

                    int identity = db.getComputerByID(c.getName().c_str());
                    cout <<"id = "<<identity<<endl;

                    db.update(identity,fieldName,obj,"computers");

                    if(option == 1)
                        c.setName(obj);
                }

                cout << "Update again(n/y):"<<endl;
                cout << "Your choice: ";
                cin >> update;
                cout <<endl;
            }
        }

        i++;
    }
}
void List::closeDatabase() {
    db.closeDBConnection();
}


void List:: updatePioneer(int row, QSqlQuery pquery){

    int i = 0;

    while (pquery.next()) {

        if(i == row-1){

            string first = pquery.value(1).toString().toStdString();
            string last = pquery.value(2).toString().toStdString();
            string sex = pquery.value(3).toString().toStdString();
            int born = pquery.value(4).toUInt();
            int died = pquery.value(5).toUInt();

            person p = returnNewPersonWith(last,first,sex,born,died);

            cout <<endl;
            cout <<p;
            cout <<endl;

            char update = 'Y';

            while (update == 'Y'|| update == 'y'){

                cout << "Choose action: \n"
                        "1) New first name. \n"
                        "2) New last name. \n"
                        "3) New sex. \n"
                        "4) New born year. \n"
                        "5) New died year. \n" << endl;

                cout << "Your choice: ";
                int option;
                cin>> option;

                string fieldName;

                if(option >0 && option <6){

                    switch(option){

                    case 1:{
                          cout << "New first name: ";
                          fieldName ="firstname";
                             }
                    break;
                    case 2:{
                        cout << "New last name: ";
                        fieldName ="lastname";
                    }
                    break;
                    case 3:{
                        cout << "New sex(m/f): ";
                        fieldName ="sex";
                    }
                    break;
                    case 4:{
                        cout << "New born year: ";
                        fieldName ="born";
                    }
                    break;
                    case 5:{
                        cout << "New died year";
                        fieldName ="died";
                    }
                    break;

                    }

                    string obj;
                    cin.ignore(1);
                    getline(cin,obj);

                    int identity = db.getPersonID(p.getLastName().c_str(),p.getFirstName().c_str());
                    cout <<"id = "<<identity<<endl;
                    cout <<"firstname = "<<p.getFirstName()<<endl;
                    cout <<"latname = "<<p.getLastName()<<endl;

                    if(option == 1)
                        p.setFirstName(obj);
                    else if(option == 2)
                        p.setLastName(obj);

                    db.update(identity,fieldName,obj,"persons");

                }

                cout << "Update again(n/y):"<<endl;
                cout << "Your choice: ";
                cin >> update;
                cout <<endl;
            }
        }

        i++;
   }
}

void List::updateConnections(string firstName, string lastName, string computerName) {

    int personID = getPersonID(lastName, firstName);

    if( personID == -1 ) {
        cout << "Person not in database" << endl;
        return;
    }
    int computerID = getComputerID(computerName.c_str());
    if( computerID == -1) {
        cout << "Computer not in database" << endl;
        return;
    }

    cout << "Choose action: \n"
            "1) Update pioneer \n"
            "2) Update computer \n" << endl;

    cout << "Your choice: ";
    int option;
    cin>> option;
    if(option >0 && option <3){

        switch(option){

        case 1:{
            updateConnectionPerson(personID, computerID);
        }
        break;
        case 2:{
            updateConnectionComputer(personID, computerID);
        }
        break;
        }
    }
    cout <<endl;

}

void List::updateConnectionComputer(int personID, int computerID){

    string newComputerName, fieldName;
    int newcID;
    cin.ignore(1);
    cout << "New computer name: ";
    getline(cin, newComputerName);
    fieldName ="cID";
    newcID = getComputerID(newComputerName);
    if(newcID == -1) {
        return;
    } else {
      db.updateConnection(personID, computerID, fieldName, newcID);
          cout << "Update successful" << endl;
    }
}


void List::updateConnectionPerson(int personID, int computerID) {

    string newLastName, newFirstName, fieldName;
    int newpID;
    cin.ignore(1);
    cout << "New Last name: ";
    getline(cin, newLastName);
    cout << "New First name: ";
    getline(cin, newFirstName);
    fieldName = "pID";
    newpID = getPersonID(newLastName, newFirstName);
    //return if new Person not in database
    if(newpID == -1) {
       return;
    } else {
       db.updateConnection(personID, computerID, fieldName, newpID);
           cout << "Update successful" << endl;
    }
}

int List::getPersonID(string lastName, string firstName) {
    int personID = db.getPersonID(lastName.c_str(), firstName.c_str());

    if( personID == -1 || personID == 0) {
        cout << "Person not in database" << endl;
        return -1;
    }
    return personID;
}

//Use computername to get ID of cpu
int List::getComputerID(string computerName){

    int computerID = db.getComputerByID(computerName.c_str());
    if( computerID == -1 || computerID == 0) {
        cout << "Computer not in database" << endl;
        return -1;
    }
    return computerID;
}

void List::removeConnection(string firstName, string lastName, string computerName) {

    int personID = db.getPersonID(lastName.c_str(), firstName.c_str());

    if( personID == -1 || personID == 0) {
        cout << "Person not in database" << endl;
        return;
    }

    int computerID = db.getComputerByID(computerName.c_str());
    if( computerID == -1 || computerID == 0) {
        cout << "Computer not in database" << endl;
        return;
    }

    bool remove = db.removeConnectionByID(personID, computerID);
    if(remove) {
        cout << "Succesfully removed connection" << endl;
    } else {
        cout << "ID's are not valid" << endl;
    }
}
