#include "Activite.h"
#include <string.h>

using namespace std;

Activite::Activite()
{
    setNom("Defaut");
    setLieu("Defaut");
    pObjetFlottant = NULL;
    pObjetFlottant = new ObjetFlottant;
}

Activite::Activite(string nA, string lA, const ObjetFlottant &POF)
{
    setNom(nA);
    setLieu(lA);
    pObjetFlottant = NULL;
    setObjetFlottant(POF);
}

Activite::Activite(const Activite &a)
{
    setNom(a.nomActivite);
    setLieu(a.lieuActivite);
    pObjetFlottant = NULL;
    setObjetFlottant(*(a.pObjetFlottant));
}

Activite::~Activite()
{
    if (pObjetFlottant)
        delete pObjetFlottant;
}

/********* Getters *********/

string Activite::getNom() const
{
    return nomActivite;
}

string Activite::getLieu() const
{
    return lieuActivite;
}

ObjetFlottant Activite::getObjetFlottant() const
{
    return *pObjetFlottant;
}

/********* Setters *********/

void Activite::setNom(string nA)
{
    nomActivite = nA;
}

void Activite::setLieu(string lA)
{
    lieuActivite = lA;
}

void Activite::setObjetFlottant(const ObjetFlottant &OF)
{
    if (pObjetFlottant)
        delete pObjetFlottant;

    pObjetFlottant = new ObjetFlottant(OF);
}

/********* Surcharges d'operateurs *********/

ostream& operator<<(ostream &o, const Activite &a)
{
    o << "Nom de l'activite: " << a.nomActivite << endl;
    o << "Lieu de l'activite: " << a.lieuActivite << endl;
    o << "Objet Flottant: " << *(a.pObjetFlottant) << endl;

    return o;
}

istream& operator>>(istream &i, Activite &a)
{
    char nA[256], lA[256];
    ObjetFlottant *POF = new ObjetFlottant;

    i.ignore();
    cout << "Nom de l'activite: ";
    i.getline(nA, 256); // Si on utilise pas cette méthode, lorsqu'on entre "nom de l'activité", il mettra nom pour le nom de l'activite, de pour le lieu, ... Bref, ça ne fera que de la merde
    cout << "Lieu de l'activite: ";
    i.getline(lA, 256);
    cout << "ObjetFlottant: ";
    cout << endl;
    i >> *POF;

    a.nomActivite = nA;
    a.lieuActivite = lA;
    *(a.pObjetFlottant) = *POF;

    return i;
}

/*******************************************/

void Activite::Affiche()
{
    cout << "Nom de l'activite: " << nomActivite << endl;
    cout << "Lieu de l'activite: " << lieuActivite << endl;
    cout << "Objet Flottant: " << endl;
    cout << *pObjetFlottant;
}

void Activite::save(ofstream &f)
{
    char buf[100];
    strcpy(buf, nomActivite.c_str());
    int n = strlen(buf);
    f.write((char*) &n, sizeof(int));
    f.write(buf, n);

    strcpy(buf, lieuActivite.c_str());
    n = strlen(buf);
    f.write((char*) &n, sizeof(int));
    f.write(buf, n);

    pObjetFlottant->save(f);
}

void Activite::load(ifstream &f)
{
    int n;
    char buf[100];

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;
    setNom(buf);

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;
    setLieu(buf);

    pObjetFlottant->load(f);
}

