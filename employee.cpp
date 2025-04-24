#include "employee.h"

employee::employee() : nom("Inconnu"),prenom("Inconnu") ,age(0), salaireHoraire(0.0) {}
employee::employee(string n,string p, int a, double salaire) : nom(n),prenom(p), age(a), salaireHoraire(salaire) {}
void employee::afficherInfos()  {
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Age: " << age << " ans" << endl;
    cout << "Salaire horaire: " << salaireHoraire << " €" << endl;
}
void employee::surveillerEnfant() {
    cout << nom << " est en train de surveiller un enfant." << endl;
}
string employee::getNom()  {
    return nom;
}
int employee::getAge()  {
    return age;
}
double employee::getSalaireHoraire()  {
    return salaireHoraire;
}
void employee::setNom(string n)  {
    nom = n;
}
void employee::setAge(int a) {
    age = a;
}

void employee::setSalaireHoraire(double salaire)  {
    salaireHoraire = salaire;
}
void employee::saisirEmployee(){
    cout<<"Tapez Nom : ";
    cin>>nom;
    cout<<"Tapez prenom : ";
    cin>>prenom;
    cout<<"Tapez age : ";
    cin>> age;
    cout<<"Tapez SalaireHoraire : ";
    cin>> salaireHoraire;
    
}

double employee::calculerSalaire(double heuresTravaillees) const {
    return salaireHoraire * heuresTravaillees;
}

employee::~employee() {}
