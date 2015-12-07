#ifndef INTERFACE
#define INTERFACE

#include <string>
#include <iostream>
#include <list.h>

using namespace std;

class Interface{
public:
    Interface();
    void welcomeMessage();
    void actions();
    void view();
    void order();
    void find();
    void add();
    void discover();
    void discoverComputer();
    void deleteComputer();
    void deleteCharacter();
    void viewOptions();
private:
    List ComputerScientists;

};

#endif // INTERFACE



