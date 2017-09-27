#include "FonctionsClub.h"
#include "FonctionsCircuit.h"
#include "FonctionsRegate.h"
#include "FonctionsRegateChoisie.h"
#include "Pause.h"

#include <iostream>
#include <cstdlib>

using namespace std;

char menuClub()
{
    char ch;
    do
    {
        cout << endl;
        cout << "***************************************************" << endl;
        cout << "***                                             ***" << endl;
        cout << "***   MySailingWorld                            ***" << endl;
        cout << "***   Seraing by Meuse - Club de voile          ***" << endl;
        cout << "***                                             ***" << endl;
        cout << "***************************************************" << endl << endl;
        cout << " 1. Gerer les circuits" << endl;
        cout << " \t1.1 Ajouter un circuit" << endl;
        cout << " \t1.2 Ajouter un circuit a partir d'un fichier texte" << endl;
        cout << " \t1.3 Afficher les donnees d'un circuit" << endl;
        cout << " 2. Gerer les regates" << endl;
        cout << " \t2.1 Ajouter une regate" << endl;
        cout << " \t2.2 Afficher la liste des regates" << endl;
        cout << " \t2.3 Afficher une regate" << endl;
        cout << " \t2.4 Supprimer une regate" << endl;
        cout << " 3. Gerer une regate choisie" << endl;
        cout << " \t3.1 Ajouter un concurrent" << endl;
        cout << " \t3.2 Ajouter une liste de concurrent a partir d'un fichier texte" << endl;
        cout << " \t3.3 Lancer une regate" << endl;
        cout << " N. Nouvelle Session" << endl;
        cout << " Q. Quitter l'application" << endl << endl;

        cout << "  Choix (1, 2, 3, N ou Q): ";
        cin >> ch;
    }
    while ((ch < '1' || ch > '4') && ch != 'N' && ch != 'Q');

    return ch;
}

void choixMenuClub(char c, MaListeTriee<Regate> &lRegate, FichierRegates &fichierReg, MaListeTriee<Concurrent> &lTConcurrent)
{
    char c1 = '\0';

    switch(c)
    {
        case '1':
            system("clear");
            c1 = sousMenuCircuit();
            choixMenuCircuit(c1);
        break;

        case '2':
            system("clear");
            c1 = sousMenuRegate();
            choixMenuRegate(c1, lRegate, fichierReg);
        break;

        case '3':
            system("clear");
            c1 = sousMenuRegateChoisie();
            choixMenuRegateChoisie(c1, lTConcurrent, lRegate);
        break;

        default: cout << "Vous n'avez pas entre un(e) numero/lettre du menu ..." << endl;
        break;
    }
}

char sousMenuCircuit()
{
    char ch;
    do
    {
        cout << endl;
        cout << "***************************************************" << endl;
        cout << "***                                             ***" << endl;
        cout << "***   MySailingWorld                            ***" << endl;
        cout << "***   Seraing by Meuse - Club de voile          ***" << endl;
        cout << "***                                             ***" << endl;
        cout << "***              Menu des circuits              ***" << endl;
        cout << "***************************************************" << endl << endl;
        cout << " 1. Ajouter un circuit" << endl;
        cout << " 2. Ajouter un circuit a partir d'un fichier texte" << endl;
        cout << " 3. Afficher les donnees d'un circuit" << endl;
        cout << " R. Retour au menu principal" << endl << endl;

        cout << "  Choix : ";
        cin >> ch;
    }
    while ((ch < '1' || ch > '3') && ch != 'R');

    return ch;
}

void choixMenuCircuit(char c)
{
    switch(c)
    {
        case '1':
            system("clear");
            cout << "******** Ajouter un circuit ********" << endl << endl;
            ajoutCircuit();
        break;

        case '2':
            system("clear");
            cout << "******** Ajouter un circuit a partir d'une fichier ********" << endl << endl;
            ajoutCircuitAPDFichier();
        break;

        case '3':
            system("clear");
            cout << "******** Affichage d'un circuit ********" << endl << endl;
            afficheDonneesCircuit();
        break;

        case 'R':
            system("clear");
        break;

        default: cout << "Vous n'avez pas entre un bon numero du menu ..." << endl;
        break;
    }
    Pause();
}

