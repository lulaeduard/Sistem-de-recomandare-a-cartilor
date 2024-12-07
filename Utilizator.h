#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>

class Utilizator {
protected:
    std::string username;
    std::string parola;

public:
    Utilizator(const std::string& username, const std::string& parola);
    virtual ~Utilizator() = default;

    std::string getUsername() const;
    bool verificaParola(const std::string& parola) const;
};

#endif
