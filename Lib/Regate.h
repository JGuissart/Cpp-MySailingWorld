#ifndef REGATE_H_INCLUDED
#define REGATE_H_INCLUDED

#include <cstring>
#include "Moment.h"
#include "Activite.h"
#include "Circuit.h"

class Regate : public Activite
{
    private:
        std::string nomCourse;
        Moment Depart;
        Circuit *pCircuit;
    public:
        Regate(); // Constructeur par défaut
        Regate(std::string nomAct, std::string lieuAct, const ObjetFlottant &POF, std::string nomCou, const Moment &dep); // Constructeur d'initialisation
        Regate(const Regate &R); // Constructeur de copie
        ~Regate(); // Destructeur

        /********* Getters *********/

        std::string GetInfo();
        std::string getNomCourse() const;
        Moment getDepart() const;
        Circuit getCircuit() const;
        Point getPoint(int i);
        int getNombreElementVecteur() const;

        /********* Setters *********/

        void setNomCourse(std::string nC);
        void setDepart(const Moment &M);
        //void setNomCircuit(const Circuit &c);

        /********* Surcharges d'operateurs *********/

        Regate& operator=(const Regate &r);
        bool operator==(const Regate &r);
        bool operator<(const Regate &r);
        friend std::ostream &operator<<(std::ostream &o, const Regate &r);
        friend std::istream &operator>>(std::istream &i, Regate &r);

        /*******************************************/

        void Affiche();
        void save(std::ofstream &f);
        void load(std::ifstream &f);
};

#endif // REGATE_H_INCLUDED
