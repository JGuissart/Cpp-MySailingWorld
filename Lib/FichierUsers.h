#ifndef FICHIERUSERS_H_INCLUDED
#define FICHIERUSERS_H_INCLUDED

#include "MaListeTriee.h"
#include "User.h"
#include <fstream>

class FichierUsers
{
    private:
        char nomFichier[50];
        int iNbreEnreg;
    public:
        FichierUsers(); // Constructeur par défaut
        FichierUsers(const char* nF); // Constructeur d'initialisation
        ~FichierUsers(); // Destructeur

        /********* Getters *********/

        const char* getNomFichier() const;
        int getNombreEnregistrement() const;

        /********* Setters *********/

        void setNomFichier(const char* nF);
        void setNombreEnregistrement(int nE);

        /********* Surcharges d'operateurs *********/



        /*******************************************/

        int recupNombreEnregistrement(const char* nF);
        void save(User &u);
        void load(MaListeTriee<User> &lUser);
        void list();
};

#endif // FICHIERUSERS_H_INCLUDED
