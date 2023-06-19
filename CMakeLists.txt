cmake_minimum_required(VERSION 3.25)
project(rol)

set(CMAKE_CXX_STANDARD 17)

add_executable(rol main.cpp Box.cpp Box.h characters/Character.cpp characters/Character.h characters/CharacterEnemy.cpp characters/CharacterEnemy.h characters/TypeHeroes.h characters/TypeEnemies.h characters/Person.cpp characters/Person.h characters/TypePerson.h persons/Character.cpp persons/Character.h)
