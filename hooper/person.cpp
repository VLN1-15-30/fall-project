#include "person.h"
#include <assert.h>

using namespace std;

person::person(){

    born = 0;
    died = 0;
    firstname = "";
    lastname ="";
    sex = "";
}

string person:: getFirstName() const{

    return firstname;
}

string person:: getLastName() const{

    return lastname;
}


int person:: getBorn() const{
    return born;
}

int person:: getDied() const{
    return died;
}

string person:: getSex() const{
    return sex;
}

void person:: setFirstName(string fn){
    firstname = fn;
}

void person:: setLastName(string ln){
    lastname = ln;
}

void person:: setSex(string s){
    sex = s;
}

void person:: setBorn(int b){
    born = b;
}

void person:: setDied(int d){

    died = d;
}


void person::initialize(){

    cout << "First name: ";
    cin >> firstname;
    cout << "Last name: ";
    cin >> lastname;
    cout << "Sex(m/f): ";
    cin >> sex;
    sex = errorCheckSex(sex);
    cout << "Born: ";
    cin >>born;
    born = errorCheckNumber(born,0);
    cout << "Died: ";
    cin >> died;
    died = errorCheckNumber(died,1);
    cout << endl;

}

int person:: errorCheckNumber(int &number, int index){

    while (number <=999 || number > 2015){

        cout << "Invalid input, try again"<< endl;
        if(index == 0)
            cout << "Born: ";
        else
            cout << "Died: ";

        cin >> number;

        if(number > 999 && number < 2015)
            break;
    }

    return number;

}

string person:: errorCheckSex(string& sex){

    if(sex == "m" || sex == "f")
        return sex;

    while (sex != "m" || sex != "f"){

        cout << "Invalid input, try again"<< endl;
        cout << "Sex(m/f): ";
        cin >> sex;

        if(sex == "m" || sex == "f")
            break;
    }

    return sex;

}

//bool operator <(const person& p1,const person& p2){
//    if(p1.getName() < p2.getName())
//        return true;
//    else
//        return false;
//}

ostream& operator<< (ostream& stream,const person& p){

   stream << "First name: "<< p.firstname<<endl;
   stream << "Last name: "<< p.lastname<<endl;
   stream << "Sex: "<< p.sex<<endl;
   stream << "Born: "<< p.born<<endl;
   stream << "Died: "<< p.died<<endl;

   return stream;
}
