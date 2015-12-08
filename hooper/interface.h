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
    void order(int choice);
    void find();
    void add();
    void discover();
    void discoverComputer();
    void updateComputers();
    void updatePioneers();
    void deleteComputer();
    void deleteCharacter();
    void deleteConnection();
    void viewOptions(int choice);
private:
    List ComputerScientists;

};

#endif // INTERFACE



