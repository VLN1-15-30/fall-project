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

vector<computer> const List:: getComputers(){
    //delete our vector objects and refresh data
    computers.erase(computers.begin(),computers.end());

    QSqlQuery dataQuery(QString("SELECT * FROM computers WHERE deleted = 'NO'"));
    dataQuery.exec();
    //qDebug()<<dataQuery.executedQuery();

        while (dataQuery.next()) {

            string first = dataQuery.value(1).toString().toStdString();
            string type = dataQuery.value(2).toString().toStdString();
            int year = dataQuery.value(3).toUInt();
            bool made = dataQuery.value(4).toBool();

            computer c = returnNewComputer(first,type,year,made);

            computers.push_back(c);

        }

        return computers;

}

vector<person> const List:: getChar(){
    //delete our vector objects and refresh data
    characters.erase(characters.begin(),characters.end());

    QSqlQuery dataQuery(QString("SELECT * FROM persons WHERE deleted = 'NO'"));
    dataQuery.exec();
    //qDebug()<<dataQuery.executedQuery();

        while (dataQuery.next()) {

                string first = dataQuery.value(1).toString().toStdString();
                string last = dataQuery.value(2).toString().toStdString();
                string sex = dataQuery.value(3).toString().toStdString();
                int born = dataQuery.value(4).toUInt();
                int died = dataQuery.value(5).toUInt();

                person searchedPerson =  returnNewPersonWith(first,last,sex,born,died);

                characters.push_back(searchedPerson);

        }

        return characters;

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

void List::addConnection(int personID, int computerID){

    QSqlQuery q;
    QString query = "INSERT INTO PC VALUES(?, ?)";
    if(q.prepare(query)) {
        cout << "sucess" << endl;
        q.addBindValue(personID);
        q.addBindValue(computerID);
        q.exec();
    } else {
        qDebug() << q.lastError() << endl;
    }

    QSqlQuery q1;
    QString query1("SELECT P.lastname, C.name "
                   "FROM PC I "
                   "    INNER JOIN persons P ON P.id = I.pID "
                   "    INNER JOIN computers C ON C.id = I.cID");
    if(q1.prepare(query1)) {
        q1.exec();
        while(q1.next()){
            string lastname = q1.value(0).toString().toStdString();
            string computerName = q1.value(1).toString().toStdString();
            cout << computerName << " was invented by " << lastname << endl;
        }
    }

}

void List:: writeToFile(vector <person>& p){


    ofstream out_stream;
    out_stream.open("persons.txt", ios::app);
    if (out_stream.fail( ))
    {
        cout << "Failed to write to database."<<endl;
        return;
    }

    for (unsigned int i = 0; i< p.size(); i++) {
        person pers = p[i];
          out_stream << pers.getFirstName()<<" " << pers.getLastName() << " "
                     << pers.getSex() <<" " << pers.getBorn()<<" "
                     << pers.getDied() << endl;
    }

    out_stream.close( );

}

void List::printList(vector <person>& p){

    cout <<"==== DATABASE ===="<<endl;
    for (unsigned int i = 0; i < p.size(); i++){
        cout << p.at(i) << endl;
    }
}

void List::printComputerList(vector <computer>& c){

    cout <<"==== DATABASE ===="<<endl;
    for (unsigned int i = 0; i < c.size(); i++){
        cout << c.at(i) << endl;
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

void List:: printComputerTable(vector<computer> &c){

    cout <<"==== COMPUTER DATABASE ===="<<endl;
    computerTableBegin();

    const char separator    = ' ';
    const int nameWidth     = 15;
    const int numWidth      = 15;

    for (unsigned int i = 0; i< c.size(); i++) {

          computer comp = c[i];

          cout << left << setw(5) << setfill(separator) << i+1;
          cout << left << setw(nameWidth) << setfill(separator) << comp.getName();
          cout << left << setw(nameWidth) << setfill(separator) << comp.getType();
          cout << left << setw(numWidth) << setfill(separator) << comp.getYearMade();
          if(comp.getWasMade() == true)
              cout << left << setw(numWidth) << setfill(separator) << "YES";
          else
              cout << left << setw(numWidth) << setfill(separator) << "NO";
          cout << endl;
     }

     cout << endl;
}

void List::printTable(vector <person>& p) {

    cout <<"==== DATABASE ===="<<endl;
    tableBegin();

    const char separator    = ' ';
    const int nameWidth     = 15;
    const int numWidth      = 15;
    const int genderWidth   = 10;

    for (unsigned int i = 0; i< p.size(); i++) {

          person pers = p[i];

          cout << left << setw(5) << setfill(separator) << i+1;
          cout << left << setw(nameWidth) << setfill(separator) << pers.getLastName();
          cout << left << setw(nameWidth) << setfill(separator) << pers.getFirstName();
          cout << left << setw(genderWidth) << setfill(separator) << pers.getSex();
          cout << left << setw(numWidth) << setfill(separator) << pers.getBorn();
          if(pers.getDied() != 0)
              cout << left << setw(numWidth) << setfill(separator) << pers.getDied();
          else
              cout << left << setw(numWidth) << setfill(separator) << " - ";
          cout << endl;
     }

     cout << endl;
}

void List::orderbyNameA_Z(int format){

         vector <person> sResult;

         QSqlQuery query(db);
         QString s;
         query.prepare("SELECT * FROM persons WHERE deleted = 'NO' ORDER BY lastname ASC");
         query.exec();
         qDebug()<<query.executedQuery();
         while (query.next()) {

            string first = query.value(1).toString().toStdString();
            string last = query.value(2).toString().toStdString();
            string sex = query.value(3).toString().toStdString();
            int born = query.value(4).toUInt();
            int died = query.value(5).toUInt();

            person orderedPerson = returnNewPersonWith(first,last,sex,born,died);
            sResult.push_back(orderedPerson);

         }
         if(format == 0)
                 printList(sResult);
             else
                 printTable(sResult);
}

void List::orderbyNameZ_A(int format){

    vector <person> sResult;

    QSqlQuery query(db);
    QString s;
    query.prepare("SELECT * FROM persons WHERE deleted = 'NO' ORDER BY lastname DESC");
    query.exec();
    qDebug()<<query.executedQuery();
    while (query.next()) {

       string first = query.value(1).toString().toStdString();
       string last = query.value(2).toString().toStdString();
       string sex = query.value(3).toString().toStdString();
       int born = query.value(4).toUInt();
       int died = query.value(5).toUInt();


       person orderedPerson = returnNewPersonWith(first,last,sex,born,died);
       sResult.push_back(orderedPerson);

       }
    if(format == 0)
            printList(sResult);
        else
            printTable(sResult);
}

void List::orderbyBornASC(int format){

    vector <person> sResult;

    QSqlQuery query(db);
    QString s;
    query.prepare("SELECT * FROM persons  WHERE deleted = 'NO' ORDER BY born ASC");
    query.exec();
    qDebug()<<query.executedQuery();
    while (query.next()) {

       string first = query.value(1).toString().toStdString();
       string last = query.value(2).toString().toStdString();
       string sex = query.value(3).toString().toStdString();
       int born = query.value(4).toUInt();
       int died = query.value(5).toUInt();


       person orderedPerson = returnNewPersonWith(first,last,sex,born,died);
       sResult.push_back(orderedPerson);

       }
    if(format == 0)
            printList(sResult);
        else
            printTable(sResult);
}

void List::orderbyBornDESC(int format){

    vector <person> sResult;

    QSqlQuery query(db);
    QString s;
    query.prepare("SELECT * FROM persons  WHERE deleted = 'NO' ORDER BY born DESC");
    query.exec();
    qDebug()<<query.executedQuery();
    while (query.next()) {

       string first = query.value(1).toString().toStdString();
       string last = query.value(2).toString().toStdString();
       string sex = query.value(3).toString().toStdString();
       int born = query.value(4).toUInt();
       int died = query.value(5).toUInt();


       person orderedZAPerson = returnNewPersonWith(first,last,sex,born,died);
       sResult.push_back(orderedZAPerson);

       }
    if(format == 0)
            printList(sResult);
        else
            printTable(sResult);
}

void List::orderbyComputerNameA_Z(int format){

         vector <computer> sResult;

         QSqlQuery query(db);
         QString s;
         query.prepare("SELECT * FROM computers ORDER BY name ASC");
         query.exec();
         qDebug()<<query.executedQuery();
         while (query.next()) {

            string name = query.value(1).toString().toStdString();
            string type = query.value(2).toString().toStdString();
            int year = query.value(3).toUInt();
            bool made = query.value(4).toBool();

            computer orderedComputer = returnNewComputer(name, type, year, made);
            sResult.push_back(orderedComputer);

         }
         if(format == 0)
                 printComputerList(sResult);
             else
                 printComputerTable(sResult);
}

void List::orderbyComputerNameZ_A(int format){

         vector <computer> sResult;

         QSqlQuery query(db);
         QString s;
         query.prepare("SELECT * FROM computers ORDER BY name DESC");
         query.exec();
         qDebug()<<query.executedQuery();
         while (query.next()) {

            string name = query.value(1).toString().toStdString();
            string type = query.value(2).toString().toStdString();
            int year = query.value(3).toUInt();
            bool made = query.value(4).toBool();

            computer orderedComputer = returnNewComputer(name, type, year, made);
            sResult.push_back(orderedComputer);

         }
         if(format == 0)
                 printComputerList(sResult);
             else
                 printComputerTable(sResult);
}

void List::orderbyComputerTypeA_Z(int format){

         vector <computer> sResult;

         QSqlQuery query(db);
         QString s;
         query.prepare("SELECT * FROM computers ORDER BY type ASC");
         query.exec();
         qDebug()<<query.executedQuery();
         while (query.next()) {

            string name = query.value(1).toString().toStdString();
            string type = query.value(2).toString().toStdString();
            int year = query.value(3).toUInt();
            bool made = query.value(4).toBool();

            computer orderedComputer = returnNewComputer(name, type, year, made);
            sResult.push_back(orderedComputer);

         }
         if(format == 0)
                 printComputerList(sResult);
             else
                 printComputerTable(sResult);
}

void List::orderbyComputerTypeZ_A(int format){

         vector <computer> sResult;

         QSqlQuery query(db);
         QString s;
         query.prepare("SELECT * FROM computers ORDER BY type DESC");
         query.exec();
         qDebug()<<query.executedQuery();
         while (query.next()) {

            string name = query.value(1).toString().toStdString();
            string type = query.value(2).toString().toStdString();
            int year = query.value(3).toUInt();
            bool made = query.value(4).toBool();

            computer orderedComputer = returnNewComputer(name, type, year, made);
            sResult.push_back(orderedComputer);

         }
         if(format == 0)
                 printComputerList(sResult);
             else
                 printComputerTable(sResult);
}

void List::showOrdered(int choice, int column, int order, int format){
   if (choice == 1){
        if(column == NAME) {
            if( order == 0) {
                orderbyNameA_Z(format);
            }
            else {
                orderbyNameZ_A(format);
            }
        }
        else if (column == BORN){
            if( order == 0){
                orderbyBornASC(format);
            }
            else {
                orderbyBornDESC(format);
            }
        }
   }
   if(choice == 2){
       if(column == 0){
           if( order == 0){
               orderbyComputerNameA_Z(format);
           }
           else{
               orderbyComputerNameZ_A(format);
           }
       }
       if(column == 1){
           if(order == 0){
               orderbyComputerTypeA_Z(format);
           }
           else{
               orderbyComputerTypeZ_A(format);
           }
       }

   }

}

char List:: ask_again(){

    char answer;
    cout << "Add another person? (y/n)"<< endl;
    cin >> answer;

    return answer;
}

void List::search(){

    cout << endl;
    cout <<"==== Search ===="<<endl;
    cout <<"a: Last Name "<<endl;
    cout << "b: Sex " << endl;
    cout << "c: Year of birth " << endl;
    cout << "d: Year of death " << endl;

    cout << "Search by: ";

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

    QSqlQuery query(db);
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

        printTable(sResult);
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

    QSqlQuery query(db);
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

    QSqlQuery query(db);
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
    else if (type == 1){

        s = ("SELECT * FROM computers WHERE deleted = 'NO' ORDER BY RANDOM() LIMIT 1");
        query.exec(s);
        query.first();

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


person List:: returnPersonAtIndex(int index){

    person p = characters[index];
    return p;
}

void List:: removeComputer(){

    cout << "Type name of computer: ";
    string name;
    cin >> name;

    deleteCharacterWithName(name,1);

}

void List:: removeCharacter(){

    cout << "Type last name: ";
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
            /*
            removeIndex--;
            string deletedPerson = characters.at(removeIndex).getLastName();
            characters.erase(characters.begin()+removeIndex);
            cout << "Successfully removed: " << deletedPerson << endl;
            */
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

    QSqlQuery query(db);
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

    QSqlQuery query(db);
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

void List:: OverWriteToFile(vector <person>& p){

    ofstream out_stream;
    out_stream.open("persons.txt");

    if (out_stream.fail( )){
        cout << "Failed to write to database."<<endl;
        return;
    }

    for (unsigned int i = 0; i< p.size(); i++) {
        person pers = p[i];
          out_stream << pers.getFirstName()<<" " << pers.getLastName() << " "
                     << pers.getSex() <<" " << pers.getBorn()<<" "
                     << pers.getDied() << endl;
    }

    out_stream.close( );

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


