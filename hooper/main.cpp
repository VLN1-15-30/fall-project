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
    welcome.actions();

    return 0;
}

