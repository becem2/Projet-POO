#include "Employee.cpp"
class EmployeeBureautique : public Employee {
    private:
        string tachebureautique;
    public:
        EmployeeBureautique();
        EmployeeBureautique(Employee&, string tache);
        EmployeeBureautique(EmployeeBureautique&);
        string getTache() ;
        void setTache(string) ;
        void afficher() ;
        void saisirEmployee();
        double calculerSalaire(double heuresTravaillees);
        friend istream& operator>>(istream&,EmployeeBureautique&);
        friend ostream& operator<<(ostream&,EmployeeBureautique&);
    };