#include "Creche.h"
#include <typeinfo>

Creche::Creche() {
}

Creche::~Creche() {
    for (int i =0;i<employees.size();i++) {
        delete employees[i];
    }
    for (int i =0;i<enfants.size();i++) {
        delete enfants[i];
    }
}

void Creche::AjouterEmployee(employee* emp) {
    employees.push_back(emp);
}

void Creche::AjouterEnfant(Enfant* enf) {
    enfants.push_back(enf);
}

void Creche::afficherEmployeesNormaux() const {
    int count = 0;
    cout << "\n=== Employes Normaux ===" << endl;
    
    for (const auto& emp : employees) {
        if (dynamic_cast<employeebureautique*>(emp) == nullptr) {
            cout << "\n[Employe Normal #" << ++count << "]" << endl;
            emp->afficherInfos();
        }
    }
    
    if (count == 0) {
        cout << "Aucun employe normal dans la creche." << endl;
    } else {
        cout << "\nTotal employes normaux: " << count << endl;
    }
}

void Creche::afficherEmployeesBureautiques() const {
    int count = 0;
    cout << "\n=== Employes Bureautiques ===" << endl;
    
    for (const auto& emp : employees) {
        if (auto bureauEmp = dynamic_cast<employeebureautique*>(emp)) {
            cout << "\n[Employe Bureautique #" << ++count << "]" << endl;
            bureauEmp->afficherInfos();
            cout << "Tache: " << bureauEmp->getTache() << endl;
        }
    }
    
    if (count == 0) {
        cout << "Aucun employe bureautique dans la creche." << endl;
    } else {
        cout << "\nTotal employes bureautiques: " << count << endl;
    }
}


void Creche::afficherEnfantsNormaux() const {
    int count = 0;
    cout << "\n=== Enfants Normaux ===" << endl;
    
    for (const auto& enfant : enfants) {
        if (dynamic_cast<EnfantPermanence*>(enfant) == nullptr && 
            dynamic_cast<EnfantAvecAllergie*>(enfant) == nullptr) {
            cout << "\n[Enfant Normal #" << ++count << "]" << endl;
            enfant->afficher();
        }
    }
    
    if (count == 0) {
        cout << "Aucun enfant normal dans la creche." << endl;
    }
}



void Creche::afficherEnfantsPermanence() const {
    int count = 0;
    cout << "\n=== Enfants en Permanence ===" << endl;
    
    for (const auto& enfant : enfants) {
        if (auto perm = dynamic_cast<EnfantPermanence*>(enfant)) {
            cout << "\n[Enfant Permanence #" << ++count << "]" << endl;
            perm->afficher();
            cout << "Heure fin: " << perm->getFinPermanence() << endl;
        }
    }
    
    if (count == 0) {
        cout << "Aucun enfant en permanence dans la creche." << endl;
    }
}

void Creche::afficherEnfantsAllergies() const {
    int count = 0;
    cout << "\n=== Enfants avec Allergies ===" << endl;
    
    for (const auto& enfant : enfants) {
        if (auto allergie = dynamic_cast<EnfantAvecAllergie*>(enfant)) {
            cout << "\n[Enfant Allergie #" << ++count << "]" << endl;
            allergie->afficher();
            cout << "Allergie: " << allergie->getTypeAllergie() << endl;
        }
    }
    
    if (count == 0) {
        cout << "Aucun enfant avec allergie dans la creche." << endl;
    }
}
bool Creche::supprimerEmployee(const string& nom) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getNom() == nom) {
            delete *it;
            employees.erase(it);
            return true;
        }
    }
    return false;
}

bool Creche::supprimerEnfant(const string& nom) {
    for (auto it = enfants.begin(); it != enfants.end(); ++it) {
        if ((*it)->getNom() == nom) {
            delete *it;
            enfants.erase(it);
            return true;
        }
    }
    return false;
}

void Creche::afficherListeEmployees() const {
    cout << "\n=== Liste des employes ===" << endl;
    for (const auto& emp : employees) {
        cout << "- " << emp->getNom() << endl;
    }
}

void Creche::afficherListeEnfants() const {
    cout << "\n=== Liste des enfants ===" << endl;
    for (const auto& enf : enfants) {
        cout << "- " << enf->getNom() << endl;
    }
}

employee* Creche::trouverEmployee(const string& nom) {
    for (auto emp : employees) {
        if (emp->getNom() == nom) {
            return emp;
        }
    }
    return nullptr;
}

Enfant* Creche::trouverEnfant(const string& nom) {
    for (auto enf : enfants) {
        if (enf->getNom() == nom) {
            return enf;
        }
    }
    return nullptr;
}


