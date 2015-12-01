#include <iostream>
#include "interface.h"
#include <algorithm>
using namespace std;


Interface::Interface(){
    ComputerScientists.initialize("persons.txt");
}
void Interface::welcomeMessage(){
    cout << "Welcome to the Hooper database!\n"
            "The database contains information about pioneers in computer science." << endl;
}
void Interface::actions(){
    cout << "Choose a number for your next action: \n"
            "Choose 1 to view the database. \n"
            "Choose 2 to search the database. \n"
            "Choose 3 to add a pioneer to the database. \n"
            "Choose 4 to discover a random pioneer."<< endl;

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
    }
}
void Interface::view(){
    char answer;
    cout << "Do you wish to control the order of the data(y/n)? ";
    cin >> answer;
    switch(answer){
        case 'Y':
        case 'y':order();
        break;
        case 'N':
        case 'n': ComputerScientists.showList();
        break;
    }
}
void Interface::order(){
    int column;
    int order;
    cout << "Write 0 to order by Name, 1 to order by Born" << endl;
    cin >> column;
    cout << "Write 0 for ascending order, 1 for descending order" << endl;
    cin >> order;
    ComputerScientists.showOrderedList(column, order);
}
void Interface::find(){
    ComputerScientists.search();
}
void Interface::add(){
    ComputerScientists.addData();
}

void Interface::discover(){

    ComputerScientists.disvoverAPioneer();
}
