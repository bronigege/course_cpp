//
// Created by Bruno Gómez García on 19/6/23.
//

#ifndef ROL_PERSON_H
#define ROL_PERSON_H

#include "TypePerson.h"
#include <iostream>

// Vamos clase general attack, metodo defense,
// y va a tener de atributos un nombre y un type

class Person {

private:
    std::string name;
    TypePerson type;
    int force;

public:
    Person(
            std::string name,
            TypePerson type,
            int force);

    int attack(int defense);
    int attackForType();

    std::string getName();
    int getForce();
};

#endif //ROL_PERSON_H