void Creche::afficherEmployees() const {
    if (employees.empty()) {
        cout << "Aucun employe dans la creche." << endl;
        return;
    }

    cout << "\n=== Liste des employes ===" << endl;
    for (size_t i = 0; i < employees.size(); ++i) {
        cout << "\nEmploye #" << i+1 << ":" << endl;
        employees[i]->afficherInfos();
        
        // Display specific info for office employees
        if (auto bureauEmp = dynamic_cast<employeebureautique*>(employees[i])) {
            cout << "Type: Employe bureautique" << endl;
            cout << "Tache: " << bureauEmp->getTache() << endl;
        } else {
            cout << "Type: Employe normal" << endl;
        }
    }
}

void Creche::afficherEnfants() const {
    if (enfants.empty()) {
        cout << "Aucun enfant dans la creche." << endl;
        return;
    }

    cout << "\n=== Liste des enfants ===" << endl;
    for (size_t i = 0; i < enfants.size(); ++i) {
        cout << "\nEnfant #" << i+1 << ":" << endl;
        enfants[i]->afficher();
        
        if (auto perm = dynamic_cast<EnfantPermanence*>(enfants[i])) {
            cout << "Type: Enfant en permanence" << endl;
            cout << "Heure fin: " << perm->getFinPermanence() << endl;
        } 
        else if (auto allergie = dynamic_cast<EnfantAvecAllergie*>(enfants[i])) {
            cout << "Type: Enfant avec allergie" << endl;
            cout << "Allergie: " << allergie->getTypeAllergie() << endl;
        } 
        else {
            cout << "Type: Enfant normal" << endl;
        }
    }
}
int Creche::compterEnfantsPermanence() const {
    int count = 0;
    for (const auto& enfant : enfants) {
        if (dynamic_cast<EnfantPermanence*>(enfant) != nullptr) {
            count++;
        }
    }
    return count;
}
void Creche::listerEnfantsAvecAllergie(const string& typeAllergie) const {
    bool found = false;
    
    cout << "\n=== ENFANTS AVEC ALLERGIE A " << typeAllergie << " ===" << endl;
    
    for (const auto& enfant : enfants) {
        if (auto allergie = dynamic_cast<EnfantAvecAllergie*>(enfant)) {
            if (allergie->getTypeAllergie() == typeAllergie) {
                enfant->afficher();
                cout << "Type d'allergie: " << allergie->getTypeAllergie() << endl;
                cout << "---------------------" << endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << "Aucun enfant avec cette allergie trouve." << endl;
    }
}


void Creche::afficherPlusVieuxEnfant() const {
    if (enfants.empty()) {
        cout << "Aucun enfant dans la creche." << endl;
        return;
    }

    const Enfant* plusVieux = enfants[0];
    for (const auto& enfant : enfants) {
        if (enfant->getAge() > plusVieux->getAge()) {
            plusVieux = enfant;
        }
    }

    cout << "\n=== ENFANT LE PLUS AGE ===" << endl;
    plusVieux->afficher();
    
 
    if (auto perm = dynamic_cast<const EnfantPermanence*>(plusVieux)) {
        cout << "Type: Enfant en permanence" << endl;
        cout << "Heure fin: " << perm->getFinPermanence() << endl;
    } 
    else if (auto allergie = dynamic_cast<const EnfantAvecAllergie*>(plusVieux)) {
        cout << "Type: Enfant avec allergie" << endl;
        cout << "Allergie: " << allergie->getTypeAllergie() << endl;
    } 
    else {
        cout << "Type: Enfant normal" << endl;
    }
}


void Creche::listerEnfantsMoinsDe10Ans() const {
    const int AGE_LIMITE = 10;
    bool trouve = false;

    cout << "\n=== ENFANTS DE MOINS DE " << AGE_LIMITE << " ANS ===" << endl;

    for (const auto& enfant : enfants) {
        if (enfant->getAge() < AGE_LIMITE) {
            enfant->afficher();
            
            if (auto perm = dynamic_cast<const EnfantPermanence*>(enfant)) {
                cout << "Type: Enfant en permanence" << endl;
                cout << "Heure fin: " << perm->getFinPermanence() << endl;
            } 
            else if (auto allergie = dynamic_cast<const EnfantAvecAllergie*>(enfant)) {
                cout << "Type: Enfant avec allergie" << endl;
                cout << "Allergie: " << allergie->getTypeAllergie() << endl;
            } 
            else {
                cout << "Type: Enfant normal" << endl;
            }
            cout << "---------------------" << endl;
            trouve = true;
        }
    }

    if (!trouve) {
        cout << "Aucun enfant de moins de " << AGE_LIMITE << " ans trouve." << endl;
    }
}