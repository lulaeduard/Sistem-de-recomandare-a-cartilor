#ifndef ADMIN_H
#define ADMIN_H

#include "Utilizator.h"
#include "Carte.h"
#include <vector>
#include <string>

class Admin : public Utilizator {
public:
    Admin(const std::string& username, const std::string& parola);
    void adaugaCarte(std::vector<Carte>& carti, const Carte& carte) const;
    void stergeCarte(std::vector<Carte>& carti, const std::string& titlu) const;
    void vizualizeazaCarti(const std::vector<Carte>& carti) const;
    void vizualizeazaIstoric(const std::vector<std::pair<std::string, std::vector<std::string>>>& istoric) const;
};

#endif
