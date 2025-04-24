#include "EnfantPermenance.h"

EnfantPermanence::EnfantPermanence() : finPermanence("Inconnue") {}

EnfantPermanence::EnfantPermanence(string fin, string activiteNom) : finPermanence(fin) {
    activitessupp.push_back(ActiviteSupplementaire(activiteNom));
}

string EnfantPermanence::getFinPermanence() const {
    return finPermanence;
}

void EnfantPermanence::setFinPermanence(string fin) {
    finPermanence = fin;
}

void EnfantPermanence::ajouterActivite(const ActiviteSupplementaire& act) {
    activitessupp.push_back(act);
}

void EnfantPermanence::afficherActivites() const {
    for (auto act : activitessupp) {
        act.afficher();
    }
}
void EnfantPermanence::saisirEnfant() {
    Enfant::saisirEnfant();
    
    cout << "Tapez l'heure de fin de permanence: ";
    cin >> finPermanence;
    
    string choix;
    cout << "Ajoutez activite supplementaire?: ";
    cin >> choix;
    
    while(choix == "oui") {
        ActiviteSupplementaire* act = new ActiviteSupplementaire;
        string a;
        cout<< "Saisir activite : ";
        cin>> a;
        *act = a;
        ajouterActivite(*act);
        
        cout << "Ajoutez une autre activite supplementaire?: ";
        cin >> choix;
    }
}
void EnfantPermanence::afficher(){
    Enfant::afficher();
    cout<< "Fin du permenance : "<< finPermanence<<endl;
    for (auto act : activitessupp) {
        act.afficher();
        cout<<"\n"<<endl;
    }
}

EnfantPermanence::~EnfantPermanence() {}
