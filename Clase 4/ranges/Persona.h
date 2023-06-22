//
// Created by Bruno Gómez García on 22/6/23.
//

#ifndef RANGES_PERSONA_H
#define RANGES_PERSONA_H
#include <iostream>

class Persona {
private:
    std::string nombre;
    std::string apellido;
    std::string dni;

public:
    Persona(std::string nombre, std::string apellido) {
        this->nombre = nombre;
        this->apellido = apellido;
    }

    Persona(std::string nombre, std::string apellido, std::string dni) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->dni = dni;
    }

    std::string getName() {
        return nombre;
    }

    std::string getApellido() {
        return apellido;
    }

    std::string getDni() {
        return apellido;
    }
};

#endif //RANGES_PERSONA_H
