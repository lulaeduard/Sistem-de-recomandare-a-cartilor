#include "Utilizator.h"

Utilizator::Utilizator(const std::string& username, const std::string& parola)
    : username(username), parola(parola) {
}

std::string Utilizator::getUsername() const {
    return username;
}

bool Utilizator::verificaParola(const std::string& parola) const {
    return this->parola == parola;
}
