//
// Created by Bruno Gómez García on 19/6/23.
//

#include "CharacterEnemy.h"


Enemies::CharacterEnemy::CharacterEnemy(
        std::string name,
        int live,
        int force) {
    this->name = name;
    this->live = live;
    this->force = force;
};

Enemies::CharacterEnemy::CharacterEnemy(
        std::string name,
        int live,
        int force,
        TypeEnemies type
        ) {
    this->name = name;
    this->live = live;
    this->force = force;
    this->type = type;
};

int Enemies::CharacterEnemy::attack() {
    std::cout << name << " ataca con " << std::to_string(attackForType());
    std::cout << std::endl;

    return attackForType();
}

int Enemies::CharacterEnemy::attackForType() {
    switch(type) {
        case TypeEnemies::TROLL:
            return 5;
        case TypeEnemies::GUERRERO:
            return 10;
        case TypeEnemies::DRAGON:
            return 50;
        default:
            return 1;
    }
}