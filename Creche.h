#include "EnfantPermenance.cpp"
#include "EmployeeBureautique.cpp"
class Creche {
public:
    vector<Employee*> employees;
    vector<Enfant*> enfants;
public:
    Creche();
    Creche(Creche&);
    ~Creche(void);
    void AjouterEmployee(Employee* );
    void AjouterEnfant(Enfant* );
    void afficherEmployeesNormaux() ;
    void afficherEmployeesBureautiques() ;
    void afficherEnfantsNormaux() ;
    void afficherEnfantsPermanence() ;
    void afficherEnfantsAllergies() ;
    void supprimerEmployee( string );
    void supprimerEnfant( string );
    void compterEnfantsPermanence() ;
    void listerEnfantsAvecAllergie(string ) ;
    void afficherPlusVieuxEnfant() ;
    void listerEnfantsMoinsDe10Ans() ;
    void afficherEmployeePlusHautSalaire();
    friend ostream& operator<<(ostream& ,  Creche& );
    friend istream& operator>>(istream& , Creche& );
};