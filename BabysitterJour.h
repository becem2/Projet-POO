#include "Babysitter.cpp"



class BabySitterJour : public BabySitter {
    private:
        string horaireTravail; 
    public:
        
        BabySitterJour(string n, int a, string tel, double salaire, string horaire);
    
       
        void afficherInfos() const;
    
        void donnerRepas() ;
    
        void changerCouches() ;
    };