#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Activite {
private:
    string typeActivite;

public:
    Activite();
    Activite(string type);
    string getTypeActivite() ;
    void setTypeActivite(string type);
    void afficher();
    ~Activite();
};
