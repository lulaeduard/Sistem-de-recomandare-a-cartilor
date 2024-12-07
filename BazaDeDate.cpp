#include "BazaDeDate.h"
#include <fstream>
#include <iostream>

void BazaDeDate::incarcaDate() {
    std::ifstream fisier("date.txt");
    std::string titlu, autor, domeniu;
    int nivel;

    while (fisier >> titlu >> autor >> domeniu >> nivel) {
        carti.emplace_back(titlu, autor, domeniu, nivel);
    }
    fisier.close();
}

void BazaDeDate::salveazaDate() const {
    std::ofstream fisier("date.txt");
    for (const auto& carte : carti) {
        fisier << carte.getTitlu() << " " << carte.getDomeniu() << " " << carte.getNivelDificultate() << "\n";
    }
    fisier.close();
}

bool BazaDeDate::autentificaUtilizator(const std::string& username, const std::string& parola) {
    std::ifstream fisier("utilizatori.txt");
    std::string user, pass;

    while (fisier >> user >> pass) {
        if (user == username && pass == parola) {
            return true;
        }
    }
    return false;
}

bool BazaDeDate::inregistreazaUtilizator(const std::string& username, const std::string& parola) {
    if (autentificaUtilizator(username, parola)) {
        std::cout << "Utilizatorul exista deja!\n";
        return false;
    }

    std::ofstream fisier("utilizatori.txt", std::ios::app);
    fisier << username << " " << parola << "\n";
    std::cout << "Cont creat cu succes!\n";
    return true;
}
