#include "EnfantEnPermenance.h"

EnfantEnPermanence::EnfantEnPermanence() : Enfant(), dureePermanence(0) {}
EnfantEnPermanence::EnfantEnPermanence(const string& nom, const string& prenom, int age, int duree, const string& specificNeeds)
    : Enfant(nom, prenom, age, specificNeeds), dureePermanence(duree) {}

void EnfantEnPermanence::saisirDureePermanence() {
    while (true) {
        cout << "Durée de permanence (en heures) : ";
        cin >> dureePermanence;
        if (cin.fail() || dureePermanence <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veuillez entrer une durée valide !\n";
        } else {
            break;
        }
    }
    cout << "Durée de permanence enregistrée avec succès !\n";
}

void EnfantEnPermanence::afficher() const {
    Enfant::afficher();
    cout << "Duree de permanence: " << dureePermanence << " heure\n";
}