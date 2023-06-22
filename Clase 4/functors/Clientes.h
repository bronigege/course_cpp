//
// Created by Bruno Gómez García on 21/6/23.
//

#ifndef FUNCTORS_CLIENTES_H
#define FUNCTORS_CLIENTES_H


class Clientes {
private:
    int compras[10]{};
public:
    // LA sobrecarga del operator [] siempre debe tomar un parámetro
    // que indicará el subíndice al que se quiere acceder
    // Debe sobrecargarse como función miembro
    // Esta sobrecarga nos permite acceder directamente a
    // cualquier elemento del array
    int& operator[] (int index);
};


#endif //FUNCTORS_CLIENTES_H
