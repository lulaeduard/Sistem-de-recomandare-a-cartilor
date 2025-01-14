

#include "SistemDeRecomandare.h"
#include <iostream>
#include <limits>

int main() {
    SistemDeRecomandare sistem;


    while (true) {
        std::cout << "\nBine ati venit in sistemul de recomandare!\n";
        std::cout << "1. Autentificare\n";
        std::cout << "2. Inregistrare\n";
        std::cout << "3. Iesire\n";
        std::cout << "Alegeti o optiune: ";

        int optiune;
        std::cin >> optiune;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input invalid. Va rugam sa incercati din nou.\n";
            continue;
        }

        if (optiune == 1) {
            std::string username, parola;
            std::cout << "Introduceti username: ";
            std::cin >> username;
            std::cout << "Introduceti parola: ";
            std::cin >> parola;

            std::cout << "Se verifica autentificarea pentru: " << username << "\n";

            if (sistem.autentificaUtilizator(username, parola)) {
                std::cout << "Autentificare reusita!\n";
                bool loggedIn = true;
                while (loggedIn) {
                    std::cout << "\n1. Cere recomandari\n";
                    std::cout << "2. Delogare\n";
                    std::cout << "Alegeti o optiune: ";

                    int suboptiune;
                    std::cin >> suboptiune;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Input invalid. Va rugam sa incercati din nou.\n";
                        continue;
                    }

                    std::cout << "Optiune selectata in submeniu: " << suboptiune << "\n";

                    switch (suboptiune) {
                    case 1:
                        std::cout << "Se initiaza recomandarea...\n";
                        sistem.intreabaUtilizator(username);
                        break;
                    case 2:
                        std::cout << "Delogare reusita!\n";
                        loggedIn = false;
                        break;
                    default:
                        std::cout << "Optiune invalida! Va rugam sa alegeti 1 sau 2.\n";
                        break;
                    }
                }
            }
            else {
                std::cout << "Username sau parola incorecta!\n";
            }
        }
        else if (optiune == 2) {
            std::string username, parola;
            std::cout << "Introduceti username: ";
            std::cin >> username;
            std::cout << "Introduceti parola: ";
            std::cin >> parola;

            sistem.inregistreazaUtilizator(username, parola);
        }
        else if (optiune == 3) {
            sistem.salveazaDate();
            std::cout << "La revedere!\n";
            break;
        }
        else {
            std::cout << "Optiune invalida! Va rugam sa alegeti 1, 2 sau 3.\n";
        }
    }

    return 0;
}

