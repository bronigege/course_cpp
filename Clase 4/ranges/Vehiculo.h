//
// Created by Bruno Gómez García on 22/6/23.
//

#ifndef RANGES_VEHICULO_H
#define RANGES_VEHICULO_H

#include <iostream>

/*
 * // Vamos a tener una clase Vehiculo con atributos matrícula
    // marca, modelo, itv (false). Crear un vector o array en el que guardéis
    // 5 elementos, los ordenéis por matrícula y otro filter que ponga
    // que pasaron la itv(true)
 */

class Vehiculo {
private:
    std::string matricula;
    std::string marca;
    std::string modelo;
    bool itv;
public:
    Vehiculo(std::string matricula, std::string marca, std::string modelo, bool itv) {
        this->matricula = matricula;
        this->marca = marca;
        this->modelo = modelo;
        this->itv = itv;
    }

    const std::string &getMatricula() const {
        return matricula;
    }

    const std::string &getMarca() const {
        return marca;
    }

    const std::string &getModelo() const {
        return modelo;
    }

    bool isItv() const {
        return itv;
    }
};

#endif //RANGES_VEHICULO_H
