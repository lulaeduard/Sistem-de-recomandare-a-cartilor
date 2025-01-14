#ifndef CERCETATOR_H
#define CERCETATOR_H

#include "Utilizator.h"

class Cercetator : public Utilizator {
public:
    Cercetator(const std::string& username, const std::string& parola);
    void afiseazaTipUtilizator() const;
};

#endif
