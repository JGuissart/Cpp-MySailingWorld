#include "FonctionsRegateChoisie.h"
#include "Concurrent.h"
#include "MaListeTriee.h"
#include "Vecteur.h"
#include "Pause.h"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

/**************************************************************************************************/
/*                                                                                                */
/* INPUT: référence MaListeTriee<Concurrent>                                                      */
/* PROCESS: La fonction va permettre d'encoder manuellement un concurrent dans la liste           */
/* OUTPUT: N/A                                                                                    */
/*                                                                                                */
/**************************************************************************************************/
void ajouterUnConcurrent(MaListeTriee<Concurrent> &lTConcurrent)
{
    Concurrent newConcurrent;

    cin >> newConcurrent;

    while(lTConcurrent.contenir(newConcurrent)) // Permet d'avoir des numéro de matricule unique
    {
        int i = newConcurrent.getNumeroMatricule();
        i++;
        newConcurrent.setNumeroMatricule(i);
    }

    Pause();

    lTConcurrent.inserer(newConcurrent);

    if (lTConcurrent.contenir(newConcurrent))
        cout << "Le concurrent encode a bien ete enregistre !" << endl;
}

/**************************************************************************************************/
/*                                                                                                */
/* INPUT: référence MaListeTriee<Concurrent>                                                      */
/* PROCESS: La fonction va permettre d'ajouter des concurrents à partir d'un fichier txt          */
/*          ou d'un fichier csv                                                                   */
/* OUTPUT: N/A                                                                                    */
/*                                                                                                */
/**************************************************************************************************/
void ajouterUnConcurrentAPDFichier(MaListeTriee<Concurrent> &lTConcurrent)
{
    Concurrent recupCon;
    string nomFichier;

    cout << "Entrez le nom du fichier contenant les informations des concurrents: ";
    cin >> nomFichier;

    string nomFichierCSV;
    nomFichierCSV = nomFichier + ".csv";

    ifstream fich(nomFichierCSV.c_str());

    if (fich)
    {
        string ligne;

        while(getline(fich, ligne))
        {
            char* pTemp;
            int numMat;
            float cap;
            pTemp = strtok((char*) ligne.c_str(), ";");
            numMat = atoi((char*) pTemp);
            recupCon.setNumeroMatricule(numMat);
            pTemp = strtok(NULL, ";");
            recupCon.setNomConcurrent((char*) pTemp);
            pTemp = strtok(NULL, ";");
            cap = atof((char*) pTemp);
            recupCon.setNiveauCapacite(cap);
            recupCon.setPlace(0);

            while(lTConcurrent.contenir(recupCon)) // Permet d'avoir des numéro de matricule unique
            {
                int i = recupCon.getNumeroMatricule();
                i++;
                recupCon.setNumeroMatricule(i);
            }

            lTConcurrent.inserer(recupCon);

            if (lTConcurrent.contenir(recupCon))
                cout << "Le concurrent " << recupCon.getNomConcurrent() << " a bien ete stocke dans la liste !" << endl;
            else
                cout << "Erreur lors de l'enregistrement du concurrent dans la liste ..." << endl;
        }
    }
    fich.close();
}

