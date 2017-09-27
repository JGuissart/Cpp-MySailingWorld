#ifndef FONCTIONSCLUB_H_INCLUDED
#define FONCTIONSCLUB_H_INCLUDED

#include "MaListeTriee.h"
#include "FichierRegates.h"
#include "Regate.h"
#include "Concurrent.h"

char menuClub();
void choixMenuClub(char c, MaListeTriee<Regate> &lRegate, FichierRegates &fichierReg, MaListeTriee<Concurrent> &lTConcurrent);
char sousMenuCircuit();
char sousMenuRegate();
char sousMenuRegateChoisie();
void choixMenuCircuit(char c);
void choixMenuRegate(char c, MaListeTriee<Regate> &lRegate, FichierRegates &fichierReg);
void choixMenuRegateChoisie(char c, MaListeTriee<Concurrent> &lTConcurrent, MaListeTriee<Regate> &lTRegate);

#endif // FONCTIONSCLUB_H_INCLUDED
