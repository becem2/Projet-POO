#include"creche.cpp"

int main() {
    Creche creche;
    string firstChoix;
    string Choix;
    cout<<"Do you want to add a child or a test"<<endl;
    cin>>firstChoix;
    if (firstChoix == "yes"){
        do{
            cout<<"Enfant ou Babysitter ?"<<endl;;
            cin>>Choix;
            if (Choix == "enfant"){
                string ChoixAjout;
                do{
                    int ChoixEnfant;
                    cout<<"Enfant normal ou Enfant en permenance ?"<<endl;
                    cin>>ChoixEnfant;
                    string nom,prenom,specifineeds;
                    int age,dureePermenance;
                    vector <Allergie*> allergie;

                    if (ChoixEnfant == 1){
                        cout<<"Saisire le nom "<<endl;
                        cin>>nom;
                        cout<<"Saisire le prenom "<<endl;
                        cin>>prenom;
                        cout<<"Saisire l'age  "<<endl;
                        cin>>age;
                        cout<<"Saisire le specific needs "<<endl;
                        cin>>specifineeds;
                        Enfant e(nom,prenom,age,specifineeds);
                        string ChoixAllergie;
                        do{
                            string aller;
                            cout<<"Saisire l'allergie' "<<endl;
                            cin>>aller;
                            cout<<"add an other allergie?"<<endl;
                            cin>>ChoixAllergie;
                            Allergie a(aller);
                            e.ajouterAllergie(&a);
                        }while(ChoixAllergie == "oui");
                        creche.ajouterEnfant(&e);
                    }

                    else if (ChoixEnfant == 2){
                        cout<<"Saisire le nom "<<endl;
                        cin>>nom;
                        cout<<"Saisire le prenom "<<endl;
                        cin>>prenom;
                        cout<<"Saisire l'age  "<<endl;
                        cin>>age;
                        cout<<"Saisire le specific needs "<<endl;
                        cin>>specifineeds;
                        cout<<"Saisire duree permenance"<<endl;
                        cin>>dureePermenance;
                        EnfantEnPermanence e(nom,prenom,age,dureePermenance,specifineeds);
                        string ChoixAllergie;
                        do{
                            string aller;
                            cout<<"Saisire l'allergie' "<<endl;
                            cin>>aller;
                            cout<<"add an other allergie?"<<endl;
                            cin>>ChoixAllergie;
                            Allergie a(aller);
                            e.ajouterAllergie(&a);
                        }while(ChoixAllergie == "oui");
                    }
                    cout<<"would u like to add an other child"<<endl;
                    cin>>ChoixAjout;
                }while(ChoixAjout == "yes");
            }

            else if (Choix == "babysitter"){



                string ChoixAjout;
                do{
                    int ChoixBabysitte;
                    cout<<"Babysitter normal ou Babysitter en jour ?"<<endl;
                    cin>>ChoixBabysitte;
                    string nom,numerotelephone,horairetravail;
                    int age;
                    double salaireHoraire;

                    if (ChoixBabysitte == 1){
                        cout<<"Saisire le nom "<<endl;
                        cin>>nom;
                        cout<<"Saisire le prenom "<<endl;
                        cin>>numerotelephone;
                        cout<<"Saisire l'age  "<<endl;
                        cin>>age;
                        cout<<"Saisire le specific needs "<<endl;
                        cin>>salaireHoraire;
                        BabySitter b(nom,age,numerotelephone,salaireHoraire);
                        creche.ajouterBabysitter(&b);
                    }

                    else if (ChoixBabysitte == 2){
                        cout<<"Saisire le nom "<<endl;
                        cin>>nom;
                        cout<<"Saisire le numero de telephone "<<endl;
                        cin>>numerotelephone;
                        cout<<"Saisire l'age  "<<endl;
                        cin>>age;
                        cout<<"Saisire la salaire horaire "<<endl;
                        cin>>salaireHoraire;
                        cout<<"Saisire le horaire du travail  "<<endl;
                        cin>>horairetravail;
                        BabySitterJour b(nom,age,numerotelephone,salaireHoraire,horairetravail);
                        creche.ajouterBabysitter(&b);
                    }
                    cout<<"would u like to add an other Babysitter?"<<endl;
                    cin>>ChoixAjout;
                }while(ChoixAjout == "yes");

            }
        }while(Choix !="enfant" || Choix !="babysitter");
    }




    //Menu : 
    int ChoixMenu;
    do
    {   
        cout<<"*****************Menu*****************"<<endl;
        cout<<"1. Modification"<<endl;
        cout<<"2. Traitement"<<endl;
        cout<<"Type ur choice : ";
        cin>>ChoixMenu;
        switch (ChoixMenu)
        {
        case 1:
            int ChoixModification;
            do{

                cout<<"*******************Modification***************"<<endl;
                cout<<"1. Affichage Enfant"<<endl;
                cout<<"2. Affichage EnfantEnPermenance"<<endl;
                cout<<"3. Affichage Test"<<endl;
                switch(ChoixModification){
                    case 1 :
                        break;
                    case 2 :
                        break;
                    case 3 :
                        break;
                    default:
                        break;
                }
            }while(ChoixModification != 9);
            
            break;
        case 2:
            
            int ChoixTraitement;
            do{ 
                
                cout<<"*********************Traitement*************"<<endl;
                cout<<"1. plus grand enfant"<<endl;
                cout<<"2. allergie specifiee"<<endl;
                cout<<"3. "<<endl;
                cout<<"4."<<endl;
                cout<<"5."<<endl;
                cin>>ChoixTraitement;
                switch(ChoixTraitement){
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    default:
                        break;
                }
            }while(ChoixTraitement != 9);
            break;
        
        default:
            break;
        }
    } while (ChoixMenu != 9);
    return 0;
}