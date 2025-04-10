#include "Enfant.cpp"
#include "Permenance.h"
using namespace std;


class EnfantEnPermanence : public Enfant {
    private:
        int dureePermanence;
        vector <Permenance*> permenance;
    
    public:
        EnfantEnPermanence();
        EnfantEnPermanence(const string& nom, const string& prenom, int age, int duree, const string& specificNeeds = "");
        EnfantEnPermanence(const EnfantEnPermanence&);
        void saisirDureePermanence();
        void afficher() const override;
    
    };