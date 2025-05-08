#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;
class Employee {
protected:
    string nom;
    string prenom;
    int age;
    double salaireHoraire;
public:
    Employee();
    Employee(Employee&);
    virtual ~Employee();
    virtual void afficher()  ;
    virtual void surveillerEnfant() ;
    virtual string getNom() ;
    virtual void setNom(string) ;
    virtual int getAge() ;
    virtual void setAge(int);
    virtual double getSalaireHoraire()  ;
    virtual void setSalaireHoraire(double) ;
    virtual void saisirEmployee();
    virtual double calculerSalaire(double) ;
    friend istream& operator>>(istream&,Employee&);
    friend ostream& operator<<(ostream&,Employee&);
    Employee operator+(const Employee&);
};