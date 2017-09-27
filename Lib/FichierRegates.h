#ifndef FICHIERREGATES_H_INCLUDED
#define FICHIERREGATES_H_INCLUDED

#include <string>
#include "Regate.h"
#include "MaListeTriee.h"

class FichierRegates
{
    private:
        char nomFichier[50];
        int iNbreEnreg;
    public:
        FichierRegates(); // Constructeur par défaut
        FichierRegates(const char* nF); // Constructeur d'initialisation
		~FichierRegates(); // Destructeur

        /********* Getters *********/

        const char* getNomFichier() const;
        int getNombreEnregistrement() const;

        /********* Setters *********/

        void setNomFichier(const char* nF);
        void setNombreEnregistrement(int nE);

        /*******************************************/

        void load(MaListeTriee<Regate> &lRegate);
        void save(Regate &r);
        int load(Regate& R, const char* nR);
        void list();
        int recupNombreEnregistrement(const char* nF);

};

#endif // FICHIERREGATES_H_INCLUDED
