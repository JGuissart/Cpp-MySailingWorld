#ifndef FONCTIONSREGATE_H_INCLUDED
#define FONCTIONSREGATE_H_INCLUDED

#include "MaListeTriee.h"
#include "Regate.h"
#include "FichierRegates.h"

void ajouterUneRegate(MaListeTriee<Regate> &lRegate, FichierRegates &fichierReg);
void afficherRegates(MaListeTriee<Regate> &lRegate);
void afficherUneRegate(MaListeTriee<Regate> &lRegate);
void suppressionRegate(MaListeTriee<Regate> &lRegate, FichierRegates &fichierReg);

#endif // FONCTIONSREGATE_H_INCLUDED
