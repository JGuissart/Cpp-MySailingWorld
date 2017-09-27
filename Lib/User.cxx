#include "User.h"

#include <iostream>

using namespace std;

User::User()
{
    setLogin("admin");
    setMotDePasse("admin");
    setNomUser("admin");
    setRole("admin");
}

User::User(string log)
{
    setLogin(log);
    setMotDePasse("Defaut");
    setNomUser("Defaut");
    setRole("Defaut");
}

User::User(string log, string pass)
{
    setLogin(log);
    setMotDePasse(pass);
    setNomUser("Defaut");
    setRole("Defaut");
}

User::User(string log, string pass, string n, string role)
{
    setLogin(log);
    setMotDePasse(pass);
    setNomUser(n);
    setRole(role);
}

User::User(const User &U)
{
    setLogin(U.getLogin());
    setMotDePasse(U.getMotDePasse());
    setNomUser(U.getNomUser());
    setRole(U.getRole());
}

User::~User()
{

}

/********* Getters *********/

string User::getLogin() const
{
    return login;
}

string User::getMotDePasse() const
{
    return mdp;
}

string User::getNomUser() const
{
    return nom;
}

string User::getRole() const
{
    return idRole;
}

/********* Setters *********/

void User::setLogin(const string log)
{
    login = log;
}

void User::setMotDePasse(const string pass)
{
    mdp = pass;
}

void User::setNomUser(const string n)
{
    nom = n;
}

void User::setRole(const string role)
{
    idRole = role;
}

/********* Surcharges d'operateurs *********/

User& User::operator=(const User &u)
{
    setLogin(u.getLogin());
    setMotDePasse(u.getMotDePasse());
    setNomUser(u.getNomUser());
    setRole(u.getRole());

    return *this;
}

bool User::operator<(const User &u)
{
    if (strcmp(login.c_str(), u.login.c_str()) < 0)
        return true;
    else
        return false;
}

bool User::operator>(const User &u)
{
    if (strcmp(login.c_str(), u.login.c_str()) > 0)
        return true;
    else
        return false;
}

bool User::operator==(const User &u)
{
    if (getLogin() == u.getLogin())
        return true;
    else
        return false;
}

bool User::operator!=(const User& u)
{
    if (strcmp(login.c_str(), u.login.c_str()) != 0)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& o, const User& u)
{
    o << "Login: " << u.getLogin() << endl;
    o << "Nom: " << u.getNomUser() << endl;
    o << "Role: " << u.getRole() << endl;

    return o;
}

istream& operator>>(istream& i, User& u)
{
    int role = 0;

    cout << "Entrez le login: ";
    i >> u.login;
    cout << "Entrez le mot de passe: ";
    i >> u.mdp;
    cout << "Entrez le nom de l'utilisateur: ";
    i >> u.nom;
    while(role < 1 || role > 2)
    {
        cout << "Choississez un role: " << endl;
        cout << "\t1. Administrateur" << endl;
        cout << "\t2. Club" << endl;
        cout << "Votre choix: ";
        i >> role;
    }
    if (role == 1)
        u.setRole("admin");
    if (role == 2)
        u.setRole("club");

    return i;
}

/*******************************************/

void User::Affiche()
{
    cout << "Login: " << getLogin() << endl;
    cout << "Mot de passe: " << getMotDePasse() << endl;
    cout << "Nom: " << getNomUser() << endl;
    cout << "Role: " << getRole() << endl;
}

void User::save(ofstream &f)
{
    char buf[100];

    strcpy(buf, login.c_str());
    int n = strlen(buf);

    f.write((char*) &n, sizeof(int));
    f.write(buf, n);

    strcpy(buf, mdp.c_str());
    n = strlen(buf);

    f.write((char*) &n, sizeof(int));
    f.write(buf, n);

    strcpy(buf, nom.c_str());
    n = strlen(buf);

    f.write((char*) &n, sizeof(int));
    f.write(buf, n);

    strcpy(buf, idRole.c_str());
    n = strlen(buf);

    f.write((char*) &n, sizeof(int));
    f.write(buf, n);
}

void User::load(ifstream &f)
{
    char buf[100];
    int n;

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;
    setLogin(buf);

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;
    setMotDePasse(buf);

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;
    setNomUser(buf);

    f.read((char*) &n, sizeof(int));
    f.read(buf, n);
    buf[n] = 0;
    setRole(buf);
}
