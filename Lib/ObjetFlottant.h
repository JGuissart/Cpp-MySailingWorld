#ifndef DEF_OBJETFLOTTANT
#define DEF_OBJETFLOTTANT

#include <string>
#include "ModeleObjetFlottant.h"
#include <fstream>

class ObjetFlottant
{
    private:
        char identifiant[20];
        ModeleObjetFlottant modele;
    public:
        ObjetFlottant(); // Constructeur par defaut
        ObjetFlottant(const char* id, const ModeleObjetFlottant& m); // Constructeur d'initialisation
        ObjetFlottant(const ObjetFlottant& OF); // Constructeur de copie
        ~ObjetFlottant(); // Destructeur

        /********* Getters *********/

        const char* getIdentifiant() const;
        ModeleObjetFlottant getModele() const;

        /********* Setters *********/

        void setModele(const ModeleObjetFlottant& m);
        void setIdentifiant(const char* id);

        /********* Surcharges d'operateurs *********/

        friend std::ostream &operator<<(std::ostream &o, const ObjetFlottant &OF);
        friend std::istream& operator>>(std::istream &i, ObjetFlottant &OF);

        /*******************************************/

        void Affiche(); // Affichage des ids et des modeles
        void save(std::ofstream &f);
        void load(std::ifstream &f);
};

#endif
