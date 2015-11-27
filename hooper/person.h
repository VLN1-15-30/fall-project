#ifndef PERSON
#define PERSON

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class person
{
public:
    person();
    void initialize();
    //friend istream& operator>> (istream& stream,const person& p);
    friend ostream& operator<< (ostream& stream,const person& p);
    void showList() const;
    string getName();
    string getSex();
    int getBorn();
    int getDied();

    void setName(string n);
    void setSex(string s);
    void setBorn(int b);
    void setDied(int d);


private:
    int born;
    int died;
    string name;
    string sex;

};

#endif // PERSON
