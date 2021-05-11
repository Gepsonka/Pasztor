#ifndef ENOR_H
#define ENOR_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

enum Status {norm, abnorm};

struct Sor{
        string nickname;
        char type;
        int num;

        friend istream& operator>>(istream& is, Sor& s);
};

class Enor
{
    public:
        enum Exception {OPEN_ERROR};
        Enor(const string &filename);
        ~Enor() { _x.close(); }

        void first() { next(); }
        void next() { read(); }
        Sor current() const { return _dx; }
        bool end() const { return _sx==abnorm; }
        void readfirstline();

    private:
        ifstream _x;
        Sor _dx;
        Status _sx;

        void read();

    protected:

    private:
};

#endif // ENOR_H
