#include "Student.h"
#include <iostream>

Student::Student(const std::string& username, const std::string& parola)
    : Utilizator(username, parola) {
}

void Student::afiseazaTipUtilizator() const {
    std::cout << "Tip utilizator: Student\n";
}
