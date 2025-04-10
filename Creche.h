
#include "EnfantEnPermenance.cpp"
#include "BabysitterJour.cpp"

using namespace std;


class Creche {
private:
    vector<Enfant*> enfants;
    vector<BabySitter*> babysitter;

public:
    void ajouterEnfant(Enfant* enfant);
    void ajouterBabysitter(BabySitter* babysitter);
    void afficherEnfants() const;
    Enfant* rechercherEnfant(const string& nom, const string& prenom) const;
    int compterEnfantsEnPermanence() const;
    void supprimerEnfant(const string& nom, const string& prenom);
    ~Creche();
};