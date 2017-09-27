#include "Vecteur.h"
#include "Point.h"
#include "Concurrent.h"

#include <iostream>

using namespace std;

template <class T> Vecteur<T>::Vecteur()
{
    data = NULL;
    data = new T[20];
    occ = NULL;
    occ = new bool[20];
    for (int i = 0; i < 20; i++)
        occ[i] = false;
    iTailleVec = 20;
    iNbreElem = 0;
}

template <class T> Vecteur<T>::Vecteur(int n)
{
    data = NULL;
    data = new T[n];
    occ = NULL;
    occ = new bool[n];
    for (int i = 0; i < n; i++)
        occ[i] = false;
    iTailleVec = n;
    iNbreElem = 0;
}

template <class T> Vecteur<T>::~Vecteur()
{
    if (data)
        delete[] data;
    if (occ)
        delete [] occ;
}

/********* Getters *********/

template <class T> T Vecteur<T>::getElement(int n)
{
    return data[n];
}

template <class T> int Vecteur<T>::getNombreElement() const
{
    return iNbreElem;
}

/********* Setters *********/

template <class T> void Vecteur<T>::setElement(int n, const T& elem)
{
    data[n] = elem;
    occ[n] = true;
    iNbreElem++;
}

template <class T> void Vecteur<T>::setNombreElement(int n)
{
    iNbreElem = n;
}

/********* Surcharges d'operateurs *********/

template <class T> Vecteur<T>& Vecteur<T>::operator=(const Vecteur<T>& vec)
{
    for (int i = 0; i < iTailleVec; i++)
    {
        data[i] = vec.data[i];
        occ[i] = vec.occ[i];
    }
    iNbreElem = vec.iNbreElem;

    return *this;
}

template <class T> T Vecteur<T>::operator[](int n)
{
    return data[n];
}

template <class T> void Vecteur<T>::operator+(const T& elem)
{
    int i = 0;
    bool bTrouve = false;
    while (i < iTailleVec && !bTrouve)
    {
        if (estOccupe(i))
            i++;
        else
            bTrouve = true;
    }
    if (bTrouve)
    {
        data[i] = elem;
        occ[i] = true;
        iNbreElem++;
    }
    if (i == iTailleVec)
        throw(InvalidContainersException("ERREUR: le vecteur est plein !"));
}

/*******************************************/

template <class T> void Vecteur<T>::affiche()
{
    for (int i = 0; estOccupe(i); i++)
    {
        if (estOccupe(i))
        {
            if (!i)
                cout << "\tBouee de depart: " << getElement(i) << endl;
            if (i == iNbreElem - 1)
                cout << "\tBouee d'arrivee: " << getElement(i) << endl;
            if (i != 0 && i != iNbreElem - 1)
                cout << "\tBouee " << i + 1 << " :" << getElement(i) << endl;
        }
    }
}
template <class T> void Vecteur<T>::affiche(int n)
{
    int i = 0;
    while (estOccupe(i) && i < n)
    {
        cout << getElement(i);
        i++;
    }
}

template <class T> bool Vecteur<T>::indiceValide(int n)
{
	if (n >= iTailleVec)
		throw(InvalidContainersException("ERREUR: l'indice du vecteur n'est pas valide !"));
		
    if (n < iTailleVec)
        return true;
    else
        return false;
}

template <class T> bool Vecteur<T>::estOccupe(int n)
{
    return occ[n];
}

template <class T> T Vecteur<T>::retireElement(int n)
{
    occ[n] = false;
    return data[n];
    iNbreElem--;
}

template class Vecteur<Point>;
template class Vecteur<Concurrent>;
