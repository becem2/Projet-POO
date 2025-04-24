#include "enfantAvecAllergie.cpp"
#include "Activitesupp.cpp"

class EnfantPermanence : public Enfant{
private:
    string finPermanence;
    vector<ActiviteSupplementaire> activitessupp;

public:
    EnfantPermanence();
    EnfantPermanence(string fin, string activite);
    string getFinPermanence() const;
    void setFinPermanence(string fin);
    void ajouterActivite(const ActiviteSupplementaire& act);
    void afficherActivites() const;
    void saisirEnfant();
    void afficher();
    ~EnfantPermanence();
};

