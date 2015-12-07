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
            "Choose 5 to discover a random computer. \n"
            "Choose 6 to remove a pioneer from the database. \n"
            "Choose 7 to remove a computer from the database."<< endl;


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
        case 5: discoverComputer();
        break;
        case 6: deleteCharacter();
        break;
        case 7: deleteComputer();
        break;
    }
}
void Interface::view(){

    //if(ComputerScientists.databaseEmpty()) return;
    int choice;
    cout << "Choose 1 to view pioneers \n"
            "Choose 2 to view computers \n"
            "Choose 3 to view connections between pioneers and computers" << endl;
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

    if(choice == 1){
        vector<person> p = ComputerScientists.getChar();

        if(view == 0){
            ComputerScientists.printList(p);
        }
        else if(view == 1){
            ComputerScientists.printTable(p);
        }
    }
    else if(choice == 2){
        vector<computer>c = ComputerScientists.getComputers();

        if(view == 0){
            ComputerScientists.printComputerList(c);
        }

        else if(view == 1){
            ComputerScientists.printComputerTable(c);
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
    }
    cout << "Write 0 for ascending order, 1 for descending order" << endl;
    cin >> order;
    cout << "Write 0 to view as list, 1 to view as Table" << endl;
    int view;
    cin >> view;

    ComputerScientists.showOrdered(choice, column, order, view);

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

void Interface::discoverComputer(){

    cout << "==== Discover a Computer ===="<<endl;

    if(ComputerScientists.databaseEmpty()) return;
    ComputerScientists.discover(1);
}

void Interface::discover(){

    cout << "==== Discover ===="<<endl;
    if(ComputerScientists.databaseEmpty()) return;
    ComputerScientists.discover(0);
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

void Interface:: deleteComputer(){

    if(ComputerScientists.computersDatabaseEmpty()) return;

    vector<computer> c = ComputerScientists.getComputers();
    ComputerScientists.printComputerTable(c);
    cout << "==== REMOVE COMPUTER ===="<<endl;
    cout << "Write 0 to remove by index, 1 to remove by name"<<endl;
    int type;
    cin >> type;
    if (type == 0)
        ComputerScientists.removeComputerWithIndex();
    else if (type == 1)
         ComputerScientists.removeComputer();


}
