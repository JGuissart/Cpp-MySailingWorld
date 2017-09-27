#include "Circuit.h"
#include "FichierCircuits.h"
#include "InvalidContainersException.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

Circuit::Circuit()
{
    setNomCircuit("Defaut");
}

Circuit::Circuit(string nC)
{
    setNomCircuit(nC);
}

Circuit::Circuit(const Circuit &c)
{
    nomCircuit = c.nomCircuit;
    vec = c.vec;
}

Circuit::~Circuit()
{

}

/********* Getters *********/

string Circuit::getNomCircuit() const
{
    return nomCircuit;
}

Point Circuit::getBouee(int i)
{
    return vec.getElement(i);
}

int Circuit::getNombreElementVecteur() const
{
    return vec.getNombreElement();
}

/********* Setters *********/

void Circuit::setNomCircuit(const string& nC)
{
    nomCircuit = nC;
}

void Circuit::setVecteur(const Point& po)
{
    vec + po;
}

/********* Surcharges d'operateurs *********/

ostream& operator<<(ostream& o, Circuit &cir)
{
    o << "\tNom du circuit: " << cir.getNomCircuit() << endl;
    o << "\tCoordonnees des bouees: " << endl;
    cir.afficheBouees();

    return o;
}

istream& operator>>(istream& i, Circuit &cir)
{
    char buf[256];
    i.ignore();
    cout << "Entrez le nom du circuit: ";
    i.getline(buf, 256);
    cir.setNomCircuit(buf);

    string nomCirBIN;
    nomCirBIN = cir.nomCircuit + ".cir";

    ifstream fichLoad(nomCirBIN.c_str(), ios::in | ios::binary);

    if (fichLoad.is_open())
    {
        cout << "Un fichier circuit porte le nom que vous avez entrez." << endl;
        FichierCircuits fichCir(nomCirBIN.c_str());
        fichCir.load(cir);
        cout << "Les coordonnees de ce circuit ont ete affectees a cet enregistrement !" << endl;
        fichLoad.close();
    }
    else
    {
        int n = 0;
        do
        {
            cout << "Entrez le nombre de points que vous voulez encoder (min: 2 | max: 20): ";
            cin >> n;
        }
        while (n < 2 || n > 20);

        if (n >= 2)
        {
            for (int i = 0; i < n; i++)
            {
                Point po;

                cout << "**** Bouee " << i + 1 << " ****" << endl << endl;
                cin >> po;
                cir.vec + po;
            }
        }

        string nomFichierCir;
        nomFichierCir = cir.getNomCircuit() + ".cir";
        FichierCircuits fichierCir(nomFichierCir.c_str());
        fichierCir.save(cir);
    }

    return i;
}

Circuit& Circuit::operator=(const Circuit& c)
{
    //cout << "TEST NOMCIRCUIT" << endl;
    nomCircuit = c.nomCircuit;
    //cout << "TEST AVANT VEC" << endl;
    vec = c.vec;
    //cout << "TEST APRES VEC" << endl;

    return *this;
}

/*******************************************/

void Circuit::afficheBouees()
{
    vec.affiche();
}

void Circuit::save(ofstream &f)
{
    int i = 0, n = 0;

    while (vec.estOccupe(i))
    {
        n++;
        i++;
    }

    //cout << "NOMBRE ENREG SAVE: " << n << endl << endl;

    f.write((char*) &n, sizeof(int));

    i = 0;
	while (vec.estOccupe(i) && i < n)
	{
		try
		{
			Point p;
			p = vec.getElement(i);
			p.save(f);
			i++;
		}
		catch (InvalidContainersException e)
		{
			cerr << e.getMessage() << endl;
		}
	}

    char buf[100];
    strcpy(buf, nomCircuit.c_str());
    n = strlen(buf);

    f.write((char*) &n, sizeof(int));
    f.write(buf, n);
}

void Circuit::load(ifstream &f)
{
    char buf[100];
    int n, i = 0;

    f.read((char*) &n, sizeof(int));

    //cout << "NOMBRE POINTS: " << n << endl << endl;

    //system("PAUSE");

    while (i < n)
    {
		try
		{
			Point p;
			p.load(f);
			vec.setElement(i, p);
			i++;
		}
		catch (InvalidContainersException e)
		{
			cerr << e.getMessage() << endl;
		}
    }
    vec.setNombreElement(n);

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;

    setNomCircuit(buf);
}

void Circuit::load(string nC)
{
    char buf[100];
    int n, i = 0;
    string nomCirBIN;

    nomCirBIN = nC + ".cir";

    //cout << "Nom circuit: " << nomCirBIN << endl;

    ifstream fR(nomCirBIN.c_str(), ios::in | ios::binary);

    fR.read((char*) &n, sizeof(int));

    //cout << "NOMBRE POINTS: " << n << endl << endl;

    while (i < n)
    {
		try
		{
			Point p;
			p.load(fR);
			vec.setElement(i, p);
			i++;
		}
		catch (InvalidContainersException e)
		{
			cerr << e.getMessage() << endl;
		}
    }
    vec.setNombreElement(n);

    fR.read((char*) &n, sizeof(int));
    fR.read(buf, n);
    fR.close();

    buf[n] = 0;

    //cout << "BUF: " << buf << endl;

    setNomCircuit(buf);
}
