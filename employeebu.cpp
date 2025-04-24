#include "employeebu.h"


employeebureautique::employeebureautique(){}
employeebureautique::employeebureautique(string n,string p, int a, double salaire, string tache)
            : employee(n,p, a, salaire), tachebureautique(tache) {}


void employeebureautique::afficherInfos() {
            employee::afficherInfos();
            cout << "Tache bureautique: " << tachebureautique << "\n";
        }

void employeebureautique::donnerRepas() {
            cout << nom << " donne un repas à l'enfant.\n";
        }

void employeebureautique::changerCouches() {
            cout << nom << " change la couche de l'enfant.\n";
        }

string employeebureautique::getTache() {
    return tachebureautique;
    }

void employeebureautique::setTache(string t) {
    tachebureautique = t;
    }
void employeebureautique::saisirEmployee(){
    employee::saisirEmployee();
    cout<<"Tapez tachebureautique : ";
    cin>>tachebureautique;
}
double employeebureautique::calculerSalaire(double heuresTravaillees) const {
    const double BONUS_BUREAU = 1.52;
    return salaireHoraire * heuresTravaillees * BONUS_BUREAU;
}