#include "Cercetator.h"
#include <iostream>

Cercetator::Cercetator(const std::string& username, const std::string& parola)
    : Utilizator(username, parola) {
}

void Cercetator::afiseazaTipUtilizator() const {
    std::cout << "Tip utilizator: Cercetator\n";
}
