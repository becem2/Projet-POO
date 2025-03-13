#include "Enfant.h"



Enfant::Enfant() : CodeEnfant(0), Name("deflaut"), Lastname("deflaut"), Age{0, 0, 0} {}
Enfant::Enfant(int c ,string n,string p,DATE d) : CodeEnfant(c),Name(n),Lastname(p),Age(d){}
Enfant::Enfant(const Enfant &){}
void Enfant::Afficher(){
    cout<<"Code Enfant est : "<<CodeEnfant<<endl;
    cout<<"Nom Enfant est : "<<Name<<endl;
    cout<<"Prenom Enfant est : "<<Lastname<<endl;
    cout<<"Age du l'Enfant est : "<<Age.jour<<"/"<<Age.mois<<"/"<<Age.annee<<endl;

}
void Enfant::SetCodeEnfant(int c){
    CodeEnfant = c;
}
void Enfant::SetName(string n){
    Name = n;  
}
void Enfant::SetLastname(string p){
    Lastname= p;
}
void Enfant::SetAge(DATE d){
    Age.jour = d.jour;
    Age.mois = d.mois;
    Age.annee = d.annee;
}
int Enfant::GetCodeEnfant(){
    return CodeEnfant;
}
string Enfant::GetName(){
    return Name;
}
string Enfant::GetLastname(){
    return Lastname;
}
DATE Enfant::GetAge(){
    return Age;
}
int Enfant::GetDay(){
    return Age.jour;
}
int Enfant::GetMonth(){
    return Age.mois;
}
int Enfant::GetYear(){
    return Age.annee;
}
Enfant::~Enfant(){}