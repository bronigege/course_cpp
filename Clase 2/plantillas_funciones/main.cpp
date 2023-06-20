#include <iostream>

/**
 * PLANTILLAS DE FUNCIONES
 *
 * No son realmente funciones. Proveen al compilador con la
 * información que necesita para crearlas.
 */

template <typename /* se puede usar class, pero mejor no usarla */ T>
T greaterThan(T x, T y) {
    return (x > y) ? x : y;
}

// Para que permita dos tipos diferentes hacemos lo siguiente
template<typename T, typename D>
// Podemos usar auto
auto add(T x, D y) {
    return (x > y) ? x : y;
}

/**
 * Desde C++20 se introducen las plantillas de funciones abreviadas.
 * Ejemplo:
 * Cada auto será un marcador diferente
 */
auto multiply(auto x, auto y) {
    return x + y;
}

int main() {
    std::cout << greaterThan<int>(2, 5) << std::endl; // instancia mayor <int>
    std::cout << greaterThan<>(7, 2) << std::endl; // deduce mayor <int>(int, int)
    std::cout << greaterThan(51.2f, 5.2f) << std::endl; // deduce mayor float(float, float)

    std::cout << add<int, int>(2, 5) << std::endl;
    std::cout << add<float, int>(2.0, 5) << std::endl;
    std::cout << add(2.0, 5) << std::endl;

    std::cout << multiply(2.0, 5) << std::endl;
    std::cout << multiply(4, 5L) << std::endl;
    std::cout << multiply(20, 5123242412) << std::endl;

    return 0;
}
