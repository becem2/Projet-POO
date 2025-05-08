#include "EnfantAvecAllergie.h"
EnfantAvecAllergie::EnfantAvecAllergie() : Enfant(), allergie("") {
}
EnfantAvecAllergie::EnfantAvecAllergie(string nom, string prenom, int age, string allergie){
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
    this->allergie = allergie;
}
EnfantAvecAllergie::EnfantAvecAllergie(EnfantAvecAllergie& other){
    nom = other.nom;
    prenom = other.prenom;
    age = other.age;
    allergie = other.allergie;
    for (int i = 0 ;i<other.activites.size();i++){
        Activite* a = new Activite(*other.activites[i]);
        activites.push_back(a);
    }
}
EnfantAvecAllergie::~EnfantAvecAllergie() {
    for (int i = 0;i<activites.size();i++){
        delete activites[i];
    }
}
void EnfantAvecAllergie::afficher() {
    Enfant::afficher();
    cout << "Allergie : " << allergie << endl;
}
void EnfantAvecAllergie::saisirEnfant(){
    Enfant::saisirEnfant();
    cout <<"Saisir allergie : ";
    cin >> allergie;
}
string EnfantAvecAllergie::getTypeAllergie(){
   return allergie ;
}
void EnfantAvecAllergie::setTypeAllergie(string t){
    allergie = t;

}
ostream& operator<< (ostream& out , EnfantAvecAllergie& e ){
    out<<"Nom : "<<e.nom<<endl;
    out<<"Prenom : "<<e.prenom<<endl;
    out<<"Age : "<<e.age<<endl;
    for (int i = 0 ;i<e.activites.size();i++){
        out<<"Activite "<<(i+1)<<" : "<<e.activites[i]<<endl;
    }
    out<<"Allergie : "<<e.allergie<<endl;
    return out;
}
istream& operator>>(istream& in, EnfantAvecAllergie& e ){
    cout<<"Tapez nom : ";
    in >>e.nom;
    cout<<"Tapez Prenom : ";
    in >>e.prenom;
    cout<<"Tapez Age : ";
    in >>e.age;
    string choix;
    do{
        Activite* act = new Activite();
        string a;
        cout<< "Saisir activite : ";
        in>> a;
        *act = a;
        e.ajouterActivite(act);
        cout << "Ajoutez activite?";
        cin >> choix;
    }while(choix == "oui");
    return in;
}
