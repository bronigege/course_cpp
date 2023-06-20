#include <iostream>

/**
 * ARGUMENTOS PREDETERMINADOS
 *
 * Las funciones con argumentos predeterminados
 * pueden estar sobrecargadas
 */

// Si hay un archivo de cabecera es en el donde se
// incluye el argumento predeterminaod
void print(int x, int y = 6) {
    std::cout << "Point: {x: " << x << ", y: " << y << "}" << std::endl;
}

int main() {
    print(2);
    print(10, 24);

    return 0;
}
