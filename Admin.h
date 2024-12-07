#ifndef ADMIN_H
#define ADMIN_H

#include "Utilizator.h"

class Admin : public Utilizator {
public:
    Admin(const std::string& username, const std::string& parola);
};

#endif
