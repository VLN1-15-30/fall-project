#ifndef PERSON
#define PERSON

#include <string>
#include <iostream>
#include <vector>
#include <columns.h>

using namespace std;

class person
{
public:
    person();
    void initialize();
    //friend istream& operator>> (istream& stream,const person& p);
    friend ostream& operator<< (ostream& stream,const person& p);
    string getName() const;
    string getSex() const;
    int getBorn() const;
    int getDied() const;

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
// sort person by certain column and order
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
                return p1.getName() < p2.getName();
            } else {
                return p1.getName() > p2.getName();
            }
        } else{
            if(sort == BORN) {
                return p1.getBorn() < p2.getBorn();
            } else {
                return p1.getBorn() > p2.getBorn();
            }
        }
    }
};


#endif // PERSON
