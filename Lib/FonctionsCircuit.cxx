#include "FonctionsCircuit.h"
#include "Circuit.h"
#include "FichierCircuits.h"
#include "Pause.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void ajoutCircuit()
{
    Circuit newCir;

    cin >> newCir;

    string nomFichier;

    nomFichier = newCir.getNomCircuit();
    nomFichier += ".cir";

    FichierCircuits fichierCir(nomFichier.c_str());
    fichierCir.save(newCir);
}

void ajoutCircuitAPDFichier()
{
    Circuit recupCir;
    string nomCir;

    cout << "Entrez le nom du fichier contenant les coordonnees du circuit: ";
    cin >> nomCir;

    string nomCirCSV;
    nomCirCSV = nomCir + ".csv";

    ifstream fich(nomCirCSV.c_str());

    if (fich)
    {
        string ligne;

        while(getline(fich, ligne))
        {
            char* pTemp;
            double x, y;
            Point po;
            pTemp = strtok((char*) ligne.c_str(), ";");
            x = atof((char*) pTemp);
            po.setX(x);
            pTemp = strtok(NULL, ";");
            y = atof((char*) pTemp);
            po.setY(y);
            recupCir.setVecteur(po);
        }

        string nomCirBIN;
        nomCirBIN = nomCir + ".cir";
        FichierCircuits fichCir(nomCirBIN.c_str());
        recupCir.setNomCircuit(nomCir);
        fichCir.save(recupCir);

        cout << recupCir;
    }
    fich.close();
}

void afficheDonneesCircuit()
{
    Circuit afficheCir;
    string nomCir;

    cout << "Entrez le nom du circuit que vous voulez afficher: ";
    cin >> nomCir;

    string nomCirBin;
    nomCirBin = nomCir + ".cir";

    ifstream fTest(nomCirBin.c_str(), ios::in | ios::binary);

    if (!fTest.is_open())
        cout << "Il n'existe aucun circuit portant ce nom ..." << endl;
    else
    {
        fTest.close();
        FichierCircuits fichierCir(nomCirBin.c_str());
        fichierCir.load(afficheCir);

        cout << afficheCir;
    }
}
