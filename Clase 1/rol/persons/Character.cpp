//
// Created by Bruno Gómez García on 19/6/23.
//

#include "Character.h"

persons::Character::Character(
        std::string name,
        TypePerson type,
        int force
        ):
Person(name, type, force) {

}

std::string persons::Character::getInfo() {
    return getName() + " tiene " + std::to_string(getForce());
}
