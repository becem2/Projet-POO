#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;
class Activite {
    private:
        string typeActivite;
    public:
        Activite();
        Activite(string type);
        Activite(const Activite&);
        ~Activite();
        string getTypeActivite() ;
        void setTypeActivite(string);
        void afficher();
        friend istream& operator>>(istream&, Activite&);
        friend ostream& operator<<(ostream&, Activite&);
    };