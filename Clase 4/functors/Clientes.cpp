//
// Created by Bruno Gómez García on 21/6/23.
//

#include "Clientes.h"


int &Clientes::operator[](int index) {
    return compras[index];
}