/**************************************************************************************************/
/*                                                                                                */
/* INPUT: - référence MaListeTriee<Regate>                                                        */
/*        - référence MaListeTriee<Concurrent>                                                    */
/* PROCESS: La fonction va permettre de lancer une régate choisie dans la liste. Les concurrents  */
/*          se trouvant dans la liste disputeront la course entre eux.                            */
/*          Si la liste est vide, la fonction permettra d'encoder manuellement ou à partir d'un   */
/*          fichier txt/csv des concurrents.                                                      */
/* OUTPUT: N/A                                                                                    */
/*                                                                                                */
/**************************************************************************************************/
void lancerUneRegate(MaListeTriee<Regate> &lTRegate, MaListeTriee<Concurrent> &lTConcurrent)
{
    const double pi = 3.1416;
    char c = '\0', c2 = 'o';
    while (lTConcurrent.getTaille() < 2 || c2 == 'o' || c2 == 'O')
    {
        while (c != 'o' && c != 'O' && c != 'n' && c != 'N')
        {
            if (lTConcurrent.isEmpty())
                cout << "La liste des concurrents est vide." << endl;
            if (lTConcurrent.getTaille() == 1)
                cout << "Il manque au moins un concurrent pour lancer la regate." << endl;
            cout << "Voulez-vous ajouter des concurrents a la liste ?" << endl;
            cout << "Votre choix (O/N): ";
            cin >> c;
        }

        if (c == 'o' || c == 'O')
        {
            int iChoix;
            do
            {
                cout << "De quelle manière ?" << endl;
                cout << "1. Encodage manuel" << endl;
                cout << "2. Generation a partir d'un fichier" << endl;
                cout << endl << "Votre choix (1/2): ";
                cin >> iChoix;
                cout << endl;
            }
            while (iChoix < 1 || iChoix > 2);

            if (iChoix == 1)
                ajouterUnConcurrent(lTConcurrent);
            if (iChoix == 2)
                ajouterUnConcurrentAPDFichier(lTConcurrent);
            do
            {
                cout << endl << endl << "Voulez-vous ajouter d'autre concurrents a la liste ?" << endl;
                cout << "Votre choix (O/N): ";
                cin >> c2;
            }
            while (c2 != 'o' && c2 != 'O' && c2 != 'n' && c2 != 'N');

            if (c2 == 'o' || c == 'O')
                c = 'o';
        }
        if (c == 'n' || c == 'N')
        {
            if (lTConcurrent.getTaille() < 2)
                return;
            else
                c2 = 'n';
        }
    }

    Regate r;
    do
    {
        string nomReg;
        cout << "Entrez le nom de la regate que vous voulez simuler: ";
        cin >> nomReg;
        r.setNomCourse(nomReg);
    }
    while (!lTRegate.contenir(r));

    r = lTRegate.recupererObjet(r);

    cout << r << endl;

    Pause();

    Concurrent affichCon;
    int iNbreIteration = 0;
    double angleVent = 0;
    int pasRef, tailleVec = lTConcurrent.getTaille();
    Vecteur<Concurrent> vecConcurrent(tailleVec);
    int place = 0;
    Moment tempsCourant(r.getDepart());
    Moment dureeRegate;

    cout << "Entrez un pas de reference: ";
    cin >> pasRef;

    system("clear");

    while (lTConcurrent.getTaille()) // Tant qu'il reste des concurrents en course
    {
        if (!iNbreIteration) // Début de la régate, initialisation d'un angleVent de départ
        {
            angleVent = rand() % (360 - 0);
            angleVent = (pi * angleVent) / 180;
        }
        else
        {
            if(iNbreIteration % 5 == 0) // Additionner/soustraire un certain nombre de degré du vent toutes les 5 itérations
            {
                double addAngleVent = rand() % (20 - 0) - 10;
                addAngleVent = (pi * addAngleVent) / 180;
                angleVent += addAngleVent;
            }
        }

        cout << tempsCourant << endl;
        tempsCourant = tempsCourant + 3; // +3 => Choix arbitraire
        dureeRegate = dureeRegate + 3;
        Iterateur<Concurrent> it = lTConcurrent.getIterateur();

        cout << "Matricule\t\tNom\t\tNiveau\t\tPlace\t\tPosition" << endl;
        while (it.hasNext()) // Iterateur permettant l'affichage + MAJ des données
        {
            Point bouee1, bouee2, posCon;
            double x1, x2, xpt, y1, y2, ypt;
            affichCon = it.next();
            if (!iNbreIteration) // Si la régate n'a pas encore démarrée ...
                affichCon.setPosition(r.getPoint(0)); // ... on positionne tous les concurrents à la bouée de départ
            cout << affichCon;

            if (affichCon.getNumeroBouee() < r.getNombreElementVecteur() - 1)
            {
                bouee1 = r.getPoint(affichCon.getNumeroBouee());
                bouee2 = r.getPoint(affichCon.getNumeroBouee() + 1);

                posCon = affichCon.getPosition();

                x1 = bouee1.getX();
                y1 = bouee1.getY();
                x2 = bouee2.getX();
                y2 = bouee2.getY();
                xpt = posCon.getX();
                ypt = posCon.getY();
                double dTotalEntreBouees = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
                double dParcourueEntreBouees = sqrt(pow((xpt - x1), 2) + pow((ypt - y1), 2)); // dParcoursEntreBouees += pasRef ne marche pas
                double vdx = (x2 - x1) / dTotalEntreBouees;
                double vdy = (y2 - y1) / dTotalEntreBouees;

                lTConcurrent.supprimer(affichCon);
                if (dParcourueEntreBouees >= dTotalEntreBouees)
                    affichCon.setNumeroBouee(affichCon.getNumeroBouee() + 1);
                else
                {
                    double xtd, ytd, factAleatoire, alpha;
                    alpha = acos(vdx * cos(angleVent) + vdy * sin(angleVent));
                    factAleatoire = (rand() % (110 - 90 + 1)) + 90;
                    factAleatoire = factAleatoire / 100;
                    xtd = xpt + (pasRef * (cos(alpha) + sin(alpha) + 1) * affichCon.getNiveauCapacite() * factAleatoire) * vdx;
                    ytd = ypt + (pasRef * (cos(alpha) + sin(alpha) + 1) * affichCon.getNiveauCapacite() * factAleatoire) * vdy;
                    Point p(xtd, ytd);
                    affichCon.setPosition(p);
                    //cout << affichCon.getNomConcurrent() << " a parcouru " << dParcourueEntreBouees << " sur la distance totale de " << dTotalEntreBouees << endl;
                }
                lTConcurrent.inserer(affichCon);
            }
            else
            {
                place++;
                affichCon.setPlace(place);
                vecConcurrent + affichCon;
                lTConcurrent.supprimer(affichCon);
            }
        }
        iNbreIteration++;
        Pause();
    }

    system("clear");

    cout << "Duree totale de la regate: " << dureeRegate.ToString() << endl;

    cout << "Matricule\t\tNom\t\tNiveau\t\tPlace\t\tPosition" << endl;

    vecConcurrent.affiche(tailleVec);
}
