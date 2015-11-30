#include <iostream>
#include "interface.h"
#include <algorithm>
using namespace std;

Interface::Interface(){

}
void Interface::welcomeMessage(){
    cout << "Welcom to the Hooper database!\n"
            "The database contains information about pioneers in computer science.\n"
            "Choose a number for your next action:" << endl;
}
