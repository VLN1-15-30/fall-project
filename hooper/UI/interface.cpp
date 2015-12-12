#include <iostream>
#include "interface.h"
#include <algorithm>
#include <iomanip>

using namespace std;

Interface::Interface(){
    utils::getDatabaseConnection();
}

void Interface::welcomeMessage(){
    cout << "Welcome to the Hooper database!\n"<<endl;

        cout<<" -------------------------------------------- \n"
              "| The database contains information about    | \n"
              "| pioneers and computers in computer science.| \n"
              " -------------------------------------------- \n"
           << endl;

        showUsage();
}

void Interface::actions(){

    cout << "Choose a number for your next action: \n"
            "1) View \n"
            "2) Search \n"
            "3) Add \n"
            "4) Discover \n"
            "5) Remove  \n"
            "6) Update \n"<< endl;

    cout << "Your choice: ";

    int action;
    cin >> action;

    switch(action){
        case 1: view();
        break;
        case 2: find();
        break;
        case 3: add();
        break;
        case 4: discover();
        break;
        case 5: askToDelete();
        break;
        case 6: update();
        break;
        default:
        break;

    }
}

//User input options for choosing what to table
void Interface::update(){

    cout << endl;
    cout << "Choose an action: \n"
            "1) Update a pioneer \n"
            "2) Update a computer \n"
            "3) Update a connection \n"<<endl;

    cout << "Your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:updatePioneers();
        break;
    case 2:updateComputers();
        break;
    case 3:updateConnections();
    default:
        break;
    }

}

//sending information through servicelayer(list) to uptdate database
void Interface::updateComputers(){

    cout <<endl;
    cout <<"==== Update computers ===="<<endl;

    vector<computer> c = ComputerScientists.getComputers();
    printComputerTable(c);
    cout << "Enter row number: ";
    int row;
    cin >> row;
    vector<computer> updateC = ComputerScientists.getComputers();
    updateComputer(row,updateC);
}

void Interface::updatePioneers(){

    cout <<endl;
    cout <<"==== Update pioneers ===="<<endl;

    vector<person> getq = ComputerScientists.getPersons();
    printPersonTable(getq);
    cout << "Enter row number: ";
    int row;
    cin >> row;
    vector<person> updateQ = ComputerScientists.getPersons();
    updatePioneer(row,updateQ);

}

void Interface::updateConnections(){
    cout << endl;
    cout <<"==== Update connections ===="<<endl;

    string lastName, firstName, computerName;
    vector<connection> getq = ComputerScientists.getConnections();
    printConnectionTable(getq);

    cout << "Please write the name of inventor and the computer." << endl;
    cin.ignore(1);
    cout << "First name: ";
    getline(cin,firstName);
    cout << "Last name: ";
    getline(cin,lastName);
    cout << "Computer name: ";
    getline(cin, computerName);
    updateConnections(firstName, lastName, computerName);
}

void Interface::view(){

    int choice;
    cout << endl;
    cout << "Choose an action: \n"
            "1) View pioneers \n"
            "2) View computers \n"
            "3) View connections between pioneers and computers" << endl;
    cout << "Your choice: ";

    cin >> choice;
    char answer;
    cout << "Do you wish to control the order of the data(y/n)? ";
    cin >> answer;
    switch(answer){
        case 'Y':
        case 'y':order(choice);
        break;
        case 'N':
        case 'n': viewOptions(choice);
        break;
    }
}

//sending information to "list" to recieve information from database
void Interface::viewOptions(int choice){

    cout << "Write 0 to view as list, 1 to view as Table" << endl;
    int view;
    cin >> view;
    cout << endl;

    vector<computer> c = ComputerScientists.getComputers();
    vector<person> p = ComputerScientists.getPersons();
    vector<connection> conn = ComputerScientists.getConnections();

    if(choice == 1){
        cout <<"==== Pioneer database ===="<< endl;
        if(view == 0){
           // ComputerScientists.printList(p);
        }
        else if(view == 1){
            printPersonTable(p);
        }
    }
    else if(choice == 2){
        cout <<"==== Computer database ===="<< endl;
        if(view == 0){
            //ComputerScientists.printComputerList(c);
        }
        else if(view == 1){
            printComputerTable(c);
        }
    }
    else{
        cout <<"==== Overview of connections ===="<<endl;
        if(view == 0){
           // ComputerScientists.printConnectionsList(q);
        }

        else if(view == 1){
            printConnectionTable(conn);
        }
    }
}

