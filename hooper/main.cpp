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

    int exit = 0;

    while(exit != 1) {
        welcome.actions();
        cout << "Press 1 to quit or 0 to make more actions" << endl;
        cin >> exit;
    }
    return 0;
}

