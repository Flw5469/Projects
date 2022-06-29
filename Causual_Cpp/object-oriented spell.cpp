#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
protected:
    int power;
public: 
    Spell() : power(0) { };
    virtual void multiply() {};
    void print() { cout << "power is " << power; };

};

class a : public Spell {
public:
    a(int powerinput) {
        power = powerinput;
        cout << "this is a !" << endl;
    };
    void multiply() {
        power *= 2;
    };
};

class b : public Spell {
public:
    b(int powerinput) {
        power = powerinput;
        cout << "this is b !" << endl;
    };
    void multiply() {
        power *= 5;
    };
};

class c : public Spell {
public:
    c(int powerinput) {
        power = powerinput;
        cout << "this is c !" << endl;
    };
    void multiply() {
        power *= 10;
    };
};


class Wizard {
public:
    Spell* cast() {
        string Spname;
        int power;
        cout << "input name: ";
        cin >> Spname;
        cout << "input power ";
        cin >> power;
        Spell *casting= new Spell();
        if (Spname == "a") { casting = new a(power); };
        if (Spname == "b") { casting = new b(power); };
        if (Spname == "c") { casting = new c(power); };
        return casting;
    }
    ;

};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--) {
        Spell* spell = Arawn.cast();
        spell->Spell::multiply();
        spell->print();
        spell->multiply();
        spell->print();
        //counterspell(spell);
    }
    return 0;
}