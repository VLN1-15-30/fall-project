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
    void findComputers();
    void findPioneers();
    void add();
    void addPioneer(char answer);
    void addComputer(char answer);
    void addConnection(char answer);
    void discover();
    void discoverComputer();
    void discoverPioneer();
    void update();
    void updateComputers();
    void updatePioneers();
    void updateConnections();
    void askToDelete();
    void deleteComputer();
    void deleteCharacter();
    void deleteConnection();
    void viewOptions(int choice);
    void showUsage();
    void quit();

private:
    List ComputerScientists;

};

#endif // INTERFACE


