#ifndef BAZADEDATE_H
#define BAZADEDATE_H

#include <vector>
#include <string>
#include "Carte.h"

class BazaDeDate {
private:
    std::vector<Carte> carti;

public:
    void incarcaDate();
    void salveazaDate() const;
    bool autentificaUtilizator(const std::string& username, const std::string& parola);
    bool inregistreazaUtilizator(const std::string& username, const std::string& parola);
    void adaugaCarte(const Carte& carte);
    std::vector<Carte> recomandaCarti(const std::string& domeniu, int nivel) const;
};

#endif
