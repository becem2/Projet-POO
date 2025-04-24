#include "Activitesupp.h"
ActiviteSupplementaire::ActiviteSupplementaire() {}
ActiviteSupplementaire::ActiviteSupplementaire(string nom){}
ActiviteSupplementaire::~ActiviteSupplementaire() {}
void ActiviteSupplementaire::afficher()  {
    cout << "Activite Supplementaire : " << nomActivite << endl;
}