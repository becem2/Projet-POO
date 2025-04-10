#include "creche.h"



void Creche::ajouterEnfant(Enfant* enfant) {
    enfants.push_back(enfant);
}

void Creche::afficherEnfants() const {
    for (const auto& enfant : enfants) {
        enfant->afficher();
        cout << "------------------------\n";
    }
}

Enfant* Creche::rechercherEnfant(const string& nom, const string& prenom) const {
    for (const auto& enfant : enfants) {
        if (enfant->getNom() == nom && enfant->getPrenom() == prenom) {
            return enfant;
        }
    }
    return nullptr;
}

int Creche::compterEnfantsEnPermanence() const {
    int count = 0;
    for (const auto& enfant : enfants) {
        if (dynamic_cast<EnfantEnPermanence*>(enfant)) {
            count++;
        }
    }
    return count;
}

void Creche::supprimerEnfant(const string& nom, const string& prenom) {
    for (auto it = enfants.begin(); it != enfants.end(); ++it) {
        if ((*it)->getNom() == nom && (*it)->getPrenom() == prenom) {
            delete *it;
            enfants.erase(it);
            cout << "L'enfant " << nom << " " << prenom << " a été supprimé.\n";
            return;
        }
    }
    cout << "Enfant non trouvé.\n";
}


Creche::~Creche() {
    for (auto enfant : enfants)
        delete enfant;
}
