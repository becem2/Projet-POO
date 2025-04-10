#pragma once
#include <iostream>
#include <string>

using namespace std;

class BabySitter {
protected:
    string nom;
    int age;
    string numeroTelephone;
    double salaireHoraire;

public:
    
    BabySitter(string n, int a, string tel, double salaire);

    
    virtual void afficherInfos() const ;

    virtual void surveillerEnfant() ;

  
    virtual ~BabySitter() {}
};