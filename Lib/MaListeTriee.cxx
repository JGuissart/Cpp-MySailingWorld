#include "MaListeTriee.h"
#include "User.h"
#include "Regate.h"
#include "Concurrent.h"
#include "Pause.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

template <class T> MaListeTriee<T>::MaListeTriee()
{
    pTete = NULL;
    iTaille = 0;
}

template <class T> MaListeTriee<T>::MaListeTriee(MaListeTriee<T> &MLT)
{

}

template <class T> MaListeTriee<T>::~MaListeTriee()
{
    Cellule<T> *pTemp, *pPrec;

	pTemp = pTete;

	while (pTemp != NULL)
	{
		pPrec = pTemp;
		pTemp = pTemp->pNext;
		delete pPrec;
	}
}

/********* Getters *********/

template <class T> int MaListeTriee<T>::getTaille()
{
	return iTaille;
}

/********* Setters *********/



/********* Surcharges d'operateurs *********/



/*******************************************/

template <class T> bool MaListeTriee<T>::isEmpty()
{
    if (pTete == NULL)
        return true;
    else
        return false;
}

template <class T> void MaListeTriee<T>::inserer(const T& elem)
{
	Cellule<T> *pNew, *pTemp, *pPrec;

    pNew = new Cellule<T>;

    if (pNew != NULL)
    {
        pNew->val = elem;

        if (pTete == NULL) // Si la liste est vide
        {
            pNew->pNext = NULL;
            pTete = pNew;
        }
        else
        {
            pPrec = NULL;
            pTemp = pTete;

            while (pTemp != NULL && pTemp->val < pNew->val)
            {
                pPrec = pTemp;
                pTemp = pTemp->pNext;
            }

            if (pPrec == NULL) // Si on doit insérer en début de liste
            {
                pNew->pNext = pTete;
                pTete = pNew;
            }
            else
            {
                pNew->pNext = pTemp;
                pPrec->pNext = pNew;
            }
        }
        iTaille++;
    }
    else
        cout << "Erreur d'allocation de memoire ..." << endl;
}

template <class T> void MaListeTriee<T>::affiche()
{
    Iterateur<T> it = getIterateur();

    while(it.hasNext())
    {
        cout << endl << it.next() << endl;
        Pause();
    }
}

template <class T> bool MaListeTriee<T>::contenir(const T& elem)
{
	Iterateur<T> it = getIterateur();

	while(it.hasNext())
	{
		T org = it.next();
		if(org == elem)
            return true;
	}

	return false;
}

template <class T> T MaListeTriee<T>::recupererObjet(const T& elem)
{
    Iterateur<T> it = getIterateur();
    T Obj;
    bool bOk = false;

    while(it.hasNext() && !bOk)
	{
		T org = it.next();
		if(org == elem)
		{
		    Obj = org;
		    bOk = true;
		}
	}
	return Obj;
}

template <class T> void MaListeTriee<T>::clear()
{
	Cellule<T> *pCourant;

	pCourant = pTete;

	while(pCourant != NULL)
	{
		pTete = pCourant->pNext;
		delete(pCourant);
		pCourant = pTete;
		iTaille--;
	}
}

template <class T> void MaListeTriee<T>::supprimer(const T& elem)
{
	if(pTete == NULL)
		return; // la liste est vide -> rien faire

	Cellule<T>* pPrec = pTete;

	if(pPrec->val == elem) // si le premier élément est le bon -> efface
	{
		pTete = pPrec->pNext;
		delete(pPrec);
		iTaille--;
	}
	else
	{
		Cellule<T> *pTemp;

		pTemp = pTete->pNext;

		while(pTemp != NULL)
		{
			if(pTemp->val == elem)
			{
				pPrec->pNext = pTemp->pNext;
				delete(pTemp);
				pTemp = pPrec->pNext;
				iTaille--;
				return;
			}
			else
			{
				pPrec = pTemp;
				pTemp = pTemp->pNext;
			}
		}
	}
}

template <class T> Iterateur<T> MaListeTriee<T>::getIterateur()
{
	Iterateur<T> it(pTete);
	return it;
}

template class MaListeTriee<User>;
template class MaListeTriee<Regate>;
template class MaListeTriee<Concurrent>;
