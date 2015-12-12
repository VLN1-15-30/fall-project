#ifndef INTERFACE
#define INTERFACE

#include <string>
#include <iostream>
#include "Services/list.h"

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
    void personTableBegin();
    void computerTableBegin();
    void connectionsTableBegin();
    void printComputerTable(vector<computer>& c);
    void printPersonTable(vector<person>& p);
    void printConnectionTable(vector<connection>& c);
    void performSearchBasedOn(const char& selection, string& table);
    void search(string table);
    void removeComputer();
    void removeCharacter();
    void updatePioneer(int row, vector<person>& p);
    void updateComputer(int row, vector<computer> &p);
    void updateConnections(string firstName, string lastName, string computerName);
    void updateConnectionComputer(int personID, int computerID);
    void updateConnectionPerson(int personID, int computerID);
    void quit();

private:
    List ComputerScientists;

};

#endif // INTERFACE



