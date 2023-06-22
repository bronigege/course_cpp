//
// Created by Bruno Gómez García on 21/6/23.
//

#include "Funtor.h"


int Funtor::operator()(int c) {
    return (count += c);
}