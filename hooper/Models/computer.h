#ifndef COMPUTER
#define COMPUTER

#include <string>
#include <iostream>

using namespace std;

class computer
{
public:
    computer();
    computer(string name, string type, int yearMade, bool wasMade);
    void initialize();
    friend ostream& operator << (ostream& stream,const computer& c);
    string getName() const;
    int getYearMade() const;
    string getType() const;
    bool getWasMade() const;
    void setName(string n);
    void setYearMade(int ym);
    void setType(string t);
    void setWasMade(bool wm);

private:
    int year;
    bool made;
    string name;
    string type;
};

#endif // COMPUTER

