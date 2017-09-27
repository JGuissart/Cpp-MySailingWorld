#ifndef FONCTIONSREGATECHOISIE_H_INCLUDED
#define FONCTIONSREGATECHOISIE_H_INCLUDED

#include "MaListeTriee.h"
#include "Concurrent.h"
#include "Regate.h"

void ajouterUnConcurrent(MaListeTriee<Concurrent> &lTConcurrent);
void ajouterUnConcurrentAPDFichier(MaListeTriee<Concurrent> &lTConcurrent);
void lancerUneRegate(MaListeTriee<Regate> &lTRegate, MaListeTriee<Concurrent> &lTConcurrent);

#endif // FONCTIONSREGATECHOISIE_H_INCLUDED
