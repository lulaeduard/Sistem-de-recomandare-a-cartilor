#ifndef RECOMANDARE_H
#define RECOMANDARE_H

#include <string>
#include "BazaDeDate.h"

class Recomandare {
private:
    BazaDeDate bazaDeDate;

public:
    Recomandare();
    void init();
    void meniuPrincipal();
    void login();
    void inregistrare();
    void intreabaUtilizator();
};

#endif
