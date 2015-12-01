#include <iostream>
#include "list.h"
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

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
        string firstname;
        string lastname;
        string sex;
        int born;
        int died;
        while ( in_stream >> firstname >> lastname >> sex >> born >> died){

            person addPerson;
            addPerson.setFirstName(firstname);
            addPerson.setLastName(lastname);
            addPerson.setSex(sex);
            addPerson.setBorn(born);
            addPerson.setDied(died);

            characters.push_back(addPerson);

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

        characters.push_back(newPerson);
        newEntries.push_back(newPerson);

        answer = ask_again();
    }

    writeToFile(newEntries);
}

void List:: writeToFile(vector <person>& p){


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

void List::printList(vector <person>& p){

    cout <<"==== DATABASE ===="<<endl;
    for (unsigned int i = 0; i < p.size(); i++){
        cout << p.at(i) << endl;
    }
}

bool List::databaseEmpty() {

    if(this->characters.size() == 0){
        cout << "Database empty - start by adding a pioneer."<< endl;
        return true;
    }
    return false;
}

void List::printTable(vector <person>& p) {

    cout <<"==== DATABASE ===="<<endl;
    tableBegin();

    const char separator    = ' ';
    const int nameWidth     = 15;
    const int numWidth      = 15;
    const int genderWidth   = 10;

    for (unsigned int i = 0; i< p.size(); i++) {

          person pers = p[i];

          cout << left << setw(5) << setfill(separator) << i+1;
          cout << left << setw(nameWidth) << setfill(separator) << pers.getLastName();
          cout << left << setw(nameWidth) << setfill(separator) << pers.getFirstName();
          cout << left << setw(genderWidth) << setfill(separator) << pers.getSex();
          cout << left << setw(numWidth) << setfill(separator) << pers.getBorn();
          if(pers.getDied() != 0)
              cout << left << setw(numWidth) << setfill(separator) << pers.getDied();
          else
              cout << left << setw(numWidth) << setfill(separator) << " - ";
          cout << endl;
     }

     cout << endl;
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

void List::showOrdered(int column, int order, int format){
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

   if(format == 0)
        printList(p);
    else
        printTable(p);
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
    if(ask == 'a'||ask == 'b'||ask == 'c'||ask == 'd')
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

    for (unsigned int i = 0; i < characters.size(); i++){
        person comparePerson = characters[i];
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
        printTable(sResult);
    }

    cout <<  "Search again ?(y/n): ";
    char again;
    cin >> again;

    if(again == 'y'|| again == 'Y')
        search();
}

ostream& operator<< (ostream& stream,const List& p){

   for (unsigned int i = 0; i< p.characters.size(); i++) {
       person pers = p.characters[i];
       stream << pers;
       cout << "-----------------" << endl;
   }
   stream << endl;
   return stream;
}

void List:: discoverAPioneer(){

    cout << "==== Discover ===="<<endl;
    int sizeOfDatabase = characters.size();
    srand(time(0));
    int randomCharacter = (rand() % sizeOfDatabase);

    person randPers = returnPersonAtIndex(randomCharacter);
    cout << randPers<<endl;

}

person List:: returnPersonAtIndex(int index){

    person p = characters[index];
    return p;
}


void List:: removeCharacter(){

    cout << "Type last name: ";
    string name;
    cin >> name;

    for (unsigned int i = 0; i< characters.size(); i++) {
        person pers = characters[i];
        if (pers.getLastName() == name)
            characters.erase(characters.begin()+i);
    }

    OverWriteToFile(characters);


}

void List:: removeCharacterWithIndex(){

    int max = characters.size();

    if(max > 0){

        cout << "Type a number between 0 and " << max-1 << ": ";
        int removeIndex;
        cin >> removeIndex;

        if(removeIndex >= 0 && removeIndex < max){
            characters.erase(characters.begin()+removeIndex);
        }

        OverWriteToFile(characters);
    }
    else{
        cout << "Database is empty" << endl;
    }


}

void List:: OverWriteToFile(vector <person>& p){

    ofstream out_stream;
    out_stream.open("persons.txt");

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

void List:: tableBegin(){

    const char separator    = ' ';
    const int nameWidth     = 15;
    const int numWidth      = 15;
    const int genderWidth   = 10;

    cout << left << setw(5) << setfill(separator) << "Nr.";
    cout << left << setw(nameWidth) << setfill(separator) << "Last name";
    cout << left << setw(nameWidth) << setfill(separator) << "First name";
    cout << left << setw(genderWidth) << setfill(separator) << "Gender";
    cout << left << setw(numWidth) << setfill(separator) << "Year of birth";
    cout << left << setw(numWidth) << setfill(separator) << "Year of death";
    cout << endl;

    cout << left << setw(5) << setfill(separator) << "---";
    cout << left << setw(nameWidth) << setfill(separator) << "---------";
    cout << left << setw(nameWidth) << setfill(separator) << "---------";
    cout << left << setw(genderWidth) << setfill(separator) << "-----";
    cout << left << setw(numWidth) << setfill(separator) << "-------------";
    cout << left << setw(numWidth) << setfill(separator) << "-------------";
    cout << endl;

}

