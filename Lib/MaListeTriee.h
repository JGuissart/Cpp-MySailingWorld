#ifndef MALISTETRIEE_H_INCLUDED
#define MALISTETRIEE_H_INCLUDED

#include "structCellule.h"
#include "Iterateur.h"

#include <fstream>

template <class T> class Iterateur;
template <class T> class MaListeTriee
{
	private:
		Cellule<T>* pTete;
		int iTaille;
    public:
        MaListeTriee(); // Constructeur par défaut
        MaListeTriee(const char* nF); // Constructeur d'initialisation
        MaListeTriee(MaListeTriee<T> &MLT); // Constructeur de copie
        ~MaListeTriee(); // Destructeur

        /********* Getters *********/

        int getTaille();

        /********* Setters *********/



        /********* Surcharges d'operateurs *********/



        /*******************************************/

        bool isEmpty();
        void inserer(const T& elem);
        void affiche();
        void clear();
        void supprimer(const T& elem);
        bool contenir(const T& elem);
        T recupererObjet(const T& elem);
        Iterateur<T> getIterateur();
};
#endif // MALISTETRIEE_H_INCLUDED
