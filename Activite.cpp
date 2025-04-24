#include "Activite.h"


Activite::Activite() : typeActivite("Inconnu") {}

Activite::Activite(string type) : typeActivite(type) {}

string Activite::getTypeActivite()  {
    return typeActivite;
}

void Activite::setTypeActivite(string type) {
    typeActivite = type;
}
void Activite::afficher(){
    cout<<"Type activite : "<<typeActivite;
}

Activite::~Activite() {}
