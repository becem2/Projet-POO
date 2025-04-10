#include "Babysitter.h"

BabySitter::BabySitter(string n, int a, string tel, double salaire) : nom(n), age(a), numeroTelephone(tel), salaireHoraire(salaire) {}


void BabySitter::afficherInfos() const {
cout << "Nom: " << nom << "\n"
     << "Age: " << age << " ans\n"
     << "Téléphone: " << numeroTelephone << "\n"
     << "Salaire horaire: " << salaireHoraire << " €/h\n";
}

void BabySitter::surveillerEnfant() {
cout << nom << " surveille un enfant.\n";
}