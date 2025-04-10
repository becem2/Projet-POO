#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;


class Allergie {
    protected:
        string TypeAllergie;
    public:
    Allergie();
    Allergie(const string&);
    ~Allergie();
    void SetTypeAllergie(const string&);
    string GetTypeAllergie();
};