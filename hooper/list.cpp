#include <iostream>
#include "list.h"
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum Types{
    search_name,
    search_born
};

Types searchType;

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
        string firstname;
        string lastname;
        string sex;
        int born;
        int died;
        while ( in_stream >> firstname >> lastname >> sex >> born >> died){

           // cout << firstname<<" " << lastname << " "
             //    << sex << " " << born<<" " << died <<" " << endl;

            person addPerson;
            addPerson.setFirstName(firstname);
            addPerson.setLastName(lastname);
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
    cout << "===== ADD A PIONEER =====" << endl;

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
          out_stream << pers.getFirstName()<<" " << pers.getLastName() << " "
                     << pers.getSex() <<" " << pers.getBorn()<<" "
                     << pers.getDied() << endl;
    }

    out_stream.close( );

}

void List::printData(vector <person>& p){

    for (unsigned int i = 0; i < p.size(); i++){
        cout << p.at(i) << endl;
    }
}

void List::showList() const{
    cout <<"==== DATABASE ===="<<endl;
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
   cout <<"==== DATABASE ===="<<endl;
   printData(p);
}

char List:: ask_again(){

    char answer;
    cout << "Add another person? (y/n)"<< endl;
    cin >> answer;

    return answer;
}



void List::search(){

    cout << endl;
    cout <<"==== Search ===="<<endl;
    cout <<"a: Last Name "<<endl;
    cout << "b: Sex " << endl;
    cout << "c: Year of birth " << endl;
    cout << "d: Year of death " << endl;

    cout << "Search by: ";

    char ask;
    cin >> ask;

    performSearchBasedOn(ask);
}

void List:: performSearchBasedOn(const char& selection){

    switch(selection){
        case 'a':cout << "Last name: ";
        break;
        case 'b': cout << "m/f: ";
        break;
        case 'c': cout << "Enter year: ";
        break;
        case 'd': cout << "Enter year: ";
        break;
    }

    string target;
    cin >> target;

    vector <person> sResult;

    for (unsigned int i = 0; i < charachters.size(); i++){
        person comparePerson = charachters[i];
        switch (selection) {
        case 'a':{
            if(comparePerson.getLastName().find(target)!=string::npos){
                sResult.push_back(comparePerson);
            }
        }
        break;
        case 'b':{
            if(comparePerson.getSex().find(target)!=string::npos){
                sResult.push_back(comparePerson);
            }
        }
        break;
        case 'c':{

             ostringstream ss;
              ss << comparePerson.getBorn();
            if(ss.str().find(target)!=string::npos){
                sResult.push_back(comparePerson);
            }
        }
        break;
        case 'd':{
            ostringstream ss;
             ss << comparePerson.getDied();
            if(ss.str().find(target)!=string::npos){
                sResult.push_back(comparePerson);
            }
        }
        break;
        default:
            break;
        }

    }

    if(sResult.size() == 0){
        cout << "No match found for "<<target << endl;
    }
    else{
        cout <<endl;
        cout << "Found the following results: "<< endl;

        orderbyNameA_Z(sResult);
        printData(sResult);
    }

    cout <<  "Search again ?(y/n): ";
    char again;
    cin >> again;

    if(again == 'y'|| again == 'Y')
        search();
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

void List:: disvoverAPioneer(){

    cout << "==== Discover ===="<<endl;
    int sizeOfDatabase = charachters.size();
    srand(time(0));
    int randomCharacter = (rand() % sizeOfDatabase);

    person randPers = returnPersonAtIndex(randomCharacter);
    cout << randPers<<endl;

}

person List:: returnPersonAtIndex(int index){

    person p = charachters[index];
    return p;
}

