#include "Enfant.cpp"
class EnfantAvecAllergie : public Enfant {
    private:
        string allergie;
    public:
        EnfantAvecAllergie();
        EnfantAvecAllergie(string , string , int , string );
        EnfantAvecAllergie(EnfantAvecAllergie& );
        ~EnfantAvecAllergie();
        void setTypeAllergie(string);
        string getTypeAllergie() ;
        void saisirEnfant();
        void afficher();
        friend istream& operator>>(istream&, EnfantAvecAllergie&);
        friend ostream& operator<<(ostream&, EnfantAvecAllergie&);
    };