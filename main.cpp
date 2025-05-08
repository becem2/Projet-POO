#include "Creche.cpp"
int main() {
    int ChoixEnfantOuEmployee;
    Creche c;
    do {
        cout << "Vous-voulez ajouter un Enfant ou un Employee (Enfant = 1 , Employee = 2 , Tapez 9 pour acceder au menu principal) : ";
        cin >> ChoixEnfantOuEmployee;
        if (ChoixEnfantOuEmployee == 1) {
            int ChoixEnfant;
            do {
                cout << "Vous-voulez ajouter un Enfant Normal, En Permenance ou avec une Allergie (1 = Normal, 2 = Permenance, 3 = Allergie) : ";
                cin >> ChoixEnfant;
                if (ChoixEnfant == 1) {
                    Enfant* e = new Enfant;
                    e->saisirEnfant();
                    c.AjouterEnfant(e);
                    ChoixEnfantOuEmployee = -1;
                } else if (ChoixEnfant == 2) {
                    EnfantPermanence* e = new EnfantPermanence();
                    e->saisirEnfant();
                    c.AjouterEnfant(e);
                    ChoixEnfantOuEmployee = -1;
                } else if (ChoixEnfant == 3) {
                    EnfantAvecAllergie* e = new EnfantAvecAllergie();
                    e->saisirEnfant();
                    c.AjouterEnfant(e);
                    ChoixEnfantOuEmployee = -1;
                }
            } while (ChoixEnfant != 1 && ChoixEnfant != 2 && ChoixEnfant != 3);
        } else if (ChoixEnfantOuEmployee == 2) {
            int ChoixEmployee;
            do {
                cout << "Vous-voulez ajouter un Employee Normal ou Bureautique (1 = Normal, 2 = Bureautique) : ";
                cin >> ChoixEmployee;
                if (ChoixEmployee == 1) {
                    Employee* e = new Employee();
                    e->saisirEmployee();
                    c.AjouterEmployee(e);
                    ChoixEnfantOuEmployee = -1;
                } else if (ChoixEmployee == 2) {
                    EmployeeBureautique* e = new EmployeeBureautique();
                    e->saisirEmployee();
                    c.AjouterEmployee(e);
                    ChoixEnfantOuEmployee = -1;
                }
            } while (ChoixEmployee != 1 && ChoixEmployee != 2);
        }
    } while (ChoixEnfantOuEmployee != 9);
    int choix;
    cout << "=== BIENVENUE DANS LE SYSTEME DE GESTION DE CRECHE ===" << endl;
    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Ajouter" << endl;
        cout << "2. Supprimer" << endl;
        cout << "3. Afficher" << endl;
        cout << "4. Traitement" << endl;
        cout << "9. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choix;
        switch (choix) {
            case 1: {
                int ajoutChoix;
                cout << "\n--- MENU AJOUT ---" << endl;
                cout << "1. Ajouter un enfant normal" << endl;
                cout << "2. Ajouter un enfant en permanence" << endl;
                cout << "3. Ajouter un enfant avec allergie" << endl;
                cout << "4. Ajouter un employe normal" << endl;
                cout << "5. Ajouter un employe bureautique" << endl;
                cout << "Choix: ";
                cin >> ajoutChoix;
                switch (ajoutChoix){
                    case 1:{
                        Enfant* en = new Enfant;
                        en->saisirEnfant();
                        c.AjouterEnfant(en);
                        break;}
                    case 2 :{
                        EnfantPermanence* ep = new EnfantPermanence();
                        ep->saisirEnfant();
                        c.AjouterEnfant(ep);                         
                        break;}
                    case 3:{
                        EnfantAvecAllergie* ea = new EnfantAvecAllergie();
                        ea->saisirEnfant();
                        c.AjouterEnfant(ea); 
                        break;}
                    case 4 :{
                        Employee* em = new Employee();
                        em->saisirEmployee();
                        c.AjouterEmployee(em);
                        break;}
                    case 5:{
                        EmployeeBureautique* eb = new EmployeeBureautique();
                        eb->saisirEmployee();
                        c.AjouterEmployee(eb);
                        break;}
                    default:    
                        cout<<"Tapez un choix correct !!"<<endl;
                        break;
                }
                break;
            }
            case 2: {
                int suppChoix;
                cout << "\n--- MENU SUPPRESSION ---" << endl;
                cout << "1. Supprimer un enfant" << endl;
                cout << "2. Supprimer un employe" << endl;
                cout << "Choix: ";
                cin >> suppChoix;
                switch (suppChoix)
                {
                case 1:{
                    string nom;
                    cout<<"Tapez le nom de l'enfant que vous voulez supprimez : ";
                    cin>>nom;
                    c.supprimerEnfant(nom);
                    break;}
                case 2:{
                    string nom;
                    cout<<"Tapez le nom de l'employee que vous voulez supprimez : ";
                    cin>>nom;
                    c.supprimerEmployee(nom);
                    break;}
                default:    
                    cout<<"Tapez un choix correct !!"<<endl;
                    break;
                }
                break;
            }
            case 3: {
                int affChoix;
                cout << "\n--- MENU AFFICHAGE ---" << endl;
                cout << "1. Enfants normaux" << endl;
                cout << "2. Enfants en permanence" << endl;
                cout << "3. Enfants avec allergies" << endl;
                cout << "4. Employes normaux" << endl;
                cout << "5. Employes bureautiques" << endl;
                cout << "Choix: ";
                cin >> affChoix;
                switch (affChoix)
                {
                case 1:
                    c.afficherEnfantsNormaux();
                    break;
                case 2:
                    c.afficherEnfantsPermanence();
                    break;
                case 3:
                    c.afficherEnfantsAllergies();
                    break;
                case 4:
                    c.afficherEmployeesNormaux();
                    break;
                case 5:
                    c.afficherEmployeesBureautiques();
                    break;
                default:    
                    cout<<"Tapez un choix correct !!"<<endl;
                    break;
                }
                break;
            }
            case 4: {
                int trtChoix;
                cout << "\n--- MENU TRAITEMENT ---" << endl;
                cout << "1. Lister enfants avec allergie" << endl;
                cout << "2. Afficher le plus vieux enfant" << endl;
                cout << "3. Enfants de moins de 10 ans" << endl;
                cout << "4. Compter enfants en permanence" << endl;
                cout << "5. Afficher le plus employee salarie" << endl;
                cout << "Choix: ";
                cin >> trtChoix;
                switch (trtChoix)
                {
                case 1:{
                    string allergie;
                    cout<<"Tapez une allergie : ";
                    cin>>allergie;
                    c.listerEnfantsAvecAllergie(allergie);
                }
                    break;
                case 2:
                    c.afficherPlusVieuxEnfant();
                    break;
                case 3:
                    c.listerEnfantsMoinsDe10Ans();
                    break;
                case 4:
                    c.compterEnfantsPermanence();
                    break;
                case 5:
                    c.afficherEmployeePlusHautSalaire();
                    break;
                default:
                    break;
                }
                break;
            }
            case 9:
                cout << "Merci d'avoir utilise le systeme de gestion de creche." << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    } while (choix != 5);
    return 0;
}