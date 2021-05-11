#include "Enor.h"

Enor::Enor(const string &filename)
{
    _x.open(filename);
    if(_x.fail()) throw OPEN_ERROR;
}

istream& operator>>(istream& is, Sor& s) {
    is >> s.nickname >> s.type >> s.num;
    return is;
}

void Enor::read()
{
    _sx = (_x >> _dx) ? norm : abnorm;
}

void Enor::readfirstline(){
    string firstline;
    _sx = getline(_x,firstline) ? norm : abnorm;
}
