#ifndef FICHIERCIRCUITS_H_INCLUDED
#define FICHIERCIRCUITS_H_INCLUDED

#include "Circuit.h"
#include <fstream>

class FichierCircuits
{
    private:
        char nomFichier[50];
        int iNbrePoint;
    public:
        FichierCircuits(const char* nF); // Constructeur d'initialisation
        ~FichierCircuits(); // Destructeur

        /********* Getters *********/

        const char* getNomFichier() const;
        int getNombrePoints() const;

        /********* Setters *********/

        void setNomFichier(const char* nF);
        void setNombrePoints(int n);

        /********* Surcharges d'operateurs *********/



        /*******************************************/

        void save(Circuit& c);
        void load(Circuit& c);
};

#endif // FICHIERCIRCUITS_H_INCLUDED
