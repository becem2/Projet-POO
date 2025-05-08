#include "EnfantAvecAllergie.cpp"
#include "Activitesupp.cpp"
class EnfantPermanence : public Enfant{
private:
    string finPermanence;
    vector<ActiviteSupplementaire*> activitessupplementaires;
public:
    EnfantPermanence();
    EnfantPermanence(EnfantPermanence&);
    ~EnfantPermanence();
    string getFinPermanence() ;
    void setFinPermanence(string );
    void ajouterActivite(ActiviteSupplementaire* act);
    void saisirEnfant();
    void afficher();
    friend istream& operator>> (istream&,EnfantPermanence&);
    friend ostream& operator<< (ostream&,EnfantPermanence&);
};