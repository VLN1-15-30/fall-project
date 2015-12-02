#ifndef PERSON
#define PERSON

#include <string>
#include <iostream>
#include <vector>

int const NAME = 0;
int const BORN = 1;

using namespace std;

class person
{
public:
    person();
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
// sort person by certain column and order
// based on tutorial http://www.walletfox.com/course/sortvectorofcustomobjects.php
struct EntityComp{
    int column;
    int sort;
    EntityComp(int column, int sort){
        this->column = column;
        this->sort = sort;
    }
    bool operator ()(const person& p1,const person& p2) const {
        if(column == NAME){
            if(sort == 0) {
                return p1.getLastName() < p2.getLastName();
            } else {
                return p1.getLastName() > p2.getLastName();
            }
        } else{
            if(sort == BORN) {
                return p1.getBorn() > p2.getBorn();
            } else {
                return p1.getBorn() < p2.getBorn();
            }
        }
    }
};


#endif // PERSON
