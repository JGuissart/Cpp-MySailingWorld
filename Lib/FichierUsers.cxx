#include "FichierUsers.h"
#include "MaListeTriee.h"
#include "User.h"
#include <string.h>
#include <iostream>

using namespace std;

FichierUsers::FichierUsers()
{
    setNomFichier("User.dat");
    fstream fCreate(getNomFichier(), ios::in | ios::out | ios::binary);
    if (!fCreate.is_open())
    {
        setNombreEnregistrement(0);
        fCreate.open(getNomFichier(), ios::out | ios::app | ios::binary);
        fCreate.write((char*) &iNbreEnreg, sizeof(int));
    }

    fCreate.close();
}

FichierUsers::FichierUsers(const char* nF)
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

FichierUsers::~FichierUsers()
{

}

/********* Getters *********/

const char* FichierUsers::getNomFichier() const
{
    return nomFichier;
}

int FichierUsers::getNombreEnregistrement() const
{
    return iNbreEnreg;
}

/********* Setters *********/

void FichierUsers::setNomFichier(const char* nF)
{
    if (strlen(nF) < 50)
        strcpy(nomFichier, nF);
}

void FichierUsers::setNombreEnregistrement(int nE)
{
    iNbreEnreg = nE;
}

/*******************************************/

void FichierUsers::load(MaListeTriee<User> &lUser)
{
    ifstream fListe(getNomFichier(), ios::in | ios::binary);

    if (fListe.is_open())
    {
        User u;
        int i = 0;

        fListe.read((char*) &iNbreEnreg, sizeof(int));

        while (i < getNombreEnregistrement())
        {
            u.load(fListe);
            lUser.inserer(u);
            i++;
        }
    }
    fListe.close();
}

void FichierUsers::save(User &u)
{
    ofstream fW(getNomFichier(), ios::in | ios::out | ios::binary);

    if (fW.is_open())
    {
        iNbreEnreg = recupNombreEnregistrement(getNomFichier());
        fW.seekp(0, ios::beg);
        fW.write((char*) &iNbreEnreg, sizeof(int));
        fW.seekp(0, ios::end);
        u.save(fW);
        fW.close();
    }
    else
        cout << "Le fichier " << getNomFichier() << " n'a pas pu s'ouvrir correctement en ecriture !" << endl;
}

void FichierUsers::list()
{
    ifstream fR(getNomFichier(), ios::in | ios::binary);

    fR.read((char*) &iNbreEnreg, sizeof(int));

    int i = 0;
    User u;

    while (i < getNombreEnregistrement())
    {
        u.load(fR);
        u.Affiche();
        i++;
    }

    fR.close();
}

int FichierUsers::recupNombreEnregistrement(const char* nF)
{
    ifstream fichierR(nF, ios::binary);

    fichierR.seekg(0, ios::beg);
    fichierR.read((char*) &iNbreEnreg, sizeof(int));
    iNbreEnreg++;
    fichierR.close();

    return iNbreEnreg;
}
