#include <iostream>

/*
 * SOBRECARGAR FUNCIONES
 *
 * Crear múltiples funciones con el mismo nombre siempre que cada una de esas funciones
 * tenga parámetros diferentes. Cada función que comparte un nombre dentro de un
 * mismo ámbito se denomina función sobrecargada.
 *
 * La sobrecarga es un buen medio para reducir la complejidad de nuestros programas,
 * al reducir la cantidad de nombres de funciones que debemos utilizar.
 *
 */

void print(int x) {
    std::cout << x << std::endl;
}

void print(double d) {
    std::cout << d << std::endl;
}

void print(float f) {
    std::cout << f << std::endl;
}

void print(long l) {
    std::cout << l << std::endl;
}

int main() {
    print(10);
    print(20.0);
    print(40.0f);
    print(50L);
    return 0;
}
