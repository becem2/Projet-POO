#include "Permenance.h"

Permenance::Permenance() : DateDebut({0,0,0}) , DateFin({0,0,0}) {}
Permenance::Permenance(date dd,date df) : DateDebut(dd) , DateFin(df){}
date Permenance::GetDateDebut(){return DateDebut;}
date Permenance::GetDateFin(){return DateFin;}
void Permenance::SetDateDebut(int j,int m,int a){
    DateDebut.jour = j;
    DateDebut.mois = m;
    DateDebut.annee = a;
}
void Permenance::SetDateFin(int j,int m,int a){
    DateFin.jour = j;
    DateFin.mois = m;
    DateFin.annee = a;
}
Permenance::~Permenance(void){}

