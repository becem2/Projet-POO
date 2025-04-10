#include "Enfant.h"

Enfant::Enfant() : nom(""), prenom(""), age(0), specificNeeds("") {}

Enfant::Enfant(const string& nom, const string& prenom, int age, const string& specificNeeds)
    : nom(nom), prenom(prenom), age(age), specificNeeds(specificNeeds) {}

 void Enfant::saisirEnfant() {
    cout << "===== Saisie des informations d'un enfant =====\n";

    cout << "Nom : ";
    cin >> nom;

    cout << "Prénom : ";
    cin >> prenom;

    while (true) {
        cout << "Âge : ";
        cin >> age;
        if (cin.fail() || age <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veuillez entrer un âge valide !\n";
        } else {
            break;
        }
    }

    cout << "Besoins spécifiques (laisser vide si aucun) : ";
    cin.ignore();
    getline(cin, specificNeeds);

    cout << "Enfant enregistré avec succès !\n";
}

Enfant::Enfant(const Enfant& e) {
    nom = e.nom;
    prenom = e.prenom;
    age = e.age ;
    specificNeeds = e.specificNeeds ;
    for (auto& a : e.allergie) {
        allergie.push_back(new Allergie(*a));
    }
    cout <<"Constructeur de recopie appele !"<< endl;
}

void Enfant::ajouterAllergie(Allergie* a) {
    allergie.push_back(a);
}

void Enfant::afficher() const {
    cout << "Nom: " << nom << ", Prenom: " << prenom << ", Age: " << age << " ans";
    if (!specificNeeds.empty()) {
        cout << ", Besoins spécifiques: " << specificNeeds;
    }
    cout << "\n";
}


string Enfant::getNom() const { return nom; }
string Enfant::getPrenom() const { return prenom; }