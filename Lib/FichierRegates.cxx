#include "FichierRegates.h"
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

FichierRegates::FichierRegates()
{
    setNomFichier("DefautRegate.dat");
    fstream fCreate(getNomFichier(), ios::in | ios::out | ios::binary);
    if (!fCreate.is_open())
    {
        setNombreEnregistrement(0);
        fCreate.open(getNomFichier(), ios::out | ios::app | ios::binary);
        fCreate.write((char*) &iNbreEnreg, sizeof(int));
    }

    fCreate.close();
}

FichierRegates::FichierRegates(const char* nF)
{
    setNomFichier(nF);
    fstream fCreate(nF, ios::in | ios::out | ios::binary);
    if (!fCreate.is_open())
    {
        setNombreEnregistrement(0);
        fCreate.open(nF, ios::out | ios::app | ios::binary);
        fCreate.write((char*) &iNbreEnreg, sizeof(int));
    }

    fCreate.close();
}

FichierRegates::~FichierRegates()
{
    
}

/********* Getters *********/

const char* FichierRegates::getNomFichier() const
{
    return nomFichier;
}

int FichierRegates::getNombreEnregistrement() const
{
    return iNbreEnreg;
}

/********* Setters *********/

void FichierRegates::setNomFichier(const char* nF)
{
    if (strlen(nF) < 50)
        strcpy(nomFichier, nF);
}

void FichierRegates::setNombreEnregistrement(int nE)
{
    iNbreEnreg = nE;
}

/*******************************************/

void FichierRegates::load(MaListeTriee<Regate> &lRegate)
{
    ifstream fListe(getNomFichier(), ios::in | ios::binary);

    if (fListe.is_open())
    {
        Regate r;
        int i = 0;

        fListe.read((char*) &iNbreEnreg, sizeof(int));

        while (i < getNombreEnregistrement())
        {
            r.load(fListe);
            lRegate.inserer(r);
            i++;
        }
    }
    fListe.close();
}

void FichierRegates::save(Regate &r)
{
    ofstream fW(getNomFichier(), ios::in | ios::out | ios::binary);

    if (fW.is_open())
    {
        iNbreEnreg = recupNombreEnregistrement(getNomFichier());
        fW.seekp(0, ios::beg);
        fW.write((char*) &iNbreEnreg, sizeof(int));
        fW.seekp(0, ios::end);
        r.save(fW);
        fW.close();
    }
    else
        cout << "Le fichier " << getNomFichier() << " n'a pas pu s'ouvrir correctement en ecriture !" << endl;
}

void FichierRegates::list()
{
    ifstream fR(getNomFichier(), ios::in | ios::binary);

    fR.read((char*) &iNbreEnreg, sizeof(int));

    int i = 0;
    Regate r;

    while (i < getNombreEnregistrement())
    {
        r.load(fR);
        r.Affiche();
        i++;
    }

    fR.close();
}

int FichierRegates::recupNombreEnregistrement(const char* nF)
{
    ifstream fichierR(nF, ios::binary);

    fichierR.seekg(0, ios::beg);
    fichierR.read((char*) &iNbreEnreg, sizeof(int));
    iNbreEnreg++;
    fichierR.close();

    return iNbreEnreg;
}

int FichierRegates::load(Regate& R, const char* nR)
{
    ifstream fR(getNomFichier(), ios::in | ios::binary);

    fR.seekg(0, ios::beg);
    fR.read((char*) &iNbreEnreg, sizeof(int));

    int i = 0;
    while (i < getNombreEnregistrement())
    {
        R.load(fR);
        if (!strcmp(R.getNom().c_str(), nR))
            return 0;

        i++;
    }
    return 1;
}

