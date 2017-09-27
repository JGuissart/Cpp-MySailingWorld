#include "Point.h"

using namespace std;

Point::Point()
{
    setX(0);
    setY(0);
}

Point::Point(double valX, double valY)
{
    setX(valX);
    setY(valY);
}

Point::Point(const Point& p)
{
    setX(p.x);
    setY(p.y);
}

Point::~Point()
{

}

/********* Getters *********/

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

/********* Setters *********/

void Point::setX(double valX)
{
    x = valX;
}

void Point::setY(double valY)
{
    y = valY;
}

/********* Surcharges d'operateurs *********/

ostream& operator<<(ostream& o, const Point &po)
{
    o << "\t(" << po.x << "; " << po.y << ")" << endl;

    return o;
}

istream& operator>>(istream& i, Point &po)
{
    cout << "x: ";
    i >> po.x;
    cout << "y: ";
    i >> po.y;

    return i;
}

Point& Point::operator=(const Point& p)
{
    x = p.x;
    y = p.y;

    return *this;
}

Point Point::operator-(const Point &po)
{
    Point p(*this);

    p.x = p.x - po.x;
    p.y = p.y - po.y;

    return p;
}

/*******************************************/

void Point::save(ofstream &f)
{
    f.write((char*) &x, sizeof(double));
    f.write((char*) &y, sizeof(double));
}

void Point::load(ifstream &f)
{
    f.read((char*) &x, sizeof(double));
    f.read((char*) &y, sizeof(double));
}
