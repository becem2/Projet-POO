#include "Allergie.h"




Allergie::Allergie() : TypeAllergie(""){}
Allergie::Allergie(const string& TypeAllergie) : TypeAllergie(TypeAllergie){}
Allergie::~Allergie(void){}
void Allergie::SetTypeAllergie(const string& t){
    TypeAllergie = t;
}
string Allergie::GetTypeAllergie(){ return TypeAllergie;}