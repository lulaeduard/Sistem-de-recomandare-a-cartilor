#include "SistemDeRecomandare.h"
#include <iostream>
#include <fstream>
#include "Admin.h"

SistemDeRecomandare::SistemDeRecomandare() {
    incarcaDate();
}

void SistemDeRecomandare::incarcaDate() {
    std::ifstream fisier("date.txt");
    std::string titlu, autor, domeniu;
    int nivel;

    while (fisier >> titlu >> autor >> domeniu >> nivel) {
        carti.emplace_back(titlu, autor, domeniu, nivel);
    }
    fisier.close();
}

void SistemDeRecomandare::salveazaDate() const {
    std::ofstream fisier("date.txt", std::ios::app);
    for (const auto& carte : carti) {
        fisier << carte.getTitlu() << " " << carte.getDomeniu() << " " << carte.getNivelDificultate() << "\n";
    }
    fisier.close();
}

bool SistemDeRecomandare::autentificaUtilizator(const std::string& username, const std::string& parola) {
    std::ifstream fisier("utilizatori.txt");
    std::string user, pass;

    while (fisier >> user >> pass) {
        if (user == username && pass == parola) {
            return true;
        }
    }
    return false;
}

bool SistemDeRecomandare::inregistreazaUtilizator(const std::string& username, const std::string& parola) {
    if (autentificaUtilizator(username, parola)) {
        std::cout << "Utilizatorul exista deja!\n";
        return false;
    }

    std::ofstream fisier("utilizatori.txt", std::ios::app);
    fisier << username << " " << parola << "\n";
    std::cout << "Cont creat cu succes!\n";
    return true;
}

void SistemDeRecomandare::intreabaUtilizator(const std::string& username) {
    if (username == "admin") {
        Admin admin(username, ""); // presupunem că parola e deja validată
        int adminOptiune;
        do {
            std::cout << "\nMeniu administrator:\n";
            std::cout << "1. Adauga carte\n";
            std::cout << "2. Sterge carte\n";
            std::cout << "3. Vizualizeaza carti\n";
            std::cout << "4. Vizualizeaza istoric recomandari\n";
            std::cout << "5. Delogare\n";
            std::cout << "Alegeti o optiune: ";
            std::cin >> adminOptiune;

            switch (adminOptiune) {
            case 1: {
                std::string titlu, autor, domeniu;
                int nivel;
                std::cout << "Introduceti detaliile cartii:\n";
                std::cout << "Titlu: ";
                std::cin >> titlu;
                std::cout << "Autor: ";
                std::cin >> autor;
                std::cout << "Domeniu: ";
                std::cin >> domeniu;
                std::cout << "Nivel (1-3): ";
                std::cin >> nivel;
                carti.emplace_back(titlu, autor, domeniu, nivel);
                std::cout << "Cartea a fost adaugata cu succes.\n";
                break;
            }
            case 2: {
                std::string titlu;
                std::cout << "Introduceti titlul cartii de sters: ";
                std::cin >> titlu;
                carti.erase(std::remove_if(carti.begin(), carti.end(), [&titlu](const Carte& carte) {
                    return carte.getTitlu() == titlu;
                    }), carti.end());
                std::cout << "Cartea a fost stearsa (daca a existat).\n";
                break;
            }
            case 3: {
                std::cout << "Lista de carti:\n";
                for (const auto& carte : carti) {
                    std::cout << carte.afisare() << "\n";
                }
                break;
            }
            case 4: {
                std::cout << "Istoric recomandari:\n";
                for (const auto& entry : istoric) {
                    std::cout << "Utilizator: " << entry.first << "\n";
                    for (const auto& titlu : entry.second) {
                        std::cout << "  - " << titlu << "\n";
                    }
                }
                break;
            }
            case 5:
                std::cout << "Delogare reusita.\n";
                break;
            default:
                std::cout << "Optiune invalida.\n";
                break;
            }
        } while (adminOptiune != 5);
        return;
    }

    int tipUtilizator;
    std::cout << "\nSunteti student sau cercetator?\n";
    std::cout << "1. Student\n";
    std::cout << "2. Cercetator\n";
    std::cout << "Alegeti o optiune: ";
    std::cin >> tipUtilizator;

    if (std::cin.fail() || (tipUtilizator != 1 && tipUtilizator != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Optiune invalida!\n";
        return;
    }

    std::string domeniu;
    int nivel;

    std::cout << "Domeniu: ";
    std::cin >> domeniu;

    std::cout << "Nivel (1 - Incepator, 2 - Mediu, 3 - Avansat): ";
    std::cin >> nivel;

    if (std::cin.fail() || nivel < 1 || nivel > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Nivel invalid!\n";
        return;
    }

    auto recomandari = recomandaCarti(domeniu, nivel);

    if (recomandari.empty()) {
        std::cout << "Nicio carte gasita!\n";
    }
    else {
        std::cout << "Carti recomandate:\n";
        for (const auto& carte : recomandari) {
            std::cout << carte.afisare() << "\n";
        }

        // Salvare in istoric
        for (auto& entry : istoric) {
            if (entry.first == username) {
                for (const auto& carte : recomandari) {
                    entry.second.push_back(carte.getTitlu());
                }
                return;
            }
        }

        istoric.emplace_back(username, std::vector<std::string>());
        for (const auto& carte : recomandari) {
            istoric.back().second.push_back(carte.getTitlu());
        }
    }
}

std::vector<Carte> SistemDeRecomandare::recomandaCarti(const std::string& domeniu, int nivel) {
    std::vector<Carte> recomandari;
    for (const auto& carte : carti) {
        if (carte.getDomeniu() == domeniu && carte.getNivelDificultate() == nivel) {
            recomandari.push_back(carte);
        }
    }
    return recomandari;
}
