#include "Activitesupp.h"
ActiviteSupplementaire::ActiviteSupplementaire(): nomActivite("Inconnu") {
}
ActiviteSupplementaire::ActiviteSupplementaire(string nom) : nomActivite(nom){
}
ActiviteSupplementaire::ActiviteSupplementaire(ActiviteSupplementaire& other){
    nomActivite = other.nomActivite;
}
ActiviteSupplementaire::~ActiviteSupplementaire() {
}
void ActiviteSupplementaire::afficher()  {
    cout << "Activite Supplementaire : " << nomActivite << endl;
}
void ActiviteSupplementaire::SetNomActivite(string nom){
    nomActivite = nom;
}
string ActiviteSupplementaire::GetNomActivite(){
    return nomActivite;
}
istream& operator>>(istream& in, ActiviteSupplementaire& a){
    in >> a.nomActivite;
    return in;
}
ostream& operator<<(ostream& out, ActiviteSupplementaire& a){
    out << "Activite Supplementaire : " << a.nomActivite << endl;
    return out;
}