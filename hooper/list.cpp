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


QSqlQuery List:: getComputers(){
         return db.getComputers();
}

QSqlQuery List::getConnections() {
    return db.getConnections();
}


QSqlQuery List:: getPersons(){
    return db.getPersons();
}

void List::addData(person p){

    QString qfirstname(p.getFirstName().c_str());
    QString qlastname(p.getLastName().c_str());
    QString qsex(p.getSex().c_str());

    QSqlQuery add;
    QString query;

    //Death year becomes NULL if person still alive
    if(p.getDied() != 0) {
        query = ("INSERT INTO persons VALUES(NULL, ?, ?, ?, ?, ?)");
        if(add.prepare(query)) {
            cout << "success" << endl;
            add.addBindValue(qfirstname);
            add.addBindValue(qlastname);
            add.addBindValue(qsex);
            add.addBindValue(p.getBorn());
            add.addBindValue(p.getDied());
            add.exec();
        }
    } else {
        query = "INSERT INTO persons(ID, firstname, lastname, sex, born)" "VALUES(NULL, ?, ?, ?, ?)";
        if(add.prepare(query)) {
            add.addBindValue(qfirstname);
            add.addBindValue(qlastname);
            add.addBindValue(qsex);
            add.addBindValue(p.getBorn());
            add.exec();
            cout << "Succss 0" << endl;
        } else {
            qDebug() << add.lastError() << endl;

        }
    }

}

void List::addComp(computer c){

    QString qcname(c.getName().c_str());
    QString qctype(c.getType().c_str());

    QSqlQuery add;
    QString query;

    query = ("INSERT INTO computers VALUES(NULL, ?, ?, ?, ?)");
    if(add.prepare(query)) {
        cout << "success" << endl;
        add.addBindValue(qcname);
        add.addBindValue(qctype);
        add.addBindValue(c.getYearMade());
        add.addBindValue(c.getWasMade());
        add.exec();

    }
}


