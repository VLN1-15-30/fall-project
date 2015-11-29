#include "person.h"
#include <assert.h>

using namespace std;

person::person(){

    born = 0;
    died = 0;
    name = "";
    sex = "";
}

string person:: getName() const{

    return name;
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

//bool operator <(const person& p1,const person& p2){
//    if(p1.getName() < p2.getName())
//        return true;
//    else
//        return false;
//}

ostream& operator<< (ostream& stream,const person& p){

   stream << "Name: "<< p.name<<endl;
   stream << "Sex: "<< p.sex<<endl;
   stream << "Born: "<< p.born<<endl;
   stream << "Died: "<< p.died<<endl;

   return stream;
}