char sousMenuRegate()
{
    char ch;
    do
    {
        cout << endl;
        cout << "***************************************************" << endl;
        cout << "***                                             ***" << endl;
        cout << "***   MySailingWorld                            ***" << endl;
        cout << "***   Seraing by Meuse - Club de voile          ***" << endl;
        cout << "***                                             ***" << endl;
        cout << "***               Menu des regates              ***" << endl;
        cout << "***************************************************" << endl << endl;
        cout << " 1. Ajouter une regate" << endl;
        cout << " 2. Afficher la liste des regates" << endl;
        cout << " 3. Afficher une regate" << endl;
        cout << " 4. Supprimer une regate" << endl;
        cout << " R. Retour au menu principal" << endl << endl;

        cout << "  Choix : ";
        cin >> ch;
    }
    while ((ch < '1' || ch > '4') && ch != 'R');

    return ch;
}

void choixMenuRegate(char c, MaListeTriee<Regate> &lRegate, FichierRegates &fichierReg)
{
    switch(c)
    {
        case '1':
            system("clear");
            cout << "******** Encoder une nouvelle regate ********" << endl << endl;
            ajouterUneRegate(lRegate, fichierReg);
        break;

        case '2':
            system("clear");
            if (lRegate.isEmpty())
                cout << "La liste ne contient aucune regate ..." << endl << endl;
            else
            {
                cout << "******** Affichage de la liste des regates ********" << endl << endl;
                afficherRegates(lRegate);
            }
        break;

        case '3':
            system("clear");
            if (lRegate.isEmpty())
                cout << "La liste ne contient aucune regate ..." << endl << endl;
            else
            {
                cout << "******** Affichage d'une regate ********" << endl << endl;
                afficherUneRegate(lRegate);
            }
        break;

        case '4':
            system("clear");
            if (lRegate.isEmpty())
                cout << "La liste ne contient aucune regate ..." << endl << endl;
            else
            {
                cout << "******** Suppression d'une regate ********" << endl << endl;
                suppressionRegate(lRegate, fichierReg);
            }
        break;

        case 'R':
            system("clear");
        break;

        default: cout << "Vous n'avez pas entre un bon numero du menu ..." << endl;
        break;
    }
    Pause();
}

char sousMenuRegateChoisie()
{
    char ch;
    do
    {
        cout << endl;
        cout << "***************************************************" << endl;
        cout << "***                                             ***" << endl;
        cout << "***   MySailingWorld                            ***" << endl;
        cout << "***   Seraing by Meuse - Club de voile          ***" << endl;
        cout << "***                                             ***" << endl;
        cout << "***        Menu pour une regate choisie         ***" << endl;
        cout << "***************************************************" << endl << endl;
        cout << " 1. Ajouter un concurrent" << endl;
        cout << " 2. Ajouter une liste de concurrent a partir d'un fichier texte" << endl;
        cout << " 3. Lancer une regate" << endl;
        cout << " R. Retour au menu principal" << endl << endl;

        cout << "  Choix : ";
        cin >> ch;
    }
    while ((ch < '1' || ch > '3') && ch != 'R');

    return ch;
}

void choixMenuRegateChoisie(char c, MaListeTriee<Concurrent> &lTConcurrent, MaListeTriee<Regate> &lRegate)
{
    switch(c)
    {
        case '1':
            system("clear");
            cout << "******** Ajouter un concurrent ********" << endl << endl;
            ajouterUnConcurrent(lTConcurrent);
        break;

        case '2':
            system("clear");
            cout << "******** Ajouter un concurrent a partir d'un fichier ********" << endl << endl;
            ajouterUnConcurrentAPDFichier(lTConcurrent);
        break;

        case '3':
            system("clear");
            cout << "******** Lancer une regate ********" << endl << endl;
            lancerUneRegate(lRegate, lTConcurrent);
        break;

        case 'R':
            system("clear");
        break;

        default: cout << "Vous n'avez pas entre un bon numero du menu ..." << endl;
        break;
    }
    Pause();
}
