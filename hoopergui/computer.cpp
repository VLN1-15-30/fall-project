#include "computer.h"
#include <assert.h>

using namespace std;

computer::computer(){

    year = 0;
    made = 0;
    name = "";
    type = "";
}

string computer::getName() const{
    return name;
}

string computer::getType() const{
    return type;
}

int computer::getYearMade() const{
    return year;
}

bool computer::getWasMade() const{
    return made;
}

void computer::setName(string n){
    name = n;
}

void computer::setType(string t){
    type = t;
}

void computer::setYearMade(int ym){
    year = ym;
}

void computer::setWasMade(bool wm){
    made = wm;
}

void computer::initialize(){
    cout << "Name of the computer: ";
    cin >> name;
    cout << "Computer type: ";
    cin >> type;
    cout << "Year built: ";
    cin >> year;
    cout << "Was the computer made: ";
    cin >> made;
}

ostream& operator << (ostream& stream,const computer& c){

    stream << "Computer name: " << c.name << endl;
    stream << "Computer type: " << c.type << endl;
    stream << "Year built: " << c.year << endl;
    if(c.made == true){
         stream << "Was it made: YES" <<endl;
    }
    else{
         stream << "Was it made: NO" <<endl;
    }
    return stream;
}

