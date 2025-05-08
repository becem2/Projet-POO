#include "Employee.h"
Employee::Employee() : nom("Inconnu"),prenom("Inconnu") ,age(0), salaireHoraire(0.0) {
}
void Employee::afficher()  {
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Age: " << age << " ans" << endl;
    cout << "Salaire horaire: " << salaireHoraire << " €" << endl;
}
Employee::Employee(Employee& e){
    nom = e.nom;
    prenom = e.prenom;
    age = e.age;
    salaireHoraire = e.salaireHoraire;
}
string Employee::getNom()  {
    return nom;
}
int Employee::getAge()  {
    return age;
}
double Employee::getSalaireHoraire()  {
    return salaireHoraire;
}
void Employee::setNom(string n)  {
    nom = n;
}
void Employee::setAge(int a) {
    age = a;
}
void Employee::setSalaireHoraire(double salaire)  {
    salaireHoraire = salaire;
}
void Employee::saisirEmployee(){
    cout<<"Tapez Nom : ";
    cin>>nom;
    cout<<"Tapez prenom : ";
    cin>>prenom;
    cout<<"Tapez age : ";
    cin>> age;
    cout<<"Tapez SalaireHoraire : ";
    cin>> salaireHoraire;
}
double Employee::calculerSalaire(double heuresTravaillees)  {
    return salaireHoraire * heuresTravaillees;
}
Employee::~Employee(void) {
}
istream& operator>>(istream& in,Employee& e){
    cout<<"Tapez Nom : ";
    in>>e.nom;
    cout<<"Tapez prenom : ";
    in>>e.prenom;
    cout<<"Tapez age : ";
    in>> e.age;
    cout<<"Tapez SalaireHoraire : ";
    in>> e.salaireHoraire;
    return in;
}
ostream& operator<<(ostream& out,Employee& e){
    out<<"Nom : "<<e.nom<<endl;
    out<<"Prenom : "<<e.prenom<<endl;
    out<<"Age : "<<e.age<<endl;
    out<<"Salaire horaire : "<<e.salaireHoraire<<endl;
    return out;
}
void Employee::surveillerEnfant() {
}