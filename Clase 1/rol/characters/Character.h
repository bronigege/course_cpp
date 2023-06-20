//
// Created by Bruno Gómez García on 19/6/23.
//

#ifndef ROL_CHARACTER_H // si no fue definido
// anteriormente se incluye
#define ROL_CHARACTER_H

#include <iostream>
#include "Character.h"
#include "TypeHeroes.h"

using namespace std;

namespace Heroes {
    class Character {
    private:
        std::string name;
        int live;
        bool dead;
        TypeHeroes type;

    public:
        Character(string name, int live);

        Character(string name, int live, TypeHeroes type);

        void takeLife(int attack);
        string getInfo();
        bool isDead();
    };
}


#endif //ROL_CHARACTER_H
