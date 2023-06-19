//
// Created by Bruno Gómez García on 19/6/23.
//

#ifndef ROL_CHARACTER_PERSONS_H
#define ROL_CHARACTER_PERSONS_H

#include "../characters/Person.h"
#include <iostream>
#include "../characters/TypePerson.h"


namespace persons {
    class Character: public Person  {
    public:
        Character(
                std::string name,
                TypePerson type,
                int force);
        std::string getInfo();
    };
}



#endif //ROL_CHARACTER_PERSONS_H
