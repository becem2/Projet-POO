#include "EmployeeBureautique.h"
EmployeeBureautique::EmployeeBureautique(){
}
EmployeeBureautique::EmployeeBureautique(EmployeeBureautique& e ){
    nom = e.nom;
    prenom = e.prenom;
    age = e.age;
    salaireHoraire = e.salaireHoraire;
    tachebureautique = e.tachebureautique;
}
void EmployeeBureautique::afficher() {
    Employee::afficher();
    cout << "Tache bureautique: " << tachebureautique <<endl;
}
string EmployeeBureautique::getTache() {
    return tachebureautique;
}
void EmployeeBureautique::setTache(string t) {
    tachebureautique = t;
}
void EmployeeBureautique::saisirEmployee(){
    Employee::saisirEmployee();
    cout<<"Tapez tachebureautique : ";
    cin>>tachebureautique;
}
double EmployeeBureautique::calculerSalaire(double heuresTravaillees)  {
    const double Bonus = 1.52;
    return salaireHoraire * heuresTravaillees * Bonus;
}
istream& operator>>(istream& in,EmployeeBureautique& e){
    cout<<"Tapez Nom : ";
    in>>e.nom;
    cout<<"Tapez prenom : ";
    in>>e.prenom;
    cout<<"Tapez age : ";
    in>> e.age;
    cout<<"Tapez SalaireHoraire : ";
    in>> e.salaireHoraire;
    cout<<"Tapez Tache bureautique : ";
    return in;
}
ostream& operator<<(ostream& out,EmployeeBureautique& e){
    out<<"Nom : "<<e.nom<<endl;
    out<<"Prenom : "<<e.prenom<<endl;
    out<<"Age : "<<e.age<<endl;
    out<<"Salaire horaire : "<<e.salaireHoraire<<endl;
    out<<"Tache bureautique : "<<e.tachebureautique<<endl;
    return out;
}