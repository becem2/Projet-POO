#include "Activite.h"
Activite::Activite() : typeActivite("Inconnu") {
}
Activite::Activite(string type) : typeActivite(type) {
}
Activite::Activite(const Activite& a ){
    typeActivite = a.typeActivite;
}
string Activite::getTypeActivite()  {
    return typeActivite;
}
void Activite::setTypeActivite(string type) {
    typeActivite = type;
}
void Activite::afficher(){
    cout<<"Type activite : "<<typeActivite;
}
istream& operator>>(istream& in, Activite& a){
    in >> a.typeActivite;
    return in;
}
ostream& operator<<(ostream& out, Activite& a){
    out<<"Type activite : " <<a.typeActivite<<endl;
    return out;
}
Activite::~Activite() {}