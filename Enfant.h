
#include "Allergie.cpp"



class Enfant {
    protected:
        string nom;
        string prenom;
        int age;
        string specificNeeds;
        vector <Allergie*> allergie;
    
    public:
        Enfant();
        Enfant(const string& nom, const string& prenom, int age, const string& specificNeeds = "");
        Enfant(const Enfant&);
        virtual void ajouterAllergie(Allergie*);
        virtual void afficher() const;
        void saisirEnfant();
        string getNom() const;
        string getPrenom() const;
        virtual ~Enfant() = default;
    };