#include "enfant.h"

Enfant::Enfant() : nom(""), prenom(""), age(0) {}
Enfant::Enfant(string nom, string prenom, int age) : nom(nom), prenom(prenom), age(age) {}
Enfant::Enfant(const Enfant& other) : nom(other.nom), prenom(other.prenom), age(other.age) {
    for (auto act : other.activites) {
        activites.push_back(new Activite(*act));
    }
}
void Enfant::saisirEnfant(){
    cout << "Tapez le nom du Enfant : \n";
    cin >> nom;
    cout << "Tapez le prenom du Enfant : \n";
    cin >> prenom;
    cout << "Tapez l'age du Enfant : \n";
    cin >> age;
    string choix;
    cout << "Ajoutez activite?";
    cin >> choix;
    do{
        Activite* act = new Activite;
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
    for (auto act : activites) delete act;
}
void Enfant::afficher() const {
    cout << "Nom: " << nom <<endl << "Prenom: " << prenom <<endl  << "age: " << age << endl;
    for (auto act : activites) {
        act->afficher();
        cout<<"\n"<<endl;
    }
}
void Enfant::ajouterActivite(Activite* act) {
    activites.push_back(act);
}
string Enfant::getNom(){
    return nom;
}
int Enfant::getAge() const{
    return age;
}
