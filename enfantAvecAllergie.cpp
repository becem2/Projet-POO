#include "enfantAvecAllergie.h"

EnfantAvecAllergie::EnfantAvecAllergie() : Enfant(), allergie("") {}
EnfantAvecAllergie::EnfantAvecAllergie(string nom, string prenom, int age, string allergie)
    : Enfant(nom, prenom, age), allergie(allergie) {}
EnfantAvecAllergie::EnfantAvecAllergie(const EnfantAvecAllergie& other)
    : Enfant(other), allergie(other.allergie) {}
EnfantAvecAllergie::~EnfantAvecAllergie() {}
void EnfantAvecAllergie::afficher() const {
    Enfant::afficher();
    cout << "Allergie : " << allergie << endl;
}
void EnfantAvecAllergie::saisirEnfant(){
    Enfant::saisirEnfant();
    cout <<"Saisir allergie : ";
    cin >> allergie;
}
string EnfantAvecAllergie::getTypeAllergie() const{
   return allergie ;
}
void EnfantAvecAllergie::setTypeAllergie(string t){
    allergie = t;

}