void List::addConnection(string firstName, string lastName, string computerName){

   int personID = db.getPersonID(lastName.c_str(), firstName.c_str());
   cout << "This is personID " << personID << endl;

   if( personID == -1) {
       cout << "Person not in database" << endl;
       return;
   }

   int computerID = db.getComputerByID(computerName.c_str());
   if( computerID == -1) {
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
    const int nameWidth     = 15;
    const int numWidth      = 15;

    int idCount = 0;
    while (q.next()){

        int ID = ++idCount;
        string name = q.value(1).toString().toStdString();
        string type = q.value(2).toString().toStdString();
        int year = q.value(3).toUInt();
        bool made = q.value(4).toBool();

          cout << left << setw(5) << setfill(separator) << ID;
          cout << left << setw(nameWidth) << setfill(separator) << name;
          cout << left << setw(nameWidth) << setfill(separator) << type;
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
    const int nameWidth     = 15;
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
        cout << left << setw(nameWidth) << setfill(separator) << first;
        cout << left << setw(nameWidth) << setfill(separator) << last;
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

void List::search(){

    char ask;
    cin >> ask;
    if(ask == 'a'||ask == 'b'||ask == 'c'||ask == 'd')
        performSearchBasedOn(ask);
}

void List:: performSearchBasedOn(const char& selection){

    string searchby;
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

    string target;
    cin >> target;

    vector <person> sResult;

    QString obj = target.c_str();
    QString by = searchby.c_str();

    QSqlQuery query;
    QString s;
    s = ("SELECT * FROM persons WHERE %1 LIKE '%%2%' AND deleted = 'NO' ORDER BY lastname ASC" );
    query.exec(s.arg(by).arg(obj));
    qDebug()<<query.executedQuery();

        while (query.next()) {

                string first = query.value(1).toString().toStdString();
                string last = query.value(2).toString().toStdString();
                string sex = query.value(3).toString().toStdString();
                int born = query.value(4).toUInt();
                int died = query.value(5).toUInt();

                person searchedPerson = returnNewPersonWith(first,last,sex,born,died);
                sResult.push_back(searchedPerson);

        }


    if(sResult.size() == 0){
        cout << "No match found for "<<target << endl;
    }
    else{
        cout <<endl;
        cout << "Found the following results: "<< endl;

        //printTable(sResult);
    }

    cout <<  "Search again ?(y/n): ";
    char again;
    cin >> again;

    if(again == 'y'|| again == 'Y')
        search();
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

void List:: discover(int type){

    QSqlQuery query;
    QString s;

    if(type == 0){

        s = ("SELECT * FROM persons WHERE deleted = 'NO' ORDER BY RANDOM() LIMIT 1");
        query.exec(s);
        query.first();

        string first = query.value(1).toString().toStdString();
        string last = query.value(2).toString().toStdString();
        string sex = query.value(3).toString().toStdString();
        int born = query.value(4).toUInt();
        int died = query.value(5).toUInt();

        person p = returnNewPersonWith(first,last,sex,born,died);
        cout << p;
    }
    /*else if (type == 1){

        s = ("SELECT * FROM computers WHERE deleted = 'NO' ORDER BY RANDOM() LIMIT 1");
        query.exec(s);
        query.first();

        string first = query.value(1).toString().toStdString();
        string type = query.value(2).toString().toStdString();
        int year = query.value(3).toUInt();
        bool made = query.value(4).toBool();

        //computer c = returnNewComputer(first,type,year,made);
        //cout << c;

    }*/

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

person List:: returnPersonAtIndex(int index){

    person p = characters[index];
    return p;
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

void List:: removeCharacterWithIndex(){

    int max = countDatabase(0);

    if(max > 0){

        cout << "Type a number between 1 and " << max << ": ";
        int removeIndex;
        cin >> removeIndex;

        if(removeIndex >= 1 && removeIndex <= max){

            deleteRowAtIndex(removeIndex,0);
            cout << "Successfully removed:" << endl;

        }
        else {
            cout << "No person found with that index" << endl;
        }

    }
    else {
        cout << "Database is empty" << endl;
    }
}

void List:: removeComputerWithIndex(){

    int max = countDatabase(1);

    if(max > 0){

        cout << "Type a number between 1 and " << max << ": ";
        int removeIndex;
        cin >> removeIndex;

        if(removeIndex >= 1 && removeIndex <= max){

            deleteRowAtIndex(removeIndex,1);
            cout << "Successfully removed:" << endl;
        }
        else {
            cout << "No computer found with that index" << endl;
        }

    }
    else {
        cout << "Database is empty" << endl;
    }


}

void List:: deleteRowAtIndex(int rowNumber,int type){

    QSqlQuery query;
    QString s;

    if(type == 0){

        s = ( "UPDATE persons SET deleted = 'YES' WHERE id = '%1'" );

        query.exec(s.arg(rowNumber));
        qDebug()<< query.executedQuery();
    }
    else if (type == 1){

        s = ( "UPDATE computers SET deleted = 'YES' WHERE id = '%1'" );

        query.exec(s.arg(rowNumber));
        qDebug()<< query.executedQuery();
    }

}

void List:: deleteCharacterWithName(string lastname, int type){

    QSqlQuery query;
    QString s;

    if(type == 0){

         s = ( "UPDATE persons SET deleted = 'YES' WHERE lastname = '%1'" );
         query.exec(s.arg(QString(lastname.c_str())));
         qDebug()<< query.executedQuery();

    }
    else if (type == 1){

        s = ( "UPDATE computers SET deleted = 'YES' WHERE name = '%1'" );
        query.exec(s.arg(QString(lastname.c_str())));
        qDebug()<< query.executedQuery();
    }

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
    const int nameWidth     = 15;
    const int numWidth      = 15;

    cout << left << setw(5) << setfill(separator) << "Nr.";
    cout << left << setw(nameWidth) << setfill(separator) << "Name";
    cout << left << setw(nameWidth) << setfill(separator) << "Type";
    cout << left << setw(numWidth) << setfill(separator) << "Year Made";
    cout << left << setw(numWidth) << setfill(separator) << "Was Made";
    cout << endl;

    cout << left << setw(5) << setfill(separator) << "---";
    cout << left << setw(nameWidth) << setfill(separator) << "----";
    cout << left << setw(nameWidth) << setfill(separator) << "----";
    cout << left << setw(numWidth) << setfill(separator) << "---------";
    cout << left << setw(numWidth) << setfill(separator) << "--------";
    cout << endl;

}

void List:: connectionsTableBegin(){
    const char separator    = ' ';
    const int nameWidth     = 15;
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
                        "3) New year made. \n"
                        "4) New was made. \n" << endl;

                cout << "Your choice: ";
                int option;
                cin>> option;

                string fieldName;

                if(option >0 && option <5){

                    switch(option){

                    case 1:{
                          cout << "new name: ";
                          fieldName ="name";
                             }
                    break;
                    case 2:{
                        cout << "new type: ";
                        fieldName ="type";
                    }
                    break;
                    case 3:{
                        cout << "new year made: ";
                        fieldName ="yearMade";
                    }
                    break;
                    case 4:{
                        cout << "new was made(YES/NO): ";
                        fieldName ="wasMade";
                    }
                    break;

                    }

                    string obj;
                    cin >> obj;

                    int identity = db.getComputerByID(c.getName().c_str());
                    db.Update(identity,fieldName,obj,"computers");

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


void List:: updatePioneer(int row, QSqlQuery pquery){

    int i = 0;

    while (pquery.next()) {

        if(i == row-1){

            string first = pquery.value(1).toString().toStdString();
            string last = pquery.value(2).toString().toStdString();
            string sex = pquery.value(3).toString().toStdString();
            int born = pquery.value(4).toUInt();
            int died = pquery.value(5).toUInt();

            person p = returnNewPersonWith(first,last,sex,born,died);

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
                          cout << "new first name: ";
                          fieldName ="firstname";
                             }
                    break;
                    case 2:{
                        cout << "new last name: ";
                        fieldName ="lastname";
                    }
                    break;
                    case 3:{
                        cout << "new sex(m/f): ";
                        fieldName ="sex";
                    }
                    break;
                    case 4:{
                        cout << "new born year";
                        fieldName ="born";
                    }
                    break;
                    case 5:{
                        cout << "new died year";
                        fieldName ="died";
                    }
                    break;

                    }

                    string obj;
                    cin >> obj;

                    int identity = db.getPersonID(p.getLastName().c_str(),p.getFirstName().c_str());
                    cout <<"got id: "<<identity<<endl;
                    db.Update(identity,fieldName,obj,"persons");

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
