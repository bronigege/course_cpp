//
// Created by Bruno Gómez García on 19/6/23.
//

#ifndef ROL_CHARACTERENEMY_H
#define ROL_CHARACTERENEMY_H

// Clase enemigo dentro de un nuevo namespace
// atributos nombre, vida, nivel de fuerza
// método llamado que va a tener a
// tener en cuenta el nivel de fueza

#include <iostream>
#include "TypeEnemies.h"

namespace Enemies {
    class CharacterEnemy {
    private:
        std::string name;
        int live;
        int force;
        TypeEnemies type;
    public:
        CharacterEnemy(
                std::string name,
                int live,
                int force
                );
        CharacterEnemy(
                std::string name,
                int live,
                int force,
                TypeEnemies type
        );
        int attack();
        int attackForType();
    };
}


#endif //ROL_CHARACTERENEMY_H
