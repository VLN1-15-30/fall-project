#include <iostream>
#include "interface.h"

using namespace std;

int main()
{
    Interface hooper;
    hooper.welcomeMessage();

    int exit = 0;

    while(exit != 1) {
        hooper.actions();
        cout << "Press 1 to quit or 0 to choose more actions" << endl;
        cin >> exit;
    }
    return 0;
}

