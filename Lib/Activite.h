#ifndef ACTIVITE_H_INCLUDED
#define ACTIVITE_H_INCLUDED

#include "ObjetFlottant.h"
#include <string>
#include <iostream>
#include <fstream>

class Activite
{
    protected:
        std::string nomActivite;
        std::string lieuActivite;
        ObjetFlottant *pObjetFlottant;
    public:
        Activite(); // Constructeur par defaut
        Activite(std::string nA, std::string lA, const ObjetFlottant &POF); // Constructeur d'initialisation
        Activite(const Activite &a); // Constructeur de copie
        virtual ~Activite(); // Destructeur

        /********* Getters *********/

        virtual std::string GetInfo() = 0; // Permet de définir la classe Activite comme "abstraite"
        std::string getNom() const;
        std::string getLieu() const;
        ObjetFlottant getObjetFlottant() const;

        /********* Setters *********/

        void setNom(std::string nA);
        void setLieu(std::string lA);
        void setObjetFlottant(const ObjetFlottant &OF);

        /********* Surcharges d'operateurs *********/

        //Activite& operator=(const Activite &a);
        friend std::ostream& operator<<(std::ostream &o, const Activite &a);
        friend std::istream& operator>>(std::istream &i, Activite &a);

        /*******************************************/

        virtual void Affiche();
        void save(std::ofstream &f);
        void load(std::ifstream &f);
};
#endif // ACTIVITE_H_INCLUDED

