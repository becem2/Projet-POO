#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ActiviteSupplementaire{
    private:
        string nomActivite;
    public:
        ActiviteSupplementaire();
        ActiviteSupplementaire(string nom);
        ~ActiviteSupplementaire();
        void afficher();
    };