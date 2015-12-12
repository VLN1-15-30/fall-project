#ifndef PERSON
#define PERSON

#include <string>
#include <iostream>

int const NAME = 0;
int const BORN = 1;

using namespace std;

class person
{
public:
    person();
    person(string firstName, string lastName, string sex, int yearBorn, int yearDied );
    void initialize();
    friend ostream& operator<< (ostream& stream,const person& p);
    string getFirstName() const;
    string getLastName() const;
    string getSex() const;

    int getBorn() const;
    int getDied() const;

    void setFirstName(string fn);
    void setLastName(string ln);
    void setSex(string s);
    void setBorn(int b);
    void setDied(int d);

    string errorCheckSex(string& sex);
    int errorCheckNumber(int& number, int index);

private:
    int born;
    int died;
    string firstname;
    string lastname;
    string sex;

};

#endif // PERSON
