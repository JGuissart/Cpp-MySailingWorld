#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include <fstream>
#include <string.h>

class User
{
    private:
        std::string login;
        std::string mdp;
        std::string nom;
        std::string idRole;
    public:
        User(); // Constructeur par défaut
        User(std::string log);
        User(std::string log, std::string pass); // Constructeur d'initialisation (pour la connexion)
        User(std::string log, std::string pass, std::string n, std::string role); // Constructeur d'initialisation (pour une création d'un User)
        User(const User& U); //Constructeur de copie
        ~User(); // Destructeur

        /********* Getters *********/

        std::string getLogin() const;
        std::string getMotDePasse() const;
        std::string getNomUser() const;
        std::string getRole() const;

        /********* Setters *********/

        void setLogin(const std::string log);
        void setMotDePasse(const std::string pass);
        void setNomUser(const std::string n);
        void setRole(const std::string role);

        /********* Surcharges d'operateurs *********/

        User& operator=(const User &u);
        bool operator<(const User& u);
        bool operator>(const User& u);
        bool operator==(const User& u);
        bool operator!=(const User& u);
        friend std::ostream& operator<<(std::ostream& o, const User& u);
        friend std::istream& operator>>(std::istream& i, User& u);

        /*******************************************/

        void Affiche();
        void save(std::ofstream& f);
        void load(std::ifstream& f);
};

#endif // USER_H_INCLUDED
