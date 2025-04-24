#include "Creche.cpp"

int main() {
    int ChoixEnfantOuEmployee;
    Creche c;

    do {
        cout << "Vous-voulez ajouter un Enfant ou un Employee (Enfant = 1 , Employee = 2 , Tapez 9 pour acceder au menu principal) : ";
        cin >> ChoixEnfantOuEmployee;

        if (ChoixEnfantOuEmployee == 1) {
            cout << "\n*********** Ajouter un Enfant **********\n";
            int ChoixEnfant;

            do {
                cout << "Vous-voulez ajouter un Enfant Normal, En Permenance ou avec une Allergie (1 = Normal, 2 = Permenance, 3 = Allergie) : ";
                cin >> ChoixEnfant;

                if (ChoixEnfant == 1) {
                    cout << "\n*********** Ajouter un Enfant Normal **********\n";
                    Enfant* e = new Enfant;
                    e->saisirEnfant();
                    c.AjouterEnfant(e);
                    e->afficher();

                    ChoixEnfantOuEmployee = -1;
                } else if (ChoixEnfant == 2) {
                    cout << "\n*********** Ajouter un Enfant En Permenance **********\n";
                    EnfantPermanence* e = new EnfantPermanence();
                    e->saisirEnfant();
                    c.AjouterEnfant(e);
                    e->afficher();
                    ChoixEnfantOuEmployee = -1;
                } else if (ChoixEnfant == 3) {
                    cout << "\n*********** Ajouter un Enfant Avec une Allergie **********\n";
                    EnfantAvecAllergie* e = new EnfantAvecAllergie();
                    e->saisirEnfant();
                    c.AjouterEnfant(e);
                    e->afficher();
                    ChoixEnfantOuEmployee = -1;
                }

            } while (ChoixEnfant != 1 && ChoixEnfant != 2 && ChoixEnfant != 3);
        } else if (ChoixEnfantOuEmployee == 2) {
            cout << "\n*********** Ajouter un Employee **********\n";
            int ChoixEmployee;

            do {
                cout << "Vous-voulez ajouter un Employee Normal ou Bureautique (1 = Normal, 2 = Bureautique) : ";
                cin >> ChoixEmployee;

                if (ChoixEmployee == 1) {
                    cout << "\n*********** Ajouter un Employee Normal **********\n";
                    employee* e = new employee();
                    e->saisirEmployee();
                    c.AjouterEmployee(e);
                    e->afficherInfos();

                    ChoixEnfantOuEmployee = -1;
                } else if (ChoixEmployee == 2) {
                    cout << "\n*********** Ajouter un Employee Bureautique **********\n";
                    employeebureautique* e = new employeebureautique();
                    e->saisirEmployee();
                    c.AjouterEmployee(e);
                    e->afficherInfos();

                    ChoixEnfantOuEmployee = -1;
                }

            } while (ChoixEmployee != 1 && ChoixEmployee != 2);
        }

    } while (ChoixEnfantOuEmployee != 9);


















    // Menu Principal






    int ChoixMenuPrincipale;

    do {
        cout << "\n***************** Menu Principal *************\n";
        cout << "1. Modification\n";
        cout << "2. Affichage\n";
        cout << "3. Traitement\n";
        cout << "9. Fermeture du programme\n";
        cin >> ChoixMenuPrincipale;

        if (ChoixMenuPrincipale == 1) {
            if (ChoixMenuPrincipale == 1) {
                int ChoixModification;
                do {
                    cout << "***************** Menu Modification *************\n";
                    cout << "1. Employee Normal\n";
                    cout << "2. Employee Bureautique\n";
                    cout << "3. Enfant Normal\n";
                    cout << "4. Enfant En Permenance\n";
                    cout << "5. Enfant Avec Allergie\n";
                    cout << "9. Retour\n";
                    cin >> ChoixModification;
            
                    if (ChoixModification >= 1 && ChoixModification <= 5) {
                        int action;
                        cout << "1. Modifier\n2. Ajouter\n3. Supprimer\n9. Retour\n";
                        cin >> action;
            
                        switch (action) {
                            case 1:
{
    int choixModification;
    do {
        cout << "\n=== MENU MODIFICATION ===" << endl;
        cout << "1. Modifier un employe normal" << endl;
        cout << "2. Modifier un employe bureautique" << endl;
        cout << "3. Modifier un enfant normal" << endl;
        cout << "4. Modifier un enfant en permanence" << endl;
        cout << "5. Modifier un enfant avec allergie" << endl;
        cout << "9. Retour" << endl;
        cout << "Choix : ";
        cin >> choixModification;

        string nom;
        switch (choixModification) {
            case 1:
            case 2:
            {
                c.afficherEmployees();
                cout << "Entrez le nom de l'employe a modifier: ";
                cin >> nom;
                employee* emp = c.trouverEmployee(nom);
                if (emp) {
                    cout << "\nAnciennes informations:" << endl;
                    emp->afficherInfos();
                    
                    cout << "\nNouvelles informations:" << endl;
                    emp->saisirEmployee();
                    if (choixModification == 2) {
                        if (auto empBureau = dynamic_cast<employeebureautique*>(emp)) {
                            string tache;
                            cout << "Nouvelle tache bureautique: ";
                            cin >> tache;
                            empBureau->setTache(tache);
                        }
                    }
                    cout << "Employe modifie avec succes!" << endl;
                } else {
                    cout << "Employe non trouve!" << endl;
                }
                break;
            }
            case 3: 
            case 4:
            case 5:
            {
                c.afficherEnfants();
                cout << "Entrez le nom de l'enfant a modifier: ";
                cin >> nom;
                Enfant* enf = c.trouverEnfant(nom);
                if (enf) {
                    cout << "\nAnciennes informations:" << endl;
                    enf->afficher();
                    
                    cout << "\nNouvelles informations:" << endl;
                    enf->saisirEnfant();
                    
                    if (choixModification == 4) {
                        if (auto enfPerm = dynamic_cast<EnfantPermanence*>(enf)) {
                            string heure;
                            cout << "Nouvelle heure de fin: ";
                            cin >> heure;
                            enfPerm->setFinPermanence(heure);
                        }
                    } else if (choixModification == 5) {
                        if (auto enfAllergie = dynamic_cast<EnfantAvecAllergie*>(enf)) {
                            string allergie;
                            cout << "Nouveau type d'allergie: ";
                            cin >> allergie;
                            enfAllergie->setTypeAllergie(allergie);
                        }
                    }
                    cout << "Enfant modifie avec succes!" << endl;
                } else {
                    cout << "Enfant non trouve!" << endl;
                }
                break;
            }
            case 9:
                cout << "Retour au menu precedent..." << endl;
                break;
            default:
                cout << "Choix invalide!" << endl;
        }
    } while (choixModification != 9);
    break;
}
                                case 2:
                                {
                                    int choixAjout;
                                    do {
                                        cout << "\n=== Menu Ajout ===" << endl;
                                        cout << "1. Ajouter un employe normal" << endl;
                                        cout << "2. Ajouter un employe bureautique" << endl;
                                        cout << "3. Ajouter un enfant normal" << endl;

                                        cout << "4. Ajouter un enfant en permanence" << endl;
                                        cout << "5. Ajouter un enfant avec allergie" << endl;
                                        cout << "9. Retour" << endl;
                                        cout << "Choix : ";
                                        cin >> choixAjout;
                                
                                        switch (choixAjout) {
                                            case 1: {
                                                employee* emp = new employee();
                                                emp->saisirEmployee();
                                                c.AjouterEmployee(emp);
                                                cout << "Employe normal ajoute avec succes!" << endl;
                                                break;
                                            }
                                            case 2: {
                                                employeebureautique* empBureau = new employeebureautique();
                                                empBureau->saisirEmployee();
                                                c.AjouterEmployee(empBureau);
                                                cout << "Employe bureautique ajoute avec succes!" << endl;
                                                break;
                                            }
                                            case 3: {
                                                Enfant* enfant = new Enfant();
                                                enfant->saisirEnfant();
                                                c.AjouterEnfant(enfant);
                                                cout << "Enfant normal ajoute avec succes!" << endl;
                                                break;
                                            }
                                            case 4: {
                                                EnfantPermanence* enfantPerm = new EnfantPermanence();
                                                enfantPerm->saisirEnfant();
                                                c.AjouterEnfant(enfantPerm);
                                                cout << "Enfant en permanence ajoute avec succes!" << endl;
                                                break;
                                            }
                                            case 5: {
                                                EnfantAvecAllergie* enfantAllergie = new EnfantAvecAllergie();
                                                enfantAllergie->saisirEnfant();
                                                c.AjouterEnfant(enfantAllergie);
                                                cout << "Enfant avec allergie ajoute avec succes!" << endl;
                                                break;
                                            }
                                            case 9:
                                                cout << "Retour au menu precedent..." << endl;
                                                break;
                                            default:
                                                cout << "Choix invalide!" << endl;
                                        }
                                    } while (choixAjout != 9);
                                    break;
                                }
                                case 3:
                                {
                                    int choixSuppression;
                                    do {
                                        cout << "\n=== MENU SUPPRESSION ===" << endl;
                                        cout << "1. Supprimer un employe" << endl;
                                        cout << "2. Supprimer un enfant" << endl;
                                        cout << "9. Retour" << endl;
                                        cout << "Choix : ";
                                        cin >> choixSuppression;
                                
                                        switch (choixSuppression) {
                                            case 1: {
                                                c.afficherListeEmployees();
                                                if (!c.employees.empty()) {
                                                    string nom;
                                                    cout << "Entrez le nom de l'employe a supprimer: ";
                                                    cin >> nom;
                                                    if (c.supprimerEmployee(nom)) {
                                                        cout << "Employe supprime avec succes!" << endl;
                                                    } else {
                                                        cout << "Employe non trouve!" << endl;
                                                    }
                                                }
                                                break;
                                            }
                                            case 2: {
                                                c.afficherListeEnfants();
                                                if (!c.enfants.empty()) {
                                                    string nom;
                                                    cout << "Entrez le nom de l'enfant a supprimer: ";
                                                    cin >> nom;
                                                    if (c.supprimerEnfant(nom)) {
                                                        cout << "Enfant supprime avec succes!" << endl;
                                                    } else {
                                                        cout << "Enfant non trouve!" << endl;
                                                    }
                                                }
                                                break;
                                            }
                                            case 9:
                                                cout << "Retour au menu precedent..." << endl;
                                                break;
                                            default:
                                                cout << "Choix invalide!" << endl;
                                        }
                                    } while (choixSuppression != 9);
                                    break;
                                }
                            case 9:
                                break;
                            default:
                                cout << "Choix invalide.\n";
                        }
                    } else if (ChoixModification != 9) {
                        cout << "Choix invalide.\n";
                    }
            
                } while (ChoixModification != 9);
            }
            

        } else if (ChoixMenuPrincipale == 2) {
            int ChoixAffichage;
            do {
                cout << "***************** Menu Affichage *************\n";
                cout << "1. Affichage du Employee Normal\n";
                cout << "2. Affichage du Employee Bureautique\n";
                cout << "3. Affichage du Enfant Normal\n";
                cout << "4. Affichage du Enfant En Permenance\n";
                cout << "5. Affichage du Enfant Avec une Allergie\n";
                cout << "9. Retour\n";
                cin >> ChoixAffichage;
        
                switch (ChoixAffichage) {
                    case 1:
                        cout << ">> Affichage des Employees Normaux <<\n";
                        c.afficherEmployeesNormaux();
                        
                        


                        break;
                    case 2:
                        cout << ">> Affichage des Employees Bureautiques <<\n";
                        c.afficherEmployeesBureautiques();
                        
                        


                        break;
                    case 3:
                        cout << ">> Affichage des Enfants Normaux <<\n";
                        c.afficherEnfantsNormaux();
                       
                        


                        break;
                    case 4:
                        cout << ">> Affichage des Enfants en Permenance <<\n";
                        c.afficherEnfantsPermanence();
                        
                        


                        break;
                    case 5:
                        cout << ">> Affichage des Enfants avec Allergies <<\n";
                        c.afficherEnfantsAllergies();
                        
                        



                        break;
                    case 9:
                        cout << "Retour au menu principal.\n";
                        break;
                    default:
                        cout << "Choix invalide, reessayez.\n";
                }
            } while (ChoixAffichage != 9);
        

        } else if (ChoixMenuPrincipale == 3) {
            cout << "***************** Menu Traitement *************\n";
            cout << "1. Combient d'enfant en Permenance\n";
            cout << "2. Salaire d'un employee\n";
            cout << "3. Les enfant ayant une allergie specifier\n";
            cout << "4. Enfant plus agee\n";
            cout << "5. Afficher les enfant moins de 10 ans\n";

            int ChoixTraitement;
            cin >> ChoixTraitement;

            switch (ChoixTraitement) {
                case 1:
                    
                    {
                        cout << "Traitement: Combient d'enfant en permenance : \n";
                        int nbEnfantsPerm = c.compterEnfantsPermanence();
                        cout << "\n=== RESULTAT DU TRAITEMENT ===" << endl;
                        cout << "Nombre d'enfants en permanence: " << nbEnfantsPerm << endl;
                        cout << "\nPourcentage: " 
                             << (c.enfants.empty() ? 0 : (nbEnfantsPerm * 100 / c.enfants.size())) 
                             << "%" << endl;
                        break;
                    }


                    break;
                case 2:
                    
                    {
                        c.afficherEmployees();
                        cout << "Traitement: Salaire d'un employee\n";
                        
                        if (!c.employees.empty()) {
                            string nom;
                            double heures;
                            
                            cout << "Entrez le nom de l'employe: ";
                            cin >> nom;
                            
                            cout << "Entrez le nombre d'heures travaillees: ";
                            cin >> heures;
                            
                            employee* emp = c.trouverEmployee(nom);
                            if (emp) {
                                double salaire = emp->calculerSalaire(heures);
                                
                                cout << "\n=== CALCUL DE SALAIRE ===" << endl;
                                cout << "Employe: " << emp->getNom() << endl;
                                cout << "Taux horaire: " << emp->getSalaireHoraire() << " €" << endl;
                                
                                if (dynamic_cast<employeebureautique*>(emp)) {
                                    cout << "Type: Employe bureautique (avec bonus 20%)" << endl;
                                } else {
                                    cout << "Type: Employe normal" << endl;
                                }
                                
                                cout << "Heures travaillees: " << heures << endl;
                                cout << "Salaire total: " << salaire << " €" << endl;
                            } else {
                                cout << "Employe non trouve!" << endl;
                            }
                        }
                        break;
                    }


                    break;
                case 3:
                    cout << "Traitement: Enfants ayant une allergie specifier 3\n";
                    {
                        string allergieRecherche;
                        cout << "\nEntrez le type d'allergie a rechercher: ";
                        cin.ignore();
                        getline(cin, allergieRecherche);
                        
                        c.listerEnfantsAvecAllergie(allergieRecherche);
                        break;
                    }


                    break;
                case 4:
                    
                    {
                        cout << "Traitement: Enfant plus agee\n";
                        c.afficherPlusVieuxEnfant();
                        break;
                    }


                    break;
                case 5:
                    
                    {
                        cout << "Traitement: Enfant moins de 10 ans\n";
                        c.listerEnfantsMoinsDe10Ans();
                        break;
                    }


                    break;
                default:
                    cout << "Choix invalide\n";
                    break;
            }
        }

    } while (ChoixMenuPrincipale != 9);

    system("PAUSE");
    return 0;
}
