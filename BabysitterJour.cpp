#include "BabysitterJour.h"



BabySitterJour::BabySitterJour(string n, int a, string tel, double salaire, string horaire)
            : BabySitter(n, a, tel, salaire), horaireTravail(horaire) {}
    
       
void BabySitterJour::afficherInfos() const{
            BabySitter::afficherInfos();
            cout << "Horaire de travail: " << horaireTravail << "\n";
        }
    
void BabySitterJour::donnerRepas() {
            cout << nom << " donne un repas à l'enfant.\n";
        }
    
void BabySitterJour::changerCouches() {
            cout << nom << " change la couche de l'enfant.\n";
        }