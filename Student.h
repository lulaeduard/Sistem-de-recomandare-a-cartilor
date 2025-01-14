#ifndef STUDENT_H
#define STUDENT_H

#include "Utilizator.h"

class Student : public Utilizator {
public:
    Student(const std::string& username, const std::string& parola);
    void afiseazaTipUtilizator() const;
};

#endif
