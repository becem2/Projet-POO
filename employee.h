#include <iostream>
#include <string>
#include <vector>

using namespace std;

class employee {
protected:
    string nom;
    string prenom;
    int age;
    double salaireHoraire;
public:
    employee();
    employee(string n,string p, int a, double salaire);
    virtual void afficherInfos()  ;
    virtual void surveillerEnfant() ;
    virtual string getNom() ;
    virtual void setNom(string) ;
    virtual int getAge() ;
    virtual void setAge(int);
    virtual double getSalaireHoraire()  ;
    virtual void setSalaireHoraire(double) ;
    virtual void saisirEmployee();
    virtual ~employee();
    virtual double calculerSalaire(double heuresTravaillees) const;
};