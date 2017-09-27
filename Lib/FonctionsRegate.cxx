#include "FonctionsRegate.h"
#include "MaListeTriee.h"
#include "Iterateur.h"
#include "Pause.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

void ajouterUneRegate(MaListeTriee<Regate> &lRegate, FichierRegates &fichierReg)
{
    Regate newReg;

    cin  >> newReg;

    if (lRegate.contenir(newReg))
        cout << "La regate que vous avez encode existe deja ..." << endl;
    else
    {
        lRegate.inserer(newReg);
        fichierReg.save(newReg);

        if (lRegate.contenir(newReg))
            cout << "La regate a bien ete enregistre !" << endl;
        else
            cout << "Erreur lors de la creation d'une nouvelle regate" << endl;
    }
}

void afficherRegates(MaListeTriee<Regate> &lRegate)
{
    Iterateur<Regate> it = lRegate.getIterateur();

    Regate r;
    int i = 1;

    while (it.hasNext())
    {
        r = it.next();

        cout << endl << "============ REGATE N " << i << " ============" << endl << endl;

        cout << "Nom de la regate: " << r.getNomCourse() << endl;
        cout << "Date de depart de la regate: " << r.getDepart() << endl << endl;
        i++;
        Pause();
    }
}

void afficherUneRegate(MaListeTriee<Regate> &lRegate)
{
    string nomReg;

    cout << "Entrez le nom de la regate dont vous voulez afficher les informations: " << endl;
    cin >> nomReg;

    Regate r;

    r.setNomCourse(nomReg);

    if (lRegate.contenir(r))
    {
        r = lRegate.recupererObjet(r);
        cout << endl << r << endl << endl;
    }
    else
        cout << endl << "Cette regate n'existe pas !" << endl << endl;
}

void suppressionRegate(MaListeTriee<Regate> &lRegate, FichierRegates &fichierReg)
{
    string nomReg;

    cout << "Entrez le nom de la regate que vous voulez supprimer: " << endl;
    cin >> nomReg;

    Regate r;

    r.setNomCourse(nomReg);

    if (lRegate.contenir(r))
    {
        r = lRegate.recupererObjet(r);
        cout << endl << r << endl << endl << endl;

        char c = '\0';
        while (c != 'o' && c != 'O' && c != 'n' && c != 'N')
        {
            cout << "Etes-vous sur de vouloir supprimer cette regate ?" << endl;
            cout << "Oui (O) ou non (N)." << endl;
            cout << "Votre choix: ";
            cin >> c;
        }
        if (c == 'o' || c == 'O')
        {
            lRegate.supprimer(r);

            ofstream f(fichierReg.getNomFichier(), ios::out | ios::trunc | ios::binary);

            if (f.is_open())
            {
                int iNbreEnreg = 0;
                f.write((char*) &iNbreEnreg, sizeof(int));
                f.close();
            }

            Iterateur<Regate> it = lRegate.getIterateur();
            Regate rAjout;

            while(it.hasNext())
            {
                rAjout = it.next();
                fichierReg.save(rAjout);
            }
            cout << "La regate a bien ete supprimee !" << endl;
        }
        else
            cout << "Vous avez choisi de ne pas supprimer la regate selectionnee !" << endl;
    }
    else
        cout << endl << "Cette regate n'existe pas !" << endl << endl;
}
