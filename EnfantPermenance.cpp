#include "EnfantPermenance.h"
EnfantPermanence::EnfantPermanence(){
}
EnfantPermanence::~EnfantPermanence() {
}
EnfantPermanence::EnfantPermanence(EnfantPermanence& other){
    nom = other.nom;
    prenom = other.prenom;
    age = other.age;
    for (int i = 0 ;i<other.activitessupplementaires.size();i++){
        ActiviteSupplementaire* a = new ActiviteSupplementaire(*other.activitessupplementaires[i]);
        activitessupplementaires.push_back(a);
    }
}
string EnfantPermanence::getFinPermanence()  {
    return finPermanence;
}
void EnfantPermanence::setFinPermanence(string fin) {
    finPermanence = fin;
}
void EnfantPermanence::ajouterActivite(ActiviteSupplementaire* act) {
    activitessupplementaires.push_back(act);
}
void EnfantPermanence::afficher(){
    Enfant::afficher();
    cout<< "Fin du permenance : "<< finPermanence<<endl;
    for (int i = 0; i<activitessupplementaires.size();i++) {
        ActiviteSupplementaire* a = new ActiviteSupplementaire(*activitessupplementaires[i]);
        a->afficher();
        cout<<""<<endl;
    }
}
void EnfantPermanence::saisirEnfant(){
    Enfant::saisirEnfant();
    cout<<"Tapez la fin du permenance : ";
    cin >> finPermanence;
    string choix;
    do{
        ActiviteSupplementaire* act = new ActiviteSupplementaire();
        string a;
        cout<< "Saisir activite supplementaire : ";
        cin>> a;
        *act = a;
        ajouterActivite(act);
        cout << "Ajoutez activite supplementaire ?";
        cin >> choix;
    }while(choix == "oui");
}
istream& operator>> (istream& in,EnfantPermanence& e){
    cout<<"Tapez la fin du permenance : ";
    in >> e.finPermanence;
    string choix;
    do{
        ActiviteSupplementaire* act = new ActiviteSupplementaire();
        string a;
        cout<< "Saisir activite : ";
        cin>> a;
        *act = a;
        e.ajouterActivite(act);
        cout << "Ajoutez activite?";
        cin >> choix;
    }while(choix == "oui");
    return in;
}
ostream& operator<< (ostream& out,EnfantPermanence& e){
    out<<"Nom : " <<e.nom<<endl;
    out<<"Prenom : " <<e.prenom<<endl;
    out<<"Age : " <<e.age<<endl;
    out<<"Fin du permenance : "<<e.finPermanence<<endl;
    for(int i = 0;i<e.activitessupplementaires.size();i++){
        ActiviteSupplementaire* a = new ActiviteSupplementaire(*e.activitessupplementaires[i]);
        out<<"Activite : "<<a<<endl;
    }
    return out;
}