#include "EnfantPermenance.cpp"
#include "employeebu.cpp"

class Creche {
public:
    vector<employee*> employees;
    vector<Enfant*> enfants;
    
public:
    Creche();
    ~Creche(void);
    void AjouterEmployee(employee* );
    void AjouterEnfant(Enfant* );
    void afficherEmployeesNormaux() const;
    void afficherEmployeesBureautiques() const;
    void afficherEnfantsNormaux() const;
    void afficherEnfantsPermanence() const;
    void afficherEnfantsAllergies() const;
    bool supprimerEmployee(const string& nom);
    bool supprimerEnfant(const string& nom);
    void afficherListeEmployees() const;
    void afficherListeEnfants() const;
    employee* trouverEmployee(const string& nom);
    Enfant* trouverEnfant(const string& nom);
    void afficherEmployees() const;
    void afficherEnfants() const;
    int compterEnfantsPermanence() const;
    void listerEnfantsAvecAllergie(const std::string& typeAllergie) const;
    void afficherPlusVieuxEnfant() const;
    void listerEnfantsMoinsDe10Ans() const;
};