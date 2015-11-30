#include <iostream>
#include "list.h"
#include <algorithm>
using namespace std;

List::List(){

}

void List:: initialize(string fileName ){

    ifstream in_stream;

    in_stream.open(fileName.c_str());

    if (in_stream.fail( ))
    {
        cout << "Failed to open database."<<endl;
    }
    else{
        string name;
        string sex;
        int born;
        int died;
        while ( in_stream >> name >> sex >> born >> died){

            cout << name<<" " << sex << " " << born<<" " << died <<" " << endl;

            person addPerson;
            addPerson.setName(name);
            addPerson.setSex(sex);
            addPerson.setBorn(born);
            addPerson.setDied(died);

            charachters.push_back(addPerson);
            numberOfEntries++;

        }
    }

     in_stream.close();
}


void List::addData(){

    int answer = 'y';
    cout << "===== ADD PERSONS =====" << endl;

    while (answer == 'y'|| answer == 'Y') {

        person newPerson;
        newPerson.initialize();

        charachters.push_back(newPerson);
        newEntries.push_back(newPerson);

        addedEntries++;
        answer = ask_again();
    }

    writeToFile(newEntries);
}

void List:: writeToFile(vector <person>& p){

    totalEntries = addedEntries+ numberOfEntries;

    ofstream out_stream;
    out_stream.open("persons.txt", ios::app);
    if (out_stream.fail( ))
    {
        cout << "Failed to write to database."<<endl;
        return;
    }

    for (unsigned int i = 0; i< p.size(); i++) {
        person pers = p[i];
          out_stream << pers.getName()<<" "<<pers.getSex() <<" "<< pers.getBorn()<<" "<< pers.getDied() << endl;
    }

    out_stream.close( );

}

void List::showList() const{
    cout << *this;
}

void List::orderbyNameA_Z(vector <person>& p){
    sort(p.begin(), p.end(),EntityComp(NAME, 0));
}

void List::orderbyNameZ_A(vector <person>& p){
    sort(p.begin(), p.end(),EntityComp(NAME, 1));
}

void List::orderbyBornASC(vector <person>& p){
    //use stable to preserve order of equivalents
    stable_sort(p.begin(), p.end(),EntityComp(BORN, 0));
}

void List::orderbyBornDESC(vector <person>& p){

    stable_sort(p.begin(), p.end(),EntityComp(BORN, 1));
}

void List::showOrderedList(int column, int order){
   vector<person> p = getChar();
   if(column == NAME) {
       if( order == 0) {
           orderbyNameA_Z(p);
       } else {
           orderbyNameZ_A(p);
       }
   } else if (column == BORN) {
       if( order == 0) {
           orderbyBornASC(p);
       } else {
           orderbyBornDESC(p);
       }
   }

   for (unsigned int i = 0; i < p.size(); i++){
       cout << p.at(i) << endl;
   }
}

char List:: ask_again(){

    char answer;
    cout << "Add another person? (y/n)"<< endl;
    cin >> answer;

    return answer;
}


ostream& operator<< (ostream& stream,const List& p){

   for (unsigned int i = 0; i< p.charachters.size(); i++) {
       person pers = p.charachters[i];
       stream << pers;
       cout << "-----------------" << endl;
   }
   stream << endl;
   return stream;
}
