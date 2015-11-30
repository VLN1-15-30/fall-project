#include <iostream>
#include "interface.h"
#include <algorithm>
using namespace std;

List str1;
Interface::Interface(){

}
void Interface::welcomeMessage(){
    cout << "Welcom to the Hooper database!\n"
            "The database contains information about pioneers in computer science." << endl;
}
void Interface::actions(){
    cout << "Choose a number for your next action: \n"
            "Choose 1 to view the database. \n"
            "Choose 2 to search the database. \n"
            "Choose 3 to add a pioneer to the database." << endl;
    int action;
    cin >> action;
    switch(action){
        case 1: view();
        break;
        case 2: find();
        break;
        case 3: add();
        break;
    }
}
void Interface::view(){
    char answer;
    cout << "Do you whish to control the order of the data(Y/N)? ";
    cin >> answer;
    switch(answer){
        case 'Y': order();
        break;
        case 'N': List list;
                  list.showList();
        break;
    }
}
void Interface::order(){
    int column;
    int order;
    cout << "Write 0 to order by Name, 1 to order by Born" << endl;
    cin >> column;
    cout << "Write 0 for ascending, 1 for descending order" << endl;
    cin >> order;
        str1.showOrderedList(column, order);
}
void Interface::find(){
    List searching;
    searching.search();
}
void Interface::add(){
    List add;
    add.addData();
}
