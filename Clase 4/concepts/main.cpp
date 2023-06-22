#include <iostream>
#include <concepts>

/**
 * CONCEPTS
 *
 * Agregan múltiples restricciones incluyendo requires y otros conceptos
 * predefinidos
 *
 * DESDE C++20
 */
template<typename T>
concept Numerico = (std::integral<T> && !std::is_same_v<T, int>) ||
        std::floating_point<T>;

template<typename T, typename U>
concept Iguales = std::same_as<T, U>;


template<typename T>
T multiplicar(T numero1, T numero2) requires Numerico<T> {
    return numero1 * numero2;
}

template<typename T, typename U>
int suma(T a, U b) requires Iguales<T, U> {
    return a + b;
}

int main() {
    /*std::cout << multiplicar(2, 4) << std::endl;
    std::cout << multiplicar(2.0, 4.0) << std::endl;
    std::cout << multiplicar(2.0, 4.0) << std::endl;
    std::cout << multiplicar(2L, 4L) << std::endl;
    std::cout << multiplicar("ab", "abc") << std::endl;*/

    std::cout << suma(2.0, 3.0) << std::endl;
    return 0;
}
