#ifndef SISTEMDERECOMANDARE_H
#define SISTEMDERECOMANDARE_H

#include <vector>
#include <string>
#include "Carte.h"
#include "Utilizator.h"
#include "Student.h"
#include "Cercetator.h"
#include "Admin.h"

class SistemDeRecomandare {
private:
    std::vector<Carte> carti;
    std::vector<std::pair<std::string, std::vector<std::string>>> istoric;

public:
    SistemDeRecomandare();
    void incarcaDate();
    void salveazaDate() const;
    bool autentificaUtilizator(const std::string& username, const std::string& parola);
    bool inregistreazaUtilizator(const std::string& username, const std::string& parola);
    void init();
    void intreabaUtilizator(const std::string& username);
    std::vector<Carte> recomandaCarti(const std::string& domeniu, int nivel);
};

#endif
