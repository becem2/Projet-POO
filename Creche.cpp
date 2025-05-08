#include "Creche.h"
Creche::Creche() {
}
Creche::Creche(Creche& other){
    for (int i = 0; i<other.enfants.size(); i++){
        if (typeid(other.enfants[i])==typeid(Enfant)){
            Enfant* e = new Enfant(*other.enfants[i]);
            enfants.push_back(e);
        }
        else if (typeid(other.enfants[i])==typeid(EnfantPermanence)){
            EnfantPermanence* e = dynamic_cast<EnfantPermanence*>(other.enfants[i]);
            enfants.push_back(e);
        }
        else {
            EnfantAvecAllergie* e = dynamic_cast<EnfantAvecAllergie*>(other.enfants[i]);
            enfants.push_back(e);
        }
    }
    for (int i = 0 ; i<other.employees.size();i++){
        if (typeid(other.employees[i])==typeid(Employee)){
            Employee* e = new Employee(*other.employees[i]);
            employees.push_back(e);
        }
        else {
            EmployeeBureautique * e = dynamic_cast<EmployeeBureautique*>(other.employees[i]);
            employees.push_back(e);
        }
    }
}
Creche::~Creche() {
    for (int i =0;i<employees.size();i++) {
        delete employees[i];
    }
    for (int i =0;i<enfants.size();i++) {
        delete enfants[i];
    }
}
void Creche::AjouterEmployee(Employee* e) {
    employees.push_back(e);
}
void Creche::AjouterEnfant(Enfant* e) {
    enfants.push_back(e);
}
void Creche::afficherEmployeesNormaux() {
    int count = 0;
    cout << "\n=== Employés Normaux ===" << endl;
    
    for (int i = 0; i < employees.size(); i++) {
        if (typeid(*employees[i]) == typeid(Employee)) {
            count++;
            cout << "Employé no " << count << " : " << endl;
            employees[i]->afficher();
        }
    }
    if (count == 0) {
        cout << "Aucun employé normal dans la creche." << endl;
    } else {
        cout << "Total employés normaux: " << count << endl;
    }
}
void Creche::afficherEmployeesBureautiques() {
    int count = 0;
    cout << "\n=== Employés Bureautiques ===" << endl;
    for (int i = 0; i < employees.size(); i++) {
        if (typeid(*employees[i]) == typeid(EmployeeBureautique)) {
            count++;
            cout << "Employé no " << count << " : " << endl;
            employees[i]->afficher();
        }
    }
    if (count == 0) {
        cout << "Aucun employé bureautique dans la creche." << endl;
    } else {
        cout << "Total employés bureautiques: " << count << endl;
    }
}
void Creche::afficherEnfantsNormaux() {
    int count = 0;
    cout << "\n=== Enfants Normaux ===" << endl;
    for (int i = 0; i < enfants.size(); i++) {
        if (typeid(*enfants[i]) == typeid(Enfant)) {
            count++;
            cout << "Enfant no " << count << " : " << endl;
            enfants[i]->afficher();
        }
    }
    if (count == 0) {
        cout << "Aucun enfant normal dans la creche." << endl;
    } else {
        cout << "Total enfants normaux: " << count << endl;
    }
}
void Creche::afficherEnfantsPermanence() {
    int count = 0;
    cout << "\n=== Enfants en Permanence ===" << endl;
    
    for (int i = 0; i < enfants.size(); i++) {
        if (typeid(*enfants[i]) == typeid(EnfantPermanence)) {
            count++;
            cout << "Enfant no " << count << " : " << endl;
            enfants[i]->afficher();
        }
    }
    if (count == 0) {
        cout << "Aucun enfant en permanence dans la creche." << endl;
    } else {
        cout << "Total enfants en permanence: " << count << endl;
    }
}
void Creche::afficherEnfantsAllergies() {
    int count = 0;
    cout << "\n=== Enfants avec Allergies ===" << endl;
    for (int i = 0; i < enfants.size(); i++) {
        if (typeid(*enfants[i]) == typeid(EnfantAvecAllergie)) {
            count++;
            cout << "Enfant no "<<count<<" : "<< endl;
            enfants[i]->afficher();
        }
    }
    if (count == 0) {
        cout << "Aucun enfant avec allergie dans la creche." << endl;
    } else {
        cout << "Total enfants avec allergies: " << count << endl;
    }
}
void Creche::supprimerEmployee(string nom) {
    int i = 0;
    bool found = false;
    while (i < employees.size() && !found) {
        if (employees[i]->getNom() == nom) {
            found = true;
        } else {
            i++;
        }
    }
    if (found) {
        delete employees[i];
        for (int j = i; j < employees.size() - 1; j++) {
            employees[j] = employees[j+1];
        }
        employees.pop_back();
        cout << "Employee supprime avec succes" << endl;
    } else {
        cout << "Aucun employee avec ce nom existe!" << endl;
    }
}
void Creche::supprimerEnfant(string nom) {
    int i = 0;
    bool trouve = false;
    while (i < enfants.size() && !trouve) {
        if (enfants[i]->getNom() == nom) {
            trouve = true;
        } else {
            i++;
        }
    }
    if (trouve) {
        delete enfants[i];
        for (int j = i; j < enfants.size() - 1; j++) {
            enfants[j] = enfants[j+1];
        }
        enfants.pop_back();
        cout << "Enfant supprime avec succes" << endl;
    } else {
        cout << "Aucun enfant avec ce nom existe!" << endl;
    }
}
void Creche::compterEnfantsPermanence()  {
    int count = 0;
    for (int i = 0;i<enfants.size();i++) {
        if(typeid(enfants[i])== typeid(EnfantPermanence)){
            count++;
        }
    }
    cout<<"Il ya "<<count<<" enfant en permenance"<<endl;
}
void Creche::listerEnfantsAvecAllergie( string typeAllergie)  {
    bool found = false;
    cout << "\n=== ENFANTS AVEC ALLERGIE A " << typeAllergie << " ===" << endl;
    for (int i = 0; i < enfants.size(); ++i) {
        EnfantAvecAllergie* e = dynamic_cast<EnfantAvecAllergie*>(enfants[i]);
        if (e->getTypeAllergie() == typeAllergie) {
            enfants[i]->afficher();
            cout << "Type d'allergie: " << e->getTypeAllergie() << endl;
            cout << "---------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Aucun enfant avec cette allergie trouve." << endl;
    }
}
void Creche::afficherPlusVieuxEnfant() {
    if (enfants.empty()) {
        cout << "Aucun enfant dans la creche." << endl;
        return;
    }

    Enfant* plusVieux = enfants[0];
    for (int i = 1; i < enfants.size(); ++i) {
        if (*plusVieux < *enfants[i]) {
            plusVieux = enfants[i];
        }
    }

    cout << "\n=== ENFANT LE PLUS AGE ===" << endl;
    plusVieux->afficher();
}
void Creche::listerEnfantsMoinsDe10Ans()  {
    int ageLimit = 10;
    bool trouve = false;
    cout << "\n=== ENFANTS DE MOINS DE " << ageLimit << " ANS ===" << endl;
    for (int i = 0; i < enfants.size(); ++i) {
        if (enfants[i]->getAge() < ageLimit) {
            enfants[i]->afficher();
            cout << "---------------------" << endl;
            trouve = true;
        }
    }
    if (!trouve) {
        cout << "Aucun enfant de moins de " << ageLimit << " ans trouve." << endl;
    }
}
void Creche::afficherEmployeePlusHautSalaire() {
    Employee* plusHautSalaire = employees[0];
    for (int i = 1; i < employees.size(); ++i) {
        if (employees[i]->getSalaireHoraire() > plusHautSalaire->getSalaireHoraire()) {
            plusHautSalaire = employees[i];
        }
    }
    cout << "\n=== EMPLOYE AVEC LE SALAIRE LE PLUS ELEVE ===" << endl;
    plusHautSalaire->afficher();
    cout << "Salaire: " << plusHautSalaire->getSalaireHoraire() << endl;
}
ostream& operator<<(ostream& out,Creche& creche) {
    for (int i = 0;i<creche.employees.size();i++) {
        if (typeid(creche.employees[i]) == typeid(Employee)) {
            out<<creche.employees[i];
        } else if (typeid(*creche.employees[i]) == typeid(EmployeeBureautique)) {
            out<<creche.employees[i];
        }
    }
    for (int i = 0;i<creche.enfants.size();i++) {
        if (typeid(creche.enfants[i]) == typeid(Enfant)) {
            out<<creche.enfants[i];
        } else if (typeid(creche.enfants[i]) == typeid(EnfantPermanence)) {
            out<<creche.enfants[i];
        } else if (typeid(creche.enfants[i]) == typeid(EnfantAvecAllergie)) {
            out<<creche.enfants[i];
        }
    }
    return out;
}
istream& operator>>(istream& in, Creche& creche) {
    int choixEnfantOuEmployee;
    do {
        cout << "Vous-voulez ajouter un Enfant ou un Employee (Enfant = 1, Employee = 2, Quitter = 9): ";
        in >> choixEnfantOuEmployee;
        if (choixEnfantOuEmployee == 1) {
            int choixEnfant;
            do {
                cout << "Type d'enfant (1 = Normal, 2 = Permanence, 3 = Allergie): ";
                in >> choixEnfant;
                if (choixEnfant == 1) {
                    Enfant* e = new Enfant();
                    in >> *e;
                    creche.AjouterEnfant(e);
                    choixEnfantOuEmployee = -1;
                }
                else if (choixEnfant == 2) {
                    EnfantPermanence* e = new EnfantPermanence();
                    in >> *e;
                    creche.AjouterEnfant(e);
                    choixEnfantOuEmployee = -1;
                }
                else if (choixEnfant == 3) {
                    EnfantAvecAllergie* e = new EnfantAvecAllergie();
                    in >> *e;
                    creche.AjouterEnfant(e);
                    choixEnfantOuEmployee = -1;
                }
            } while (choixEnfant != 1 && choixEnfant != 2 && choixEnfant != 3);
        }
        else if (choixEnfantOuEmployee == 2) {
            int choixEmployee;
            do {
                cout << "Type d'employé (1 = Normal, 2 = Bureautique): ";
                in >> choixEmployee;
                if (choixEmployee == 1) {
                    Employee* e = new Employee();
                    in >> *e;
                    creche.AjouterEmployee(e);
                    choixEnfantOuEmployee = -1;
                }
                else if (choixEmployee == 2) {
                    EmployeeBureautique* e = new EmployeeBureautique();
                    in >> *e; 
                    creche.AjouterEmployee(e);
                    choixEnfantOuEmployee = -1;
                }
            } while (choixEmployee != 1 && choixEmployee != 2);
        }

    } while (choixEnfantOuEmployee != 9);
    return in;
}