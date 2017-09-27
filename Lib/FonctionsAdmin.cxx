#include "FonctionsAdmin.h"
#include "MaListeTriee.h"
#include "Iterateur.h"
#include "Pause.h"

#include <iostream>
#include <cstdlib>

using namespace std;

char menuAdmin()
{
    char ch;
    do
    {
        cout << endl;
        cout << "***************************************" << endl;
        cout << "***                                 ***" << endl;
        cout << "*** MySailingWorld - Administrateur ***" << endl;
        cout << "***                                 ***" << endl;
        cout << "***************************************" << endl << endl;
        cout << " 1. Afficher la liste des utilisateurs" << endl;
        cout << " 2. Afficher les infos d'un utilisateur" << endl;
        cout << " 3. Creer un utilisateur" << endl;
        cout << " 4. Changer un mot de passe" << endl << endl;
        cout << " N. Nouvelle Session" << endl;
        cout << " Q. Quitter l'application" << endl << endl;

        cout << "  Choix : ";
        cin >> ch;
    }
    while ((ch < '1' || ch > '4') && ch != 'N' && ch != 'Q');

    return ch;
}

void choixMenuAdmin(char c, MaListeTriee<User> &lUser, FichierUsers &fichierUsr)
{
    switch(c)
    {
        case '1':
            system("clear");
            if (lUser.isEmpty())
                cout << "La liste des utilisateurs est vide !" << endl << endl;
            else
            {
                cout << "**** Liste des utilisateurs *****" << endl << endl;
                afficheUsers(lUser);
            }
        break;

        case '2':
            system("clear");
            if (lUser.isEmpty())
                cout << "La liste des utilisateurs est vide !" << endl << endl;
            else
			{
				afficheUser(lUser);
                cout << endl;
			}
        break;

        case '3':
            system("clear");
            cout << "*** Creation d'un nouvel utilisateur ***" << endl << endl;
            creerUser(lUser, fichierUsr);
			cout << endl;
        break;

        case '4':
            system("clear");
            if (lUser.isEmpty())
                cout << "La liste des utilisateurs est vide !" << endl << endl;
            else
            {
				cout << "*** Changement de votre mot de passe ***" << endl << endl;
                changerMDP(lUser, fichierUsr);
            }
        break;

        default: cout << "Vous n'avez pas entre un bon numero du menu ..." << endl;
        break;
    }
    Pause();
}

void afficheUsers(MaListeTriee<User> &lUser)
{
    lUser.affiche();
}
void afficheUser(MaListeTriee<User> &lUser)
{
    string log;

    cout << "Entrez le login de l'utilisateur dont vous voulez afficher les informations: " << endl;
    cin >> log;

    User UsrRecherche(log);

    if (lUser.contenir(UsrRecherche))
    {
        UsrRecherche = lUser.recupererObjet(UsrRecherche);
        UsrRecherche.Affiche();
    }
    else
        cout << endl << "Cet utilisateur n'existe pas !" << endl << endl;
}
void creerUser(MaListeTriee<User> &lUser, FichierUsers &fichierUsr)
{
    User NewUsr;
    cin >> NewUsr;

    if (lUser.contenir(NewUsr))
        cout << "Le login que vous venez d'entrer existe deja !" << endl;
    else
    {
        lUser.inserer(NewUsr);

        fichierUsr.save(NewUsr);

        if (lUser.contenir(NewUsr))
            cout << "L'utilisateur a bien ete enregistre !" << endl;
        else
            cout << "Erreur lors de la creation de nouvel utilisateur" << endl;
    }
}
void changerMDP(MaListeTriee<User> &lUser, FichierUsers &fichierUsr)
{
    string log;

    cout << "Entrez le login de l'utilisateur dont vous voulez afficher les informations: " << endl;
    cin >> log;

    User UsrRecherche(log);

    if (lUser.contenir(UsrRecherche))
    {
        UsrRecherche = lUser.recupererObjet(UsrRecherche);
        string mdpActuel, mdpNew, mdpConfirme;

        cout << "Entrez votre mot de passe actuel: ";
        cin >> mdpActuel;

        if (UsrRecherche.getMotDePasse() == mdpActuel)
        {
            cout << "Entrez votre nouveau mot de passe: ";
            cin >> mdpNew;
            cout << "Confirmez votre mot de passe: ";
            cin >> mdpConfirme;

            if (mdpNew == mdpConfirme)
            {
                lUser.supprimer(UsrRecherche);
                UsrRecherche.setMotDePasse(mdpNew);
                lUser.inserer(UsrRecherche);

                ofstream f("User.dat", ios::out | ios::trunc | ios::binary);

                if (f.is_open())
                {
                    int iNbreEnreg = 0;
                    f.write((char*) &iNbreEnreg, sizeof(int));
                    f.close();
                }

                Iterateur<User> it = lUser.getIterateur();

                while(it.hasNext())
                {
                    UsrRecherche = it.next();
                    fichierUsr.save(UsrRecherche);
                }
            }
            else
                cout << endl << "Le nouveau mot de passe n'a pas ete confirme !" << endl << endl;
        }
        else
            cout << endl << "Le mot de passe entre ne correspond pas a votre mot de passe actuel !" << endl << endl;
    }
    else
        cout << endl << "Cet utilisateur n'existe pas !" << endl << endl;
}
