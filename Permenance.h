#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct date{
    int jour;
    int mois;
    int annee;

};
typedef struct date DATE;
class Permenance {
    protected:
        date DateDebut;
        date DateFin;

    public:
    Permenance();
    Permenance(date,date);
    date GetDateDebut();
    date GetDateFin();
    void SetDateDebut(int,int,int);
    void SetDateFin(int,int,int);
    ~Permenance();
};