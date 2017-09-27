#include <cstdlib>
#include <ctime> // Fonction time(...), localtime(...), mktime(...)
#include <cstdio>
#include "Moment.h"
#include "InvalidMomentException.h"

using namespace std;

Moment::Moment()
{
    setValue(0);
    setDate(false);
}
Moment::Moment(int duree)
{
    Value = duree * 60;
    bDate = false;
}
Moment::Moment(int y, int m, int d)
{
    struct tm x;
    int iJourMax;

    if (y < 1970 || y > 2030)
        throw(InvalidMomentException("L'annee entree est incorrecte !"));
    if (m < 1 || m > 12)
        throw(InvalidMomentException("Le mois entre est incorrect !"));

    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            iJourMax = 31;
        break;
        case 4:
        case 6:
        case 9:
        case 11:
            iJourMax = 30;
        break;
        case 2:
        {
            if (this->IsBissextile())
                iJourMax = 29;
            else
                iJourMax = 28;
        }
        break;
    }
    if (d < 1 || d > iJourMax)
        throw(InvalidMomentException("Le jour entre est incorrect !"));

    x.tm_year = y - 1900;
    x.tm_mon = m - 1;
    x.tm_mday = d;
    x.tm_hour = 0;
    x.tm_min = 0;
    x.tm_sec = 0;
    x.tm_isdst = 0;
    Value = mktime(&x);

    bDate = true;
}
Moment::Moment(int y, int mon, int d, int h, int min)
{
    struct tm x;
    int iJourMax;

    if (y < 1970 || y > 2030)
        throw(InvalidMomentException("L'annee entree est incorrecte !"));
    if (mon < 1 || mon > 12)
        throw(InvalidMomentException("Le mois entre est incorrect !"));

    switch(mon)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            iJourMax = 31;
        break;
        case 4:
        case 6:
        case 9:
        case 11:
            iJourMax = 30;
        break;
        case 2:
        {
            if (this->IsBissextile())
                iJourMax = 29;
            else
                iJourMax = 28;
        }
        break;
    }
    if (d < 1 || d > iJourMax)
        throw(InvalidMomentException("Le jour entre est incorrect !"));
    if (h < 0 || h > 23)
        throw(InvalidMomentException("L'heure entree est incorrecte !"));
    if (min < 0 || min > 59)
        throw(InvalidMomentException("Le nombre de minutes entre est incorrect !"));

    x.tm_year = y - 1900;
    x.tm_mon = mon - 1;
    x.tm_mday = d;
    x.tm_hour = h;
    x.tm_min = min;
    x.tm_sec = 0;
    x.tm_isdst = 0;
    Value = mktime(&x);

    bDate = true;
}
Moment::Moment(const Moment &m)
{
    setValue(m.getValue());
    setDate(m.IsDate());
}
Moment::~Moment()
{

}

/********* Getters *********/

int Moment::getValue() const
{
    return Value;
}
bool Moment::IsDate() const
{
    return bDate;
}
bool Moment::IsBissextile() const
{
    struct tm *p;

    p = localtime((time_t *) &Value);

    if(((int)p->tm_year % 4 == 0 && (int)p->tm_year % 100 != 0) || (int)p->tm_year % 400 == 0)
        return true;
    else
        return false;
}
int Moment::getAnnee() const
{
    struct tm *p;

    p = localtime((time_t *) &Value);

    return p->tm_year + 1900;
}
int Moment::getMois() const
{
    struct tm *p;

    p = localtime((time_t *) &Value);

    return p->tm_mon + 1;
}
int Moment::getJour() const
{
    struct tm *p;

    p = localtime((time_t *) &Value);

    return p->tm_mday;
}
int Moment::getHeure() const
{
    struct tm *p;

    p = localtime((time_t *) &Value);

    return p->tm_hour;
}
int Moment::getMinute() const
{
    struct tm *p;

    p = localtime((time_t *) &Value);

    return p->tm_min;
}
int Moment::getSeconde() const
{
    struct tm *p;

    p = localtime((time_t *) &Value);

    return p->tm_sec;
}

/********* Setters *********/

void Moment::setValue(int v)
{
    Value = v;
}
void Moment::setDate(bool d)
{
    bDate = d;
}
void Moment::setAnnee(int y)
{
    struct tm *p;

    if (y < 1970 || y > 2030)
        throw(InvalidMomentException("Erreur de saisie de l'annee"));

    p = localtime((time_t *) &Value);

    p->tm_year = y - 1900;

    Value = mktime(p);
}
void Moment::setMois(int m)
{
    struct tm *p;

    if (m < 1 || m > 12)
        throw(InvalidMomentException("Erreur de saisie du mois"));

    p = localtime((time_t *) &Value);

    p->tm_mon = m - 1;

    Value = mktime(p);
}
void Moment::setJour(int j)
{
    struct tm *p;

    if (j < 1 || j > 31)
        throw(InvalidMomentException("Erreur de saisie du jour"));

    p = localtime((time_t *) &Value);

    p->tm_mday = j;

    Value = mktime(p);
}
void Moment::setHeure(int h)
{
    struct tm *p;

    if(h < 0 || h > 23)
        throw(InvalidMomentException("Erreur de saisie de l'heure"));

    p = localtime((time_t *) &Value);

    p->tm_hour = h;

    Value = mktime(p);
}
void Moment::setMinute(int m)
{
    struct tm *p;

    if(m < 0 || m > 59)
        throw(InvalidMomentException("Erreur de saisie des minutes"));

    p = localtime((time_t *) &Value);

    p->tm_min = m;

    Value = mktime(p);
}
void Moment::setSeconde(int s)
{
    struct tm *p;

    if (s < 0 || s > 59)
        throw(InvalidMomentException("Erreur de saisie des secondes"));

    p = localtime((time_t *) &Value);

    p->tm_sec = s;

    Value = mktime(p);
}

