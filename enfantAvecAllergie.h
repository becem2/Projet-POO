#include "enfant.cpp"

class EnfantAvecAllergie : public Enfant {
    private:
        string allergie;
    public:
        EnfantAvecAllergie();
        EnfantAvecAllergie(string nom, string prenom, int age, string allergie);
        EnfantAvecAllergie(const EnfantAvecAllergie& other);
        ~EnfantAvecAllergie();
        void setTypeAllergie(string);
        string getTypeAllergie() const;
        void saisirEnfant();;
        void afficher() const override;
    };