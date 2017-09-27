#include "Regate.h"
#include "Moment.h"

#include <sstream>

using namespace std;

Regate::Regate() : Activite()
{
    setNomCourse("Defaut");
    pCircuit = NULL;
    pCircuit = new Circuit;
}

Regate::Regate(string nomAct, string lieuAct, const ObjetFlottant &POF, string nomCou, const Moment &dep) : Activite(nomAct, lieuAct, POF) // : Activite(...) permet d'appeler le constructeur d'initialisation d'Activite
{
    setNomCourse(nomCou);
    setDepart(dep);
    pCircuit = NULL;
    pCircuit = new Circuit;
}

Regate::Regate(const Regate &R)
{
    setNom(R.getNom());
    setLieu(R.getLieu());
    setObjetFlottant(R.getObjetFlottant());
    setNomCourse(R.getNomCourse());
    setDepart(R.getDepart());
    pCircuit = NULL;
    pCircuit = new Circuit;
    *pCircuit = *(R.pCircuit);
}

Regate::~Regate()
{
    if (pCircuit)
        delete pCircuit;
}

/********* Getters *********/

string Regate::getNomCourse() const
{
    return nomCourse;
}

Moment Regate::getDepart() const
{
    return Depart;
}

Circuit Regate::getCircuit() const
{
    return *pCircuit;
}

Point Regate::getPoint(int i)
{
    return pCircuit->getBouee(i);
}

int Regate::getNombreElementVecteur() const
{
    return pCircuit->getNombreElementVecteur();
}

string Regate::GetInfo()
{
	ostringstream out;   // équivalent du sprintf mais plus optimisé
	out << "REGATE: " << nomActivite << "#" << nomCourse << endl;
	return out.str();
}

/********* Setters *********/

void Regate::setNomCourse(string nC)
{
    nomCourse = nC;
}

void Regate::setDepart(const Moment &M)
{
    Depart = M;
}

/********* Surcharges d'operateurs *********/

bool Regate::operator<(const Regate &r)
{
    if (getDepart() < r.getDepart())
        return true;
    else
        return false;
}

bool Regate::operator==(const Regate &r)
{
    if (getNomCourse() == r.getNomCourse())
        return true;
    else
        return false;
}

ostream& operator<<(ostream& o, const Regate& r)
{
    o << (Activite&)r; // Casting pour récupérer operator<< d'Activite
    o << "Nom de la course: " << r.nomCourse << endl;
    o << "Depart de la course: " << r.Depart.ToString() << endl;
    o << endl;
    o << "Donnees du circuit: " << endl << *(r.pCircuit) << endl;

    return o;
}

istream& operator>>(istream &i, Regate &r)
{
    char nC[256];
    Moment Dep;

    i >> (Activite&)r; // Casting pour récupérer operator>> d'Activite
    cout << "Nom de la course: ";
    i.ignore(); // Permet de vider le buffer
    i.getline(nC, 256); // Si on n'utilise pas cette méthode, operator>> ne prendra en compte que le premier mot entré et mettra les autres là où il le pourra
    cout << "Depart de la course: " << endl;
    i >> Dep; // Dep étant un moment, il va aller dans operator>> de la classe Moment pour encoder la date et l'heure
    cout << "Informations du circuit: " << endl;
    i >> *(r.pCircuit);

    r.nomCourse = nC;
    r.Depart = Dep;

    return i;
}

Regate& Regate::operator=(const Regate &r)
{
    nomActivite = r.nomActivite;
    lieuActivite = r.lieuActivite;
    *pObjetFlottant = *(r.pObjetFlottant);
    nomCourse = r.nomCourse;
    Depart = r.Depart;
    *pCircuit = *(r.pCircuit);

    return *this;
}

/*******************************************/

void Regate::Affiche()
{
    cout << "Nom de l'activite: " << getNom() << endl;
    cout << "Lieu de l'activite: " << getLieu() << endl;
    cout << "Objet Flottant: " << getObjetFlottant() << endl;
    cout << "Nom de la course: " << getNomCourse() << endl;
    cout << "Depart de la course: " << getDepart() << endl;
    cout << endl;
}

void Regate::save(ofstream &f)
{
    Activite::save(f);
    Depart.save(f);

    char buf[100];
    strcpy(buf, nomCourse.c_str());
    int n = strlen(buf);

    f.write((char*) &n, sizeof(int));
    f.write(buf, n);

    string nomCir;
    nomCir = pCircuit->getNomCircuit();

    strcpy(buf, nomCir.c_str());
    n = strlen(buf);

    f.write((char*) &n, sizeof(int));
    f.write(buf, n);
}

void Regate::load(ifstream &f)
{
    Activite::load(f);
    Depart.load(f);

    char buf[100];
    int n;

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;

    setNomCourse(buf);

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;

    pCircuit->load(buf);
}
