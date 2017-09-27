#ifndef FONCTIONSADMIN_H_INCLUDED
#define FONCTIONSADMIN_H_INCLUDED

#include "MaListeTriee.h"
#include "User.h"
#include "FichierUsers.h"

char menuAdmin();
void choixMenuAdmin(char c, MaListeTriee<User> &lUser, FichierUsers &fichierUsr);
void afficheUsers(MaListeTriee<User> &lUser);
void afficheUser(MaListeTriee<User> &lUser);
void creerUser(MaListeTriee<User> &lUser, FichierUsers &fichierUsr);
void changerMDP(MaListeTriee<User> &lUser, FichierUsers &fichierUsr);

#endif // FONCTIONSADMIN_H_INCLUDED
