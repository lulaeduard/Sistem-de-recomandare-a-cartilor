#include "Recomandare.h"
#include <iostream>
#include <string>

Recomandare::Recomandare() {
    bazaDeDate.incarcaDate();
}

void Recomandare::init() {
    bazaDeDate.incarcaDate();
    meniuPrincipal();
}

void Recomandare::meniuPrincipal() {
    int optiune;
    do {
        std::cout << "1. Login\n2. Inregistrare\n3. Iesire\n";
        std::cout << "Alege o optiune: ";
        std::cin >> optiune;

        switch (optiune) {
            case 1: login(); break;
            case 2: inregistrare(); break;
            case 3: std::cout << "La revedere!\n"; break;
            default: std::cout << "Optiune invalida!\n"; break;
        }
    } while (optiune != 3);
}

void Recomandare::login() {
    std::string username, parola;

    std::cout << "Introdu username: ";
    std::cin >> username;
    std::cout << "Introdu parola: ";
    std::cin >> parola;

    if (bazaDeDate.autentificaUtilizator(username, parola)) {
        std::cout << "Autentificare reușită! Bine ai venit, " << username << "!\n";
        intreabaUtilizator();
    } else {
        std::cout << "Autentificare esuata! Utilizator sau parola gresita.\n";
    }
}

void Recomandare::inregistrare() {
    std::string username, parola;

    std::cout << "Introdu username: ";
    std::cin >> username;
    std::cout << "Introdu parola: ";
    std::cin >> parola;

    bazaDeDate.inregistreazaUtilizator(username, parola);
}

void Recomandare::intreabaUtilizator() {
    std::string domeniu;
    int nivel;

    std::cout << "Domeniu: ";
    std::cin >> domeniu;

    std::cout << "Nivel (1 - Incepator, 2 - Mediu, 3 - Avansat): ";
    std::cin >> nivel;

    auto recomandari = bazaDeDate.recomandaCarti(domeniu, nivel);

    if (recomandari.empty()) {
        std::cout << "Nicio carte gasita!\n";
    } else {
        for (const auto& carte : recomandari) {
            std::cout << carte.afisare() << "\n";
        }
    }
}
