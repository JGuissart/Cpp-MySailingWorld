#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "ObjetFlottant.h"
#include "ModeleObjetFlottant.h"

using namespace std;

ObjetFlottant::ObjetFlottant()
{
    setIdentifiant("Defaut");
}

ObjetFlottant::ObjetFlottant(const char* id, const ModeleObjetFlottant& m)
{
    setModele(m);
    setIdentifiant(id);
}

ObjetFlottant::ObjetFlottant(const ObjetFlottant& OF)
{
    setModele(OF.getModele());
    setIdentifiant(OF.getIdentifiant());
}

ObjetFlottant::~ObjetFlottant()
{

}

/********* Getters *********/

const char* ObjetFlottant::getIdentifiant() const
{
    return identifiant;
}

ModeleObjetFlottant ObjetFlottant::getModele() const
{
    return modele;
}

/********* Setters *********/

void ObjetFlottant::setModele(const ModeleObjetFlottant& m)
{
    modele.setConstructeur(m.getConstructeur());
    modele.setTaille(m.getTaille());
    modele.setModele(m.getModele());
}

void ObjetFlottant::setIdentifiant(const char* id)
{
    if (strlen(id) < 20)
        strcpy(identifiant, id);
}

/********* Surcharges d'operateurs *********/

std::ostream &operator<<(std::ostream &o, const ObjetFlottant &OF)
{
    cout << endl;
    o << "\tIdentifiant de l'objet flottant: " << OF.identifiant << endl;
    o << OF.modele << endl;

    return o;
}

std::istream& operator>>(istream &i, ObjetFlottant &OF)
{
    cout << "\tIdentifiant de l'objet flottant: ";
    i >> OF.identifiant;
    i >> OF.modele;

    return i;
}

/*******************************************/

void ObjetFlottant::Affiche()
{
    cout << "Modele = " << getModele() << endl;
    cout << "Identifiant = " << getIdentifiant() << endl;
}

void ObjetFlottant::save(ofstream &f)
{
    int n = strlen(identifiant);

    f.write((char*) &n, sizeof(int));
    f.write(identifiant, n);

    modele.save(f); // Passage à la méthode save de ModeleObjetFlottant
}

void ObjetFlottant::load(ifstream &f)
{
    int n;

    f.read((char*) &n, sizeof(int));
    f.read(identifiant, n);

    modele.load(f); // Passage à la méthode load de ModeleObjetFlottant
}