//Using 0 and 1 to give user simple option choosing
void Interface::order(int choice){

    int column, order;

    switch(choice){
    case 1: cout << "Write 0 to order by last name, 1 to order by birth year" << endl;
            cin >> column;
    break;
    case 2: cout << "Write 0 to order by computer name, 1 to order by computer type" << endl;
            cin >> column;
    break;
    case 3: cout << "Write 0 to order by inventor, 1 to order by computer," <<
                   endl << " 2 to order by year invented" << endl;
            cin >> column;
    }

    cout << "Write 0 for ascending order, 1 for descending order" << endl;
    cin >> order;

    vector<person> p;
    vector<computer> c;
    vector<connection> conn;
    cout <<"==== Database ===="<< endl;
    switch(choice){
    case 1: p = ComputerScientists.orderbyPersons(order, column);
            printPersonTable(p);
    break;
    case 2: c = ComputerScientists.orderbyComputers(order, column);
            printComputerTable(c);
    break;
    case 3: conn = ComputerScientists.orderbyConnections(order, column);
           printConnectionTable(conn);
    }

}

//Use 1,2 to give user option to search from database
void Interface::find(){

    cout <<endl;
    cout << "Choose an action: \n"
            "1) Find a pioneer\n"
            "2) Find a computer\n"<<endl;

    cout << "Your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:findPioneers();
        break;
    case 2:findComputers();
        break;
    default:
        break;
    }
}

//Searching for computers. Searching while the condition is true
void Interface::findComputers(){

    if(ComputerScientists.computersDatabaseEmpty()) return;

    char again = 'y';
    while(again == 'y'||again == 'Y'){
        cout << endl;
        cout <<"==== Search ===="<<endl;
        cout << "a) Name "<<endl;
        cout << "b) Type " << endl;
        cout << "c) Year built " << endl;
        cout << "d) Was made (1/0) " << endl;
        cout << "Search by: ";

        search("computers");

        cout << "Search again ?(y/n): ";
        cin >> again;
    }
}

//use a,b,c... for sublist of choices for user input
void Interface::findPioneers(){

    if(ComputerScientists.databaseEmpty()) return;

    char again = 'y';
    while(again == 'y'||again == 'Y'){
        cout << endl;
        cout <<"==== Search ===="<<endl;
        cout << "a) Last Name "<<endl;
        cout << "b) Sex " << endl;
        cout << "c) Year of birth " << endl;
        cout << "d) Year of death " << endl;
        cout << "Search by: ";

        search("persons");

        cout <<  "Search again ?(y/n): ";
        cin >> again;
    }
}

void Interface::add(){

    char answer = 'y';
    int choice;
    cout << endl;
    cout << "Choose an action: \n"
            "1) Add a pioneer\n"
            "2) Add a computer\n"
            "3) Add a connection\n";

    cout << "Your choice: ";
    cin >> choice;
    cout << endl;

    switch(choice){
        case 1: addPioneer(answer);
        break;
        case 2: addComputer(answer);
        break;
        case 3: addConnection(answer);
        break;
    }
}

void Interface::addPioneer(char answer){

    cout << "===== Add a pioneer =====" << endl;
    while(answer == 'y' || answer == 'Y'){
        string firstname, lastname, sex;
        int born, died;
        cin.ignore(1);
        cout << "First name: ";
        getline(cin,firstname);
        cout << "Last name: ";
        getline(cin,lastname);
        cout << "Sex(m/f): ";
        getline(cin,sex);
        // sex = errorCheckSex(sex);
        cout << "Born: ";
        cin >> born;
        // born = errorCheckNumber(born,0);
        cout << "Died(0 if alive): ";
        cin >> died;
        // died = errorCheckNumber(died,1);
        cout << endl;

        if(born <= died || died == 0) {

            person pers;
            pers.setFirstName(firstname);
            pers.setLastName(lastname);
            pers.setSex(sex);
            pers.setBorn(born);
            pers.setDied(died);

           bool check = ComputerScientists.addPerson(pers);
           if(check) {
               cout << "Successfully added" << endl;
           } else {
               cout << "Failed to add" << endl;
           }
        }
        else{
            cout << "Invalid input: Birth year > death year" << endl;
        }
            answer = ComputerScientists.ask_again();
    }
}

void Interface::addComputer(char answer){

    cout << "===== Add a computer =====" << endl;
    while(answer == 'y' || answer == 'Y'){
        string name, type;
        int year;
        bool made;
        cin.ignore(1);
        cout << "Computer name: ";
        getline(cin, name);
        cout << "Computer type: ";
        getline(cin, type);
        cout << "Year invented: ";
        cin >> year;
        cout << "Was it made(0 if not made else 1): ";
        cin >> made;
        // died = errorCheckNumber(died,1);
        cout << endl;

            computer comp;
            comp.setName(name);
            comp.setType(type);
            comp.setYearMade(year);
            comp.setWasMade(made);

            bool check = ComputerScientists.addComp(comp);
            if(check) {
                cout << "Successfully added" << endl;
            } else {
                cout << "Failed to add" << endl;
            }

            answer = ComputerScientists.ask_again();
    }
}

