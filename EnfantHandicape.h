#include "Enfant.cpp"

class EnfantHandicape : public Enfant{
    private:
        int TypeMaladie;
    public:
        EnfantHandicape();
        EnfantHandicape(Enfant,int);
        EnfantHandicape(int,string,string,DATE,int);
        void Afficher(); 
        void SetTypeMaladie(int);
        int GetTypeMaladie();
        ~EnfantHandicape();
        
};