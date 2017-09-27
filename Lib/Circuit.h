#ifndef CIRCUIT_H_INCLUDED
#define CIRCUIT_H_INCLUDED

#include "Vecteur.h"
#include "Point.h"
#include <string>
#include <iostream>

class Circuit
{
    private:
        std::string nomCircuit;
        Vecteur<Point> vec;
    public:
        Circuit();
        Circuit(std::string nC);
        Circuit(const Circuit &c);
        ~Circuit();

        /********* Getters *********/

        std::string getNomCircuit() const;
        Point getBouee(int i);
        int getNombreElementVecteur() const;

        /********* Setters *********/

        void setNomCircuit(const std::string& nC);
        void setVecteur(const Point& po);

        /********* Surcharges d'operateurs *********/

        friend std::ostream& operator<<(std::ostream& o, Circuit& cir);
        friend std::istream& operator>>(std::istream& i, Circuit& cir);
        Circuit& operator=(const Circuit& c);

        /*******************************************/

        void afficheBouees();
        void save(std::ofstream& f);
        void load(std::ifstream& f);
        void load(std::string nC);

};
#endif // CIRCUIT_H_INCLUDED
