#include <QCoreApplication>
#include <iostream>
#include "list.h"

using namespace std;

int main(int argc, char *argv[])
{
    List str1;
    str1.initialize("persons.txt");
    str1.addData();
    cout << str1;
    return 0;
}

