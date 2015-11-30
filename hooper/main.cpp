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

    return 0;
}

