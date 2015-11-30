#include <QCoreApplication>
#include <iostream>
#include "list.h"
#include "interface.h"
#include <vector>

using namespace std;

int main()
{
    Interface welcome;
    welcome.welcomeMessage();
    List str1;
    str1.initialize("persons.txt");
    str1.showList();
    str1.addData();
    //order list

//    int column;
//    int order;
//    cout << "Write 0 for Name order, 1 for Born order" << endl;
//    cin >> column;
//    cout << "Write 0 for ascending, 1 for descending order" << endl;
//    cin >> order;
//    str1.showOrderedList(column, order);
    str1.search();



    return 0;
}

