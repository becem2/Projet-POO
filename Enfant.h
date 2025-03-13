#include <iostream>
#include <string>

using namespace std;

struct date{
    int jour;
    int mois;
    int annee;
};
typedef struct date DATE;

class Enfant {
    protected:
        int CodeEnfant;
        string Name;
        string Lastname;
        DATE Age;

    public:
        Enfant();
        Enfant(const Enfant &);
        Enfant(int,string,string,DATE);
        virtual void Afficher();
        void SetCodeEnfant(int );
        void SetName(string);
        void SetLastname(string);
        void SetAge(DATE);
        int GetCodeEnfant();
        string GetName();
        string GetLastname();
        DATE GetAge();
        int GetDay();
        int GetMonth();
        int GetYear();
        virtual ~Enfant();



};