//
// Created by Bruno Gómez García on 19/6/23.
//

#include "Person.h"


Person::Person(
        std::string name,
        TypePerson type,
        int force
        ) {
    this->name = name;
    this->type = type;
    this->force = force;
}

int Person::attack(int defense) {
    int resultAtack = attackForType() - defense;

    if (resultAtack < 0) {
        resultAtack = 0;
    }

    return resultAtack;
}

int Person::attackForType() {
    switch(type) {
        case TypePerson::NIGROMANTE:
            return 5;
        case TypePerson::GUERRERO:
            return 10;
        case TypePerson::MAGO:
            return 50;
        default:
            return 1;
    }
}

std::string Person::getName() {
    return std::string();
}

int Person::getForce() {
    return force;
}