void Interface::addConnection(char answer){

    cout << "===== Add a connection =====" << endl;

    while(answer == 'y' || answer == 'Y'){

        vector<person> p = ComputerScientists.getPersons();
        vector<computer> c = ComputerScientists.getComputers();
        printPersonTable(p);
        printComputerTable(c);

        string firstName, lastName, computerName;
        cout << "Lastname of person: ";
        cin.ignore(1);
        getline(cin, lastName);
        cout << "First name: ";
        getline(cin, firstName);

        cout << "Name of cpu: ";
        getline(cin, computerName);


        bool check = ComputerScientists.addConnection(firstName, lastName, computerName);
        if(check) {
            cout << "Succesfully added new connections" << endl;
        } else {
            cout << "Failed to add" << endl;
        }
        answer = ComputerScientists.ask_again();
        }
}

void Interface::discover(){

    cout <<endl;
    cout << "Choose an action: \n"
            "1) Discover a pioneer.\n"
            "2) Discover a computer.\n"<<endl;

    cout << "Your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:discoverPioneer();
        break;
    case 2:discoverComputer();
        break;
    default:
        break;
    }

}

void Interface::discoverComputer(){

    cout << "==== Discover a Computer ===="<<endl;
    if(ComputerScientists.computersDatabaseEmpty()) return;

    computer c = ComputerScientists.discoverComputer();
    cout << c;
}

void Interface::discoverPioneer(){

    cout << "==== Discover a pioneer ===="<<endl;
    if(ComputerScientists.databaseEmpty()) return;

    person p = ComputerScientists.discoverPerson();
    cout << p;
}

void Interface::askToDelete(){

    cout <<endl;
    cout << "Choose an action: \n"
            "1) Delete a pioneer\n"
            "2) Delete a computer\n"
            "3) Delete a connection\n"<<endl;

    cout << "Your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:deleteCharacter();
        break;
    case 2:deleteComputer();
        break;
    case 3:deleteConnection();
        break;
    default:
        break;
    }

}

void Interface::deleteCharacter(){

   if(ComputerScientists.databaseEmpty()) return;

    vector<person> p = ComputerScientists.getPersons();
    printPersonTable(p);

   cout << "==== Remove a pioneer ===="<<endl;
   cout << "Type last name: ";
   removeCharacter();
}

void Interface::deleteComputer(){

    if(ComputerScientists.computersDatabaseEmpty()) return;

    vector<computer> c = ComputerScientists.getComputers();
    printComputerTable(c);
    cout << "==== Remove Computer ===="<<endl;

    cout << "Type name of computer: ";
    removeComputer();
}


void Interface::deleteConnection(){

    cout << "==== Remove Connection ===="<<endl;
    vector<connection> conn = ComputerScientists.getConnections();
    printConnectionTable(conn);
    cout << "Write Inventors name and computer name"<<endl;
    string firstName, lastName, computerName;

    cin.ignore(1);
    cout << "First name: ";
    getline(cin,firstName);
    cout << "Last name: ";
    getline(cin,lastName);
    cout << "Computer name: ";
    getline(cin, computerName);
    ComputerScientists.removeConnection(firstName, lastName, computerName);
}

void Interface::showUsage() {

    cout << "Hooper is currently storing information about " << endl;
    cout << ComputerScientists.countDatabase(0) << " pioneers and ";
    cout << ComputerScientists.countDatabase(1) << " computers." << endl;
    cout << endl;
}

