//
// Created by Bruno Gómez García on 21/6/23.
//

#ifndef UNTITLED_ALUMNO_H
#define UNTITLED_ALUMNO_H

#include <iostream>

struct Alumno {
private:
        int id;

public:
    std::string name;

    Alumno(int id, std::string name) {
        this->id = id;
        this->name = name;
    }

    bool operator<(const Alumno& other) const {
        return id < other.getId();
    }

    int getId() const {
        return id;
    }
};

#endif //UNTITLED_ALUMNO_H