/********* Surcharges d'operateurs *********/

Moment& Moment::operator=(const Moment &m)
{
    Value = m.Value;
    bDate = m.bDate;

    return *this;
}
Moment Moment::operator+(int min)
{
    Moment m(*this);

    m.Value = m.Value + min * 60;

    return m;
}
Moment Moment::operator-(int min)
{
    Moment m(*this);

    m.Value = m.Value - min * 60;

    return m;
}
Moment Moment::operator+(const Moment &d)
{
    Moment m(*this);

    if (d.IsDate() && m.IsDate())
        throw(InvalidMomentException("Absurde d'additionner deux dates ..."));
    else
        m.Value = m.Value + d.Value;

    return m;
}
Moment Moment::operator-(const Moment &d)
{
    Moment m(*this);

    if (!(m.IsDate()) && d.IsDate())
        throw(InvalidMomentException("Absurde de soustraire une date d'un delai ..."));
    if (m.IsDate() && d.IsDate())
    {
        m.Value -= d.Value;
        m.setDate(false);
    }
    if (m.IsDate() && !(d.IsDate()))
        m.Value -= d.Value;

    if (!(m.IsDate()) && !(d.IsDate()))
        m.Value -= d.Value;

    return m;
}
ostream &operator<<(ostream &o, const Moment &m)
{
    o << m.ToString();

    return o;
}
istream &operator >>(istream &i, Moment &m)
{
    struct tm *p;

    p = localtime((time_t *) &m.Value);

    cout << "\tJour: ";
    i >> p->tm_mday;

    cout << "\tMois: ";
    i >> p->tm_mon;
    p->tm_mon = p->tm_mon - 1;

    cout << "\tAnnee: ";
    i >> p->tm_year;
    p->tm_year = p->tm_year - 1900;

    cout << "\tHeure: ";
    i >> p->tm_hour;

    cout << "\tMinutes: ";
    i >> p->tm_min;

    m.Value = mktime(p);
    m.bDate = true;

    return i;
}
bool Moment::operator<(const Moment &m)
{
    if ((IsDate() && !(m.IsDate())) || (!(IsDate()) && m.IsDate()))
        throw(InvalidMomentException("Absurde: on ne peut comparer que 2 dates ou 2 durees, mais pas une date et une duree"));

    if (Value < m.Value)
        return true;
    else
        return false;
}
bool Moment::operator>(const Moment &m)
{
    if ((IsDate() && !(m.IsDate())) || (!(IsDate()) && m.IsDate()))
        throw(InvalidMomentException("Absurde: on ne peut comparer que 2 dates ou 2 durees, mais pas une date et une duree"));

    if (Value > m.Value)
        return true;
    else
        return false;
}
bool Moment::operator==(const Moment &m)
{
    if ((IsDate() && !(m.IsDate())) || (!(IsDate()) && m.IsDate()))
        throw(InvalidMomentException("Absurde: on ne peut comparer que 2 dates ou 2 durees, mais pas une date et une duree"));

    if (Value == m.Value)
        return true;
    else
        return false;
}
Moment Moment::operator++()
{
    int ValueTemp = this->Value;
    struct tm *p;

    p = localtime((time_t *) &ValueTemp);

    p->tm_mday = p->tm_mday + 1;

    ValueTemp = mktime(p);

    this->Value = ValueTemp;

    return *this;
}
Moment Moment::operator++(int)
{
    Moment temp(*this);
    int ValueTemp = this->Value;
    struct tm *p;

    p = localtime((time_t *) &ValueTemp);

    p->tm_mday = p->tm_mday + 1;

    ValueTemp = mktime(p);

    this->Value = ValueTemp;

    return temp;
}

/*******************************************/

string Moment::ToString() const
{
    char buf[40];

    if (bDate)
        sprintf(buf, "%d/%d/%d %d:%d:%d", getJour(), getMois(), getAnnee(), getHeure(), getMinute(), getSeconde());
    else
    {
        int h, min, s;

        s = getValue();
        if (s < 0)
            s = -s;

        h = s / 3600;
        s = s % 3600;
        min = s / 60;
        s = s % 60;

        if (getValue() >= 0)
            sprintf(buf, "%d:%d:%d", h, min, s);
        else
            sprintf(buf,"- %d:%d:%d", h, min, s);
    }

    return string(buf);
}
Moment Moment::Now()
{
    Moment m;

	m.setDate(true);
	m.setValue(time(NULL));

	return m;
}
void Moment::save(ofstream &f)
{
    f.write((char*) &Value, sizeof(int));
    f.write((char*) &bDate, sizeof(bool));
}
void Moment::load(ifstream &f)
{
    f.read((char*) &Value, sizeof(int));
    f.read((char*) &bDate, sizeof(bool));
}
