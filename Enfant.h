#include "Activite.cpp"


class Enfant {
    protected:
        string nom;
        string prenom;
        int age;
        vector<Activite*> activites;
    public:
        Enfant();
        Enfant(string nom, string prenom, int age);
        Enfant(const Enfant& other);
        string getNom();
        virtual void saisirEnfant();
        virtual ~Enfant();
        virtual void afficher() const;
        void ajouterActivite(Activite* act);
        int getAge() const;
        
    }; 