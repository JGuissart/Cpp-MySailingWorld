#ifndef ITERATEUR_H_INCLUDED
#define ITERATEUR_H_INCLUDED

#include "structCellule.h"
#include "MaListeTriee.h"

template <class T> class Iterateur
{
	private:
		Cellule<T> *pCourant;
	public:
		Iterateur(Cellule<T> *cell) : pCourant(cell) {};
		~Iterateur();

		bool hasNext();
		T next();
};

#endif // ITERATEUR_H_INCLUDED
