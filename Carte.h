#ifndef CARTE_H
#ifndef CARTE_H
#define CARTE_H

#include <string>

class Carte {
private:
    std::string titlu;
    std::string autor;
    std::string domeniu;
    int nivelDificultate;

public:
    Carte(const std::string& titlu, const std::string& autor, const std::string& domeniu, int nivel);

    std::string getTitlu() const;
    std::string getDomeniu() const;
    int getNivelDificultate() const;
    std::string afisare() const;
};

#endif
