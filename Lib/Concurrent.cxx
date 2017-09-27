#include "Concurrent.h"

#include <iostream>

using namespace std;

Concurrent::Concurrent()
{
	setNumeroMatricule(0);
	setNomConcurrent("defaut");
	setNiveauCapacite(0);
	setPlace(0);
	pos.setX(0);
	pos.setY(0);
	setNumeroBouee(0);
}

Concurrent::Concurrent(int nM, std::string nC, float lvlC)
{
	setNumeroMatricule(nM);
	setNomConcurrent(nC);
	setNiveauCapacite(lvlC);
	setPlace(0);
	pos.setX(0);
	pos.setY(0);
	setNumeroBouee(0);
}

Concurrent::Concurrent(const Concurrent &c)
{
	setNumeroMatricule(c.getNumeroMatricule());
	setNomConcurrent(c.getNomConcurrent());
	setNiveauCapacite(c.getNiveauCapacite());
	setPlace(c.getPlace());
	setPosition(c.getPosition());
	setNumeroBouee(c.getNumeroBouee());
}

Concurrent::~Concurrent()
{

}

/********* Getters *********/

int Concurrent::getNumeroMatricule() const
{
	return numMatricule;
}

string Concurrent::getNomConcurrent() const
{
	return nomConcurrent;
}

float Concurrent::getNiveauCapacite() const
{
	return niveauCapacite;
}

int Concurrent::getPlace() const
{
	return place;
}

int Concurrent::getNumeroBouee() const
{
	return numBouee;
}

double Concurrent::getPositionX()
{
    return pos.getX();
}

double Concurrent::getPositionY()
{
    return pos.getY();
}

Point Concurrent::getPosition() const
{
    return pos;
}

/********* Setters *********/

void Concurrent::setNumeroMatricule(const int nM)
{
	numMatricule = nM;
}

void Concurrent::setNomConcurrent(const string nC)
{
	nomConcurrent = nC;
}

void Concurrent::setNiveauCapacite(const float nC)
{
	niveauCapacite = nC;
}

void Concurrent::setPlace(const int pl)
{
	place = pl;
}

void Concurrent::setNumeroBouee(const int bouee)
{
    numBouee = bouee;
}

void Concurrent::setPositionX(const double x)
{
    pos.setX(x);
}

void Concurrent::setPositionY(const double y)
{
    pos.setY(y);
}

void Concurrent::setPosition(const Point& p)
{
    pos = p;
}

/********* Surcharges d'operateurs *********/

bool Concurrent::operator<(const Concurrent &c)
{
    if (getNomConcurrent() < c.getNomConcurrent())
        return true;
    else
        return false;
}

bool Concurrent::operator==(const Concurrent& c)
{
    if (getNumeroMatricule() == c.getNumeroMatricule())
        return true;
    else
        return false;
}

ostream& operator<<(ostream& o, const Concurrent& c)
{
    cout.precision(4); // Permet de définir la précision d'affichage (nombre de chiffres après la virgule) d'un float/double
	o << "   " << c.getNumeroMatricule() << "  \t\t" << c.getNomConcurrent() << "\t\t" << c.getNiveauCapacite() << "\t\t" << c.getPlace() << "\t" << c.pos;

	return o;
}

istream& operator>>(istream& i, Concurrent& c)
{
	char nC[256];
	int choix = 0;
	cout << "Entrez le numero de matricule du concurrent: ";
	i >> c.numMatricule;
	i.ignore();
	cout << "Entrez le nom du concurrent: ";
	i.getline(nC, 256);
	while (choix < 1 || choix > 3)
    {
        cout << "Choississez un niveau de capacite: " << endl;
        cout << "\t1. Moyen (90%)" << endl;
        cout << "\t2. Bon (100%)" << endl;
        cout << "\t3. Avance (110%)" << endl;
        cout << "Votre choix: ";
        i >> choix;
    }

	c.setNomConcurrent(nC);
	if (choix == 1)
        c.setNiveauCapacite(0.9);
    if (choix == 2)
        c.setNiveauCapacite(1);
    if (choix == 3)
        c.setNiveauCapacite(1.1);
	c.setPlace(0);
	c.setNumeroBouee(0);

	return i;
}

/*******************************************/







