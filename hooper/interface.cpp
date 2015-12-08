#include <iostream>
#include "interface.h"
#include <algorithm>

using namespace std;


Interface::Interface(){
    ComputerScientists.initialize();
}
void Interface::welcomeMessage(){
    cout << "Welcome to the Hooper database!\n"<<endl;

        cout<<" -------------------------------------------- \n"
              "| The database contains information about    | \n"
              "| pioneers and computers in computer science.| \n"
              " -------------------------------------------- \n"
           << endl;
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

void Interface:: update(){

    cout << endl;
    cout << "Choose an action: \n"
            "1) Update a pioneer \n"
            "2) Update a computer \n"<<endl;

    cout << "Your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:updatePioneers();
        break;
    case 2:updateComputers();
        break;
    default:
        break;
    }

}
void Interface:: updateComputers(){

    cout <<endl;
    cout <<"==== Update computers ===="<<endl;

    QSqlQuery getq = ComputerScientists.getComputers();
    ComputerScientists.printComputerTable(getq);
    cout << "Enter row number: ";
    int row;
    cin >> row;
    QSqlQuery updateQ = ComputerScientists.getComputers();
    ComputerScientists.updateComputer(row,updateQ);

}

void Interface:: updatePioneers(){


    cout <<endl;
    cout <<"==== Update pioneers ===="<<endl;

    QSqlQuery getq = ComputerScientists.getPersons();
    ComputerScientists.printTable(getq);
    cout << "Enter row number: ";
    int row;
    cin >> row;
    QSqlQuery updateQ = ComputerScientists.getPersons();
    ComputerScientists.updatePioneer(row,updateQ);

}

void Interface::view(){

    //if(ComputerScientists.databaseEmpty()) return;
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

void Interface::viewOptions(int choice){

    cout << "Write 0 to view as list, 1 to view as Table" << endl;
    int view;
    cin >> view;

    QSqlQuery c = ComputerScientists.getComputers();
    QSqlQuery p = ComputerScientists.getPersons();
    QSqlQuery q = ComputerScientists.getConnections();
    cout << endl;

    if(choice == 1){
        cout <<"==== Database ===="<<endl;
        if(view == 0){
            ComputerScientists.printList(p);
        }
        else if(view == 1){
            ComputerScientists.printTable(p);
        }
    }
    else if(choice == 2){

        cout <<"==== Computer database ===="<<endl;

        if(view == 0){
            ComputerScientists.printComputerList(c);
        }

        else if(view == 1){
            ComputerScientists.printComputerTable(c);
        }

    }
    else {
        cout <<"==== Overview of connections ===="<<endl;

        if(view == 0){
            ComputerScientists.printConnectionsList(c);
        }

        else if(view == 1){
            ComputerScientists.printConnectionsTable(q);
        }

    }

}

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
    cout << "Write 0 to view as list, 1 to view as Table" << endl;
    int view;
    cin >> view;
    cout <<"==== Database ===="<< endl;
    ComputerScientists.showOrdered(choice, column, order, view);

}
void Interface::find(){

    if(ComputerScientists.databaseEmpty()) return;

    cout << endl;
    cout <<"==== Search ===="<<endl;
    cout << "a) Last Name "<<endl;
    cout << "b) Sex " << endl;
    cout << "c) Year of birth " << endl;
    cout << "d) Year of death " << endl;
    cout << "Search by: ";

    ComputerScientists.search();
}
void Interface::add(){

    int answer = 'y';
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
        case 1: cout << "===== Add a pioneer =====" << endl;
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

            if(born <= died) {
                person pers;
                pers.setFirstName(firstname);
                pers.setLastName(lastname);
                pers.setSex(sex);
                pers.setBorn(born);
                pers.setDied(died);

                ComputerScientists.addData(pers);
            } else {
                cout << "Invalid input: Birth year > death year" << endl;
            }
            answer = ComputerScientists.ask_again();
        };
        break;
        case 2: cout << "===== Add a computer =====" << endl;
        while(answer == 'y' || answer == 'Y'){

            string name, type;
            int year;
            bool made;
            cin.ignore(1);
            cout << "Computer name: ";
            getline(cin, name);
            cout << "Computer type: ";
            getline(cin, type);
            cout << "Year made(0 if not made): ";
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

            ComputerScientists.addComp(comp);
            answer = ComputerScientists.ask_again();
        };
        break;
        case 3: cout << "===== Add a connection =====" << endl;
        while(answer == 'y' || answer == 'Y'){
            QSqlQuery p = ComputerScientists.getPersons();
            QSqlQuery c = ComputerScientists.getComputers();
            ComputerScientists.printTable(p);
            ComputerScientists.printComputerTable(c);

            //CHECK IF ID'S exist
            string firstName, lastName, computerName;
            cout << "Lastname of person: ";
            cin.ignore(1);
            getline(cin, lastName);
            cout << "First name: ";
            getline(cin, firstName);

            cout << "Name of cpu: ";
            getline(cin, computerName);

            ComputerScientists.addConnection(firstName, lastName, computerName);
            answer = ComputerScientists.ask_again();
        };
        break;
    }



}

void Interface:: discover(){

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
    ComputerScientists.discover(1);
}

void Interface::discoverPioneer(){

    cout << "==== Discover a pioneer ===="<<endl;
    if(ComputerScientists.databaseEmpty()) return;
    ComputerScientists.discover(0);
}

void Interface:: askToDelete(){

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

    QSqlQuery p = ComputerScientists.getPersons(); 
    ComputerScientists.printTable(p);

    cout << "==== Remove a pioneer ===="<<endl;
    cout << "Type last name: ";
    ComputerScientists.removeCharacter();
}

void Interface:: deleteComputer(){

    if(ComputerScientists.computersDatabaseEmpty()) return;

    QSqlQuery c = ComputerScientists.getComputers();
    ComputerScientists.printComputerTable(c);
    cout << "==== Remove Computer ===="<<endl;

    cout << "Type name of computer: ";
     ComputerScientists.removeComputer();


}


void Interface:: deleteConnection(){
    cout << "==== Remove Connection ===="<<endl;
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

void Interface::quit() {
    ComputerScientists.closeDatabase();
}
