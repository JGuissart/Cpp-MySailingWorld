#include "FichierCircuits.h"
#include "Circuit.h"
#include <string.h>
#include <iostream>

using namespace std;

FichierCircuits::FichierCircuits(const char* nF)
{
    setNomFichier(nF);
    fstream fCreate(nF, ios::in | ios::out | ios::binary);
    if (!fCreate.is_open())
    {
        setNombrePoints(0);
        fCreate.open(nF, ios::out | ios::app | ios::binary);
        fCreate.write((char*) &iNbrePoint, sizeof(int));
    }
    fCreate.close();
}

FichierCircuits::~FichierCircuits()
{
    
}

/********* Getters *********/

const char* FichierCircuits::getNomFichier() const
{
    return nomFichier;
}

int FichierCircuits::getNombrePoints() const
{
    return iNbrePoint;
}

/********* Setters *********/

void FichierCircuits::setNomFichier(const char* nF)
{
    if (strlen(nF) < 50)
        strcpy(nomFichier, nF);
}

void FichierCircuits::setNombrePoints(int n)
{
    iNbrePoint = n;
}

/*******************************************/

void FichierCircuits::save(Circuit &c)
{
    ofstream fW(getNomFichier(), ios::in | ios::out | ios::binary);

    if (fW.is_open())
    {
        fW.seekp(0, ios::beg);
        c.save(fW);
        fW.close();
    }
    else
        cout << "Le fichier " << getNomFichier() << " n'a pas pu s'ouvrir correctement en ecriture !" << endl;
}

void FichierCircuits::load(Circuit &c)
{
    ifstream fR(getNomFichier(), ios::in | ios::binary);

    c.load(fR);

    fR.close();
}
