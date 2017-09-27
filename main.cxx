/* Include des fonctions/classes cr��es */
#include "FichierUsers.h"
#include "User.h"
#include "Regate.h"
#include "MaListeTriee.h"
#include "FonctionsAdmin.h"
#include "FonctionsClub.h"
#include "FonctionsRegate.h"
#include "Concurrent.h"
#include "Pause.h"

/* Includes des diff�rentes fonctions/classes pr�d�finies utilis�es */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    int iQuitter = 1;
    User usrConnexion;
    MaListeTriee<User> lTUser;
    while (iQuitter)
    {
        system("clear");
        int connexion = 0;
        while (connexion != 1)
        {
            fstream fc("User.dat", ios::in | ios::out |ios::binary); // Bidonnage du fichier User.dat
            if (!fc.is_open())
            {
                FichierUsers fichierUsr("User.dat");
                fichierUsr.save(usrConnexion);
            }
            fc.close();
            FichierUsers fichierUsr("User.dat");
            fichierUsr.load(lTUser); // Initialisation de la liste tri�e des User
            cout << "*** Bienvenue dans MySailingWorld ***" << endl << endl;

            string log, mdp;

            cout << "Nom d'utilisateurs: ";
            cin >> log;
            cout << "Mot de passe: ";
            cin >> mdp;

            User userAdmin(log, mdp);

            if (lTUser.contenir(userAdmin)) // Recherche l'objet User qui correspond au login entr� � la connexion
            {
                usrConnexion = lTUser.recupererObjet(userAdmin); // Si le login entr� � la connexion existe dans la liste, on r�cup�re l'objet entier

                if (userAdmin.getMotDePasse() == usrConnexion.getMotDePasse())
                    connexion = 1;
                else
                    cout << "Mot de passe errone !" << endl;
            }
            else
                cout << "Login errone ou inexistant !" << endl;
        }
        cout << "Connexion reussie !" << endl << endl;

        int iNouvelleSession = 1;

        Pause();

        while (iNouvelleSession)
        {
            system("clear");
            char c = '\0';

            if (usrConnexion.getRole() == "admin")
            {
                c = menuAdmin();

                if (c > '0' && c < '5')
                {
                    FichierUsers fichierUsr("User.dat"); // D�claration d'un objet FichierUsers car le pr�c�dent � �t� d�truit (port�e des objets ...)
                    choixMenuAdmin(c, lTUser, fichierUsr);
                }
            }

            if (usrConnexion.getRole() == "club")
            {
                string nomFichierClub = "ClubDeVoile" + usrConnexion.getLogin() + ".rgt"; // Nom du fichier du club de voile = concat�nation ClubDeVoile + login du user connect�
                FichierRegates fichierReg(nomFichierClub.c_str()); // Cr�ation/r�cup�ration du fichier correspondant au club de voile du user
                MaListeTriee<Regate> lTRegate;
                fichierReg.load(lTRegate); // Initialisation de la liste des r�gates
                MaListeTriee<Concurrent> lTConcurrent;

                while (c != 'N' && c != 'n' && c != 'Q' && c != 'q')
                {
                    c = menuClub();
                    if (c > '0' && c < '4')
                        choixMenuClub(c, lTRegate, fichierReg, lTConcurrent);
                }
            }

            if (c == 'N' || c == 'n')
            {
                do
                {
                    cout << "Voulez-vous vraiment demarrer une nouvelle session ?" << endl;
                    cout << "\tTaper 0 pour demarrer une nouvelle session." << endl;
                    cout << "\t      1 pour annuler et retourner au menu." << endl;
                    cout << endl << "Votre choix : ";
                    cin >> iNouvelleSession;
                }
                while (iNouvelleSession < 0 || iNouvelleSession > 1);
            }
            if (c == 'Q' || c == 'q')
            {
                do
                {
                    cout << "Voulez-vous vraiment quitter l'application MySailingWorld ?" << endl;
                    cout << "\tTaper 0 pour quitter l'application." << endl;
                    cout << "\t      1 pour annuler et retourner au menu." << endl;
                    cout << endl << "Votre choix : ";
                    cin >> iQuitter;

                    if (!iQuitter)
                        iNouvelleSession = 0;
                }
                while (iQuitter < 0 || iQuitter > 1);
            }
        }
    }
    return 0;
}
