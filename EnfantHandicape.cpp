#include "EnfantHandicape.h"





EnfantHandicape::EnfantHandicape() : Enfant(0,"","",{0,0,0}),TypeMaladie(0) {}
EnfantHandicape::EnfantHandicape(Enfant e, int m) : Enfant(e),TypeMaladie(m) {}
EnfantHandicape::EnfantHandicape(int c,string n,string l,DATE d ,int t){
    CodeEnfant = c;
    Name = n;
    Lastname = l;
    Age.jour = d.jour;
    Age.mois = d.mois;
    Age.annee = d.annee;
    TypeMaladie = t;
}

void EnfantHandicape::Afficher(){
    cout<<"Code Enfant est : "<<CodeEnfant<<endl;
    cout<<"Nom Enfant est : "<<Name<<endl;
    cout<<"Prenom Enfant est : "<<Lastname<<endl;
    cout<<"Age du l'Enfant est : "<<Age.jour<<"/"<<Age.mois<<"/"<<Age.annee<<endl;
    cout<<"Le type maladie de l'Enfant est : "<<TypeMaladie<<endl;

}
int EnfantHandicape::GetTypeMaladie(){
    return TypeMaladie;
}

void EnfantHandicape::SetTypeMaladie(int t){
    TypeMaladie = t;
}


EnfantHandicape::~EnfantHandicape(){

}