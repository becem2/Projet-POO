#include "Activite.cpp"
class Enfant {
    protected:
        string nom;
        string prenom;
        int age;
        vector<Activite*> activites;
    public:
        Enfant();
        Enfant(const Enfant& );
        virtual ~Enfant();
        virtual void setNom(string);
        virtual void setPrenom(string);
        virtual void setAge(int);
        virtual string getNom();
        virtual string getPrenom();
        virtual int getAge();
        virtual void saisirEnfant();
        virtual void afficher() ;
        virtual void ajouterActivite(Activite* act);
        bool operator== (const Enfant&);
        bool operator<(const Enfant&);
        friend ostream& operator<<(ostream&, Enfant&);
        friend istream& operator>>(istream&, Enfant& );
    }; 