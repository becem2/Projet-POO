#include "employee.cpp"


class employeebureautique : public employee {
    private:
        string tachebureautique;
    public:
        employeebureautique();
        employeebureautique(string n,string p, int a, double salaire, string tache);
        string getTache() ;
        void setTache(string) ;
        void afficherInfos() ;
        void donnerRepas() ;
        void changerCouches() ;
        void saisirEmployee();
        double calculerSalaire(double heuresTravaillees) const override;
    };