#include <iostream>
#include "Box.h"
#include "characters/Character.h"
#include "characters/CharacterEnemy.h"
#include "characters/TypeEnemies.h"
#include "characters/TypeHeroes.h"
#include "characters/TypePerson.h"
#include "persons/Character.h"


int main() {

    std::cout << "Juego de Rol" << std::endl;

    // Box box(30, 30);
    // box.getDimensions();

    Heroes::Character character(
            "Pedro",
            100,
            Heroes::TypeHeroes::GUERRERO
            );
    Enemies::CharacterEnemy characterEnemy(
            "Troll",
            50,
            5,
            Enemies::TypeEnemies::DRAGON
            );

    while(!character.isDead()) {
        character.takeLife(characterEnemy.attack());
        std::cout << character.getInfo() << std::endl;
    }

    persons::Character characterHeroe("Gato con botas", TypePerson::GUERRERO, 120);

    return 0;
}
