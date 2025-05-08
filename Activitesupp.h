#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;
class ActiviteSupplementaire{
    private:
        string nomActivite;
    public:
        ActiviteSupplementaire();
        ActiviteSupplementaire(string nom);
        ActiviteSupplementaire(ActiviteSupplementaire&);
        ~ActiviteSupplementaire();
        void SetNomActivite(string);
        string GetNomActivite();
        void afficher();
        friend istream& operator>>(istream&, ActiviteSupplementaire&);
        friend ostream& operator<<(ostream&, ActiviteSupplementaire&);
    };