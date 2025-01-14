#include "Admin.h"
#include <iostream>

Admin::Admin(const std::string& username, const std::string& parola)
    : Utilizator(username, parola) {
}

void Admin::adaugaCarte(std::vector<Carte>& carti, const Carte& carte) const {
    carti.push_back(carte);
}

void Admin::stergeCarte(std::vector<Carte>& carti, const std::string& titlu) const {
    carti.erase(std::remove_if(carti.begin(), carti.end(), [&](const Carte& carte) {
        return carte.getTitlu() == titlu;
        }), carti.end());
}

void Admin::vizualizeazaCarti(const std::vector<Carte>& carti) const {
    for (const auto& carte : carti) {
        std::cout << carte.afisare() << "\n";
    }
}

void Admin::vizualizeazaIstoric(const std::vector<std::pair<std::string, std::vector<std::string>>>& istoric) const {
    for (const auto& entry : istoric) {
        std::cout << "Utilizator: " << entry.first << "\nIstoric recomandari:\n";
        for (const auto& titlu : entry.second) {
            std::cout << "- " << titlu << "\n";
        }
        std::cout << "\n";
    }
}
