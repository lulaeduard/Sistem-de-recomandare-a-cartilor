#include "Carte.h"

Carte::Carte(const std::string& titlu, const std::string& autor, const std::string& domeniu, int nivel)
    : titlu(titlu), autor(autor), domeniu(domeniu), nivelDificultate(nivel) {
}

std::string Carte::getTitlu() const {
    return titlu;
}

std::string Carte::getDomeniu() const {
    return domeniu;
}

int Carte::getNivelDificultate() const {
    return nivelDificultate;
}

std::string Carte::afisare() const {
    return "Titlu: " + titlu + ", Autor: " + autor + ", Domeniu: " + domeniu + ", Nivel: " + std::to_string(nivelDificultate);
}
