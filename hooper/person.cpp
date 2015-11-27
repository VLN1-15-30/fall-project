#include "person.h"

using namespace std;

person::person(){

    born = 0;
    died = 0;
    name = "";
    sex = "";
}

string person:: getName(){

    return name;
}

int person:: getBorn(){
    return born;
}

int person:: getDied(){
    return died;
}

string person:: getSex(){
    return sex;
}

void person:: setName(string n){
    name = n;
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

    cout << "Name: ";
    cin >> name;
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

void person::showList() const{
    cout << *this;
}

ostream& operator<< (ostream& stream,const person& p){

   stream << "Name: "<< p.name<<endl;
   stream << "Sex: "<< p.sex<<endl;
   stream << "Born: "<< p.born<<endl;
   stream << "Died: "<< p.died<<endl;

   return stream;
}
