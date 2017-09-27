#include "Iterateur.h"
#include "User.h"
#include "Regate.h"
#include "Concurrent.h"

#include <iostream>

using namespace std;

template <class T> Iterateur<T>::~Iterateur()
{
    
}

template <class T> bool Iterateur<T>::hasNext()
{
	return pCourant != NULL;
}

template <class T> T Iterateur<T>::next()
{
	T ret = pCourant->val;
	pCourant = pCourant->pNext;
	return ret;
}

template class Iterateur<User>;
template class Iterateur<Regate>;
template class Iterateur<Concurrent>;
