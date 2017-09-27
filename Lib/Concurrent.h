#ifndef CONCURRENT_H_INCLUDED
#define CONCURRENT_H_INCLUDED

#include "Point.h"

#include <string>

class Concurrent
{
    private:
        int numMatricule;
        std::string nomConcurrent;
        float niveauCapacite;
        int place;
        Point pos;
        int numBouee;
    public:
        Concurrent();
        Concurrent(int nM, std::string nC, float lvlC);
        Concurrent(const Concurrent &c);
        ~Concurrent();

        /********* Getters *********/

        int getNumeroMatricule() const;
        std::string getNomConcurrent() const;
        float getNiveauCapacite() const;
        int getPlace() const;
        int getNumeroBouee() const;
        double getPositionX();
        double getPositionY();
        Point getPosition() const;

        /********* Setters *********/

        void setNumeroMatricule(const int nM);
        void setNomConcurrent(const std::string nC);
        void setNiveauCapacite(const float nC);
        void setPlace(const int pl);
        void setNumeroBouee(const int bouee);
        void setPositionX(const double x);
        void setPositionY(const double y);
        void setPosition(const Point& p);

        /********* Surcharges d'operateurs *********/

        bool operator<(const Concurrent &c);
        bool operator==(const Concurrent& c);
        friend std::ostream& operator<<(std::ostream& o, const Concurrent& c);
        friend std::istream& operator>>(std::istream& i, Concurrent& c);

        /*******************************************/
};

#endif // CONCURRENT_H_INCLUDED
