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
    cout << endl;
    cout << "Last name: ";
    cin >> lastname;
    cout << endl;
    cout << "Sex: ";
    cin >> sex;
    cout << endl;
    cout << "Born: ";
    cin >>born;
    cout << endl;
    cout << "Died: ";
    cin >> died;
    cout << endl;

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
