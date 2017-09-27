#ifndef MODELEOBJETFLOTTANT_H_INCLUDED
#define MODELEOBJETFLOTTANT_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>

class ModeleObjetFlottant
{
    private:
        std::string constructeur;
        std::string modele;
        float taille;
    public:
        ModeleObjetFlottant(); // Constructeur par defaut
        ModeleObjetFlottant(std::string c, std::string m, float t); // Constructeur d'initialisation
        ModeleObjetFlottant(const ModeleObjetFlottant& MOF); // Constructeur de copie
        ~ModeleObjetFlottant(); // Constructeur de copie

        /********* Getters *********/

        std::string getConstructeur() const;
        std::string getModele() const;
        float getTaille() const;

        /********* Setters *********/

        void setConstructeur(std::string c);
        void setModele(std::string m);
        void setTaille(float t);

        /********* Surcharges d'operateurs *********/

        friend std::ostream& operator<<(std::ostream &o, const ModeleObjetFlottant &MOF);
        friend std::istream& operator>>(std::istream &i, ModeleObjetFlottant &MOF);

        /*******************************************/

        void Affiche();
        static std::string HOBIE;
        static std::string BICSPORT;
        static ModeleObjetFlottant HOBIE_14;
        static ModeleObjetFlottant HOBIE_16;
        void save(std::ofstream &f);
        void load(std::ifstream &f);
};

#endif // MODELEOBJETFLOTTANT_H_INCLUDED