void Interface::personTableBegin(){

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

void Interface::computerTableBegin(){

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

void Interface::connectionsTableBegin()
{
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

void Interface::printComputerTable(vector<computer> &c){

    computerTableBegin();

    const char separator    = ' ';
    const int nameWidth     = 30;
    const int numWidth      = 10;

    for(unsigned int i = 0; i < c.size(); i++ ){

          computer cpu = c[i];

          cout << left << setw(5) << setfill(separator) << i+1;
          cout << left << setw(nameWidth) << setfill(separator) << cpu.getName();
          cout << left << setw(nameWidth-12) << setfill(separator) << cpu.getType();
          cout << left << setw(numWidth) << setfill(separator) <<cpu.getYearMade();
          if(cpu.getWasMade() == true)
              cout << left << setw(numWidth) << setfill(separator) << "YES";
          else
              cout << left << setw(numWidth) << setfill(separator) << "NO";
          cout << endl;
     }

     cout << endl;
}

void Interface::printPersonTable(vector<person> &p){

    personTableBegin();

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

void Interface::printConnectionTable(vector<connection> &c){

    connectionsTableBegin();

    const char separator    = ' ';
    const int nameWidth     = 30;
    const int numWidth      = 15;

    for(int i = 0; i < c.size(); i++){

        connection conn = c[i];

        cout << left << setw(nameWidth) << setfill(separator) << conn.getComputerName();
        cout << left << setw(nameWidth) << setfill(separator) << conn.getLastName();
        cout << left << setw(numWidth) << setfill(separator) << conn.getYearInvented();
        cout << endl;
    }
}

void Interface::performSearchBasedOn(const char &selection, string &table){

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
        vector<person> p = ComputerScientists.getSearchPerson(searchby,target);
        cout <<endl;
        cout << "Found the following results: "<< endl;
        printPersonTable(p);
    }
    else{
        vector<computer> c = ComputerScientists.getSearchComputer(searchby,target);
        cout <<endl;
        cout << "Found the following results: "<< endl;
        printComputerTable(c);
    }

}

void Interface::search(string table){

        char ask;
        cin >> ask;
        if(ask == 'a'||ask == 'b'||ask == 'c'||ask == 'd')
            performSearchBasedOn(ask,table);
}

void Interface::removeComputer(){

    string name;
    cin >> name;

    ComputerScientists.deleteCharacterWithName(name,1);

}

void Interface::removeCharacter(){

    string name;
    cin >> name;

    ComputerScientists.deleteCharacterWithName(name,0);
}

void Interface::updatePioneer(int row, vector<person> &p){


    for(int i = 0; i < p.size(); i++) {

        if(i == row-1){

            cout <<endl;
            cout << p[i];
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

                    int identity = ComputerScientists.getPersonID(p[i].getLastName(),p[i].getFirstName());
                    cout <<"id = "<<identity<<endl;
                    cout <<"firstname = "<<p[i].getFirstName()<<endl;
                    cout <<"latname = "<<p[i].getLastName()<<endl;

                    if(option == 1)
                        p[i].setFirstName(obj);
                    else if(option == 2)
                        p[i].setLastName(obj);

                    ComputerScientists.update(identity,fieldName,obj,"persons");

                }

                cout << "Update again(n/y):"<<endl;
                cout << "Your choice: ";
                cin >> update;
                cout <<endl;
            }
        }

   }
}

void Interface::updateComputer(int row, vector<computer> &c){


    for(int i = 0; i < c.size(); i++) {

        if(i == row-1){

            cout <<endl;
            cout <<c[i];
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
                    cin.ignore(1);
                    getline(cin, obj);

                    int identity = ComputerScientists.getComputerID(c[i].getName());
                    cout <<"id = "<<identity<<endl;

                    if(option == 1)
                        c[i].setName(obj);

                    ComputerScientists.update(identity,fieldName,obj,"computers");

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

void Interface::updateConnections(string firstName, string lastName, string computerName){

    int personID = ComputerScientists.getPersonID(lastName, firstName);

    if( personID == -1 ) {
        cout << "Person not in database" << endl;
        return;
    }
    int computerID = ComputerScientists.getComputerID(computerName.c_str());
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

void Interface::updateConnectionComputer(int personID, int computerID){

    string newComputerName, fieldName;
    int newcID;
    cin.ignore(1);
    cout << "New computer name: ";
    getline(cin, newComputerName);
    fieldName ="cID";
    newcID = ComputerScientists.getComputerID(newComputerName);
    if(newcID == -1) {
        return;
    } else {
      ComputerScientists.updateConnection(personID, computerID, fieldName, newcID);
          cout << "Update successful" << endl;
    }
}

void Interface::updateConnectionPerson(int personID, int computerID){

    string newLastName, newFirstName, fieldName;
    int newpID;
    cin.ignore(1);
    cout << "New Last name: ";
    getline(cin, newLastName);
    cout << "New First name: ";
    getline(cin, newFirstName);
    fieldName = "pID";
    newpID = ComputerScientists.getPersonID(newLastName, newFirstName);
    //return if new Person not in database
    if(newpID == -1) {
       return;
    } else {
       ComputerScientists.updateConnection(personID, computerID, fieldName, newpID);
           cout << "Update successful" << endl;
    }
}

void Interface::quit() {
    ComputerScientists.closeDatabase();
}
