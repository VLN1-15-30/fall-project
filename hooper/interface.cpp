#include <iostream>
#include "interface.h"
#include <algorithm>

using namespace std;


Interface::Interface(){
    ComputerScientists.initialize();
}
void Interface::welcomeMessage(){
    cout << "Welcome to the Hooper database!\n"
            "The database contains information about pioneers and computers in computer science." << endl;
}
void Interface::actions(){
    cout << "Choose a number for your next action: \n"
            "Choose 1 to view the database. \n"
            "Choose 2 to search the database. \n"
            "Choose 3 to add to the database. \n"
            "Choose 4 to discover a random pioneer. \n"
            "Choose 5 to remove a pioneer from the database."<< endl;


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
        case 5: deleteCharacter();
        break;
    }
}
void Interface::view(){

    //if(ComputerScientists.databaseEmpty()) return;
    char answer;
    cout << "Do you wish to control the order of the data(y/n)? ";
    cin >> answer;
    switch(answer){
        case 'Y':
        case 'y':order();
        break;
        case 'N':
        case 'n': viewOptions();
        break;
    }
}

void Interface::viewOptions(){

    vector<person> p = ComputerScientists.getChar();
    cout << "Write 0 to view as list, 1 to view as Table" << endl;
    int view;
    cin >> view;
    if(view == 0)
        ComputerScientists.printList(p);
    else if(view == 1) {
        ComputerScientists.printTable(p);
     }
}

void Interface::order(){
    int column;
    int order;
    cout << "Write 0 to order by last name, 1 to order by birth year" << endl;
    cin >> column;
    cout << "Write 0 for ascending order, 1 for descending order" << endl;
    cin >> order;

    cout << "Write 0 to view as list, 1 to view as Table" << endl;
    int view;
    cin >> view;

    ComputerScientists.showOrdered(column, order, view);

}
void Interface::find(){
    if(ComputerScientists.databaseEmpty()) return;
    ComputerScientists.search();
}
void Interface::add(){

    int answer = 'y';
    int choice;
    cout << "Choose 1 to add a pioneer.\n"
            "Choose 2 to add a computer.\n"
            "Choose 3 to add a connection.\n";
    cin >> choice;
    switch(choice){
        case 1: cout << "===== ADD A PIONEER =====" << endl;
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

            person pers;
            pers.setFirstName(firstname);
            pers.setLastName(lastname);
            pers.setSex(sex);
            pers.setBorn(born);
            pers.setDied(died);

            ComputerScientists.addData(pers);
            answer = ComputerScientists.ask_again();
        };
        break;
        case 2: cout << "===== ADD A COMPUTER =====" << endl;
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
        case 3: cout << "===== ADD A CONNECTION =====" << endl;
        while(answer == 'y' || answer == 'Y'){

            //CHECK IF ID'S exist
            int pid, cid;
            cout << "ID of person: ";
            cin >> pid;
            cout << "ID of cpu: ";
            cin >> cid;

            ComputerScientists.addConnection(pid, cid);
            answer = ComputerScientists.ask_again();
        };
    }



}

void Interface::discover(){
    if(ComputerScientists.databaseEmpty()) return;
    ComputerScientists.discoverAPioneer();
}

void Interface::deleteCharacter(){
    if(ComputerScientists.databaseEmpty()) return;
    vector<person> p = ComputerScientists.getChar();
    ComputerScientists.printTable(p);
    cout << "==== REMOVE ===="<<endl;
    cout << "Write 0 to remove by index, 1 to remove by last name"<<endl;
    int type;
    cin >> type;
    if (type == 0)
        ComputerScientists.removeCharacterWithIndex();
    else if (type == 1)
         ComputerScientists.removeCharacter();
}
