#include <stdlib.h>
#include "ModeleObjetFlottant.h"
#include <string.h>
#include <fstream>

using namespace std;

ModeleObjetFlottant::ModeleObjetFlottant()
{
    setConstructeur("defaut");
    setModele("defaut");
    setTaille(0.0);
}

ModeleObjetFlottant::ModeleObjetFlottant(string c, string m, float t)
{
    setConstructeur(c);
    setModele(m);
    setTaille(t);
}

ModeleObjetFlottant::ModeleObjetFlottant(const ModeleObjetFlottant& MOF)
{
    setConstructeur(MOF.constructeur);
    setModele(MOF.modele);
    setTaille(MOF.taille);
}

ModeleObjetFlottant::~ModeleObjetFlottant()
{

}

/********* Getters *********/

string ModeleObjetFlottant::getConstructeur() const
{
    return constructeur;
}

string ModeleObjetFlottant::getModele() const
{
    return modele;
}

float ModeleObjetFlottant::getTaille() const
{
    return taille;
}

/********* Setters *********/

void ModeleObjetFlottant::setConstructeur(string c)
{
    constructeur = c;
}

void ModeleObjetFlottant::setModele(string m)
{
    modele = m;
}

void ModeleObjetFlottant::setTaille(float t)
{
    taille = t;
}

/********* Surcharges d'operateurs *********/

std::ostream& operator<<(std::ostream &o, const ModeleObjetFlottant &MOF)
{
    o << "\tConstructeur de l'objet flottant: " << MOF.constructeur << endl;
    o << "\tModele de l'objet flottant: " << MOF.modele << endl;
    o << "\tTaille de l'objet flottant: " << MOF.taille << endl;

    return o;
}

std::istream& operator>>(istream &i, ModeleObjetFlottant &MOF)
{
    cout << "\tConstructeur de l'objet flottant: ";
    i >> MOF.constructeur;
    cout << "\tModele de l'objet flottant: ";
    i >> MOF.modele;
    cout << "\tTaille de l'objet flottant: ";
    i >> MOF.taille;
    cout << endl;

    return i;
}

/*******************************************/

void ModeleObjetFlottant::Affiche()
{
    cout << "Constructeur = " << getConstructeur() << endl;
    cout << "Modele = " << getModele() << endl;
    cout << "Taille = " << getTaille() << endl;
}

string ModeleObjetFlottant::HOBIE = "Hobie";
string ModeleObjetFlottant::BICSPORT = "Bic Sport";
ModeleObjetFlottant ModeleObjetFlottant::HOBIE_14(HOBIE, "14", 10.46);
ModeleObjetFlottant ModeleObjetFlottant::HOBIE_16(HOBIE, "16", 15.56);

void ModeleObjetFlottant::save(ofstream &f)
{
    char buf[100];
    strcpy(buf, constructeur.c_str());
    int n = strlen(buf);

    f.write((char*) &n, sizeof(int));
    f.write(buf, n);

    strcpy(buf, modele.c_str());
    n = strlen(buf);

    f.write((char*) &n, sizeof(int));
    f.write(buf, n);

    f.write((char*) &taille, sizeof(float));
}

void ModeleObjetFlottant::load(ifstream &f)
{
    char buf[100];
    int n;

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;
    setConstructeur(buf);

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;
    setModele(buf);

    f.read((char*) &taille, sizeof(float));
    setTaille(taille);
}
