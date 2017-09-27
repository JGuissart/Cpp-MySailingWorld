#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include <fstream>

class Point
{
    private:
        double x;
        double y;
    public:
        Point();
        Point(double valX, double valY);
        ~Point();
        Point(const Point& p);

        /********* Getters *********/

        double getX();
        double getY();

        /********* Setters *********/

        void setX(double val);
        void setY(double val);

        /********* Surcharges d'operateurs *********/

        friend std::ostream& operator<<(std::ostream& o, const Point &po);
        friend std::istream& operator>>(std::istream& i, Point &po);
        Point& operator=(const Point& p);
        Point operator-(const Point &po);

        /*******************************************/

        void save(std::ofstream& f);
        void load(std::ifstream& f);

};

#endif // POINT_H_INCLUDED
