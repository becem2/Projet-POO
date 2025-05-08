#include "Enfant.h"
Enfant::Enfant() : nom(""), prenom(""), age(0) {
}
Enfant::Enfant(const Enfant& other){
    nom = other.nom;
    prenom = other.prenom;
    age = other.age;
    for (int i = 0; i <other.activites.size();i++){
        Activite* a = new Activite(*other.activites[i]);
        this->activites.push_back(a);
    }
}
void Enfant::saisirEnfant(){
    cout <<"Tapez le nom du Enfant : ";
    cin >> nom;
    cout <<"Tapez le prenom du Enfant : ";
    cin >> prenom;
    try {
        cout <<"Tapez l'age du Enfant : ";
        cin >> age;
        if (age < 0) throw age; 
    } 
    catch (int invalidAge) {
        cout << "Erreur : l'age (" << invalidAge << ") doit etre > 0" << endl;
    }
    string choix;
    do{
        Activite* act = new Activite();
        string a;
        cout<< "Saisir activite : ";
        cin>> a;
        *act = a;
        ajouterActivite(act);
        cout << "Ajoutez activite?";
        cin >> choix;
    }while(choix == "oui");
}
Enfant::~Enfant() {
    for (int i = 0;i<activites.size();i++){
        delete activites[i];
    } 
}
void Enfant::afficher()  {
    cout << "Nom: " << nom <<endl ;
    cout<< "Prenom: " << prenom <<endl  ;
    cout<< "age: " << age << endl;
    for (int i = 0;i<activites.size();i++) {
        Activite* a = new Activite(*activites[i]);
        a->afficher();
    }
}
void Enfant::ajouterActivite(Activite* act) {
    activites.push_back(act);
}
string Enfant::getNom(){
    return nom;
}
string Enfant::getPrenom(){
    return prenom;
}
int Enfant::getAge() {
    return age;
}
bool Enfant::operator== (const Enfant& e){
    return (nom == e.nom || prenom == e.prenom || age == e.age);
}
ostream& operator<<(ostream& out, Enfant& e){
    out<<"Nom : " <<e.nom<<endl;
    out<<"Prenom : " <<e.prenom<<endl;
    out<<"Age : " <<e.age<<endl;
    for(int i = 0;i<e.activites.size();i++){
        Activite* a = new Activite(*e.activites[i]);
        out<<"Activite : "<<a<<endl;
    }
    return out;
}
istream& operator>>(istream& in, Enfant& e){
    cout<<"Tapez Nom : ";
    in>>e.nom;
    cout<<"Tapez Prenom : ";
    in>>e.prenom;
    cout<<"Tapez Age : ";
    in>>e.age;
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
bool Enfant::operator< (const Enfant& e){
    return (age<e.age);
}

void Enfant::setNom(string nom) {
    this->nom = nom;
}

void Enfant::setPrenom(string prenom) {
    this->prenom = prenom;
}

void Enfant::setAge(int age) {
    this->age = age;
}