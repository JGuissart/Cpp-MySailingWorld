#ifndef VECTEUR_H_INCLUDED
#define VECTEUR_H_INCLUDED

#include <iostream>
#include "InvalidContainersException.h"

template <class T> class Vecteur
{
    private:
        T *data;
        bool *occ;
        int iTailleVec;
        int iNbreElem;
    public:
        Vecteur();
        Vecteur(int n);
        ~Vecteur();

        /********* Getters *********/

        T getElement(int n);
        int getNombreElement() const;

        /********* Setters *********/

        void setElement(int n, const T& elem);
        void setNombreElement(int n);

        /********* Surcharges d'operateurs *********/

        Vecteur<T>& operator=(const Vecteur<T>& vec);
        T operator[](int n);
        void operator+(const T& elem);

        /*******************************************/

        void affiche();
        void affiche(int n);
        bool indiceValide(int n);
        bool estOccupe(int n);
        T retireElement(int n);
};

#endif // VECTEUR_H_INCLUDED

