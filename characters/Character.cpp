//
// Created by Bruno Gómez García on 19/6/23.
//

#include "Character.h"



Heroes::Character::Character(
        std::string name,
        int live
        ) {
    this->name = name;
    this->live = live;
    dead = false;
}

Heroes::Character::Character(
        std::string name,
        int live,
        Heroes::TypeHeroes type
        ) {
    this->name = name;
    this->live = live;
    this->type = type;
    dead = false;
}

void Heroes::Character::takeLife(int attack) {
    if (live > 0) {
        live -= attack;
    }

    if (live <= 0) {
        dead = true;
    }
}

string Heroes::Character::getInfo() {
    return name + " tiene " + std::to_string(live);
}

bool Heroes::Character::isDead() {
    return dead;
}
