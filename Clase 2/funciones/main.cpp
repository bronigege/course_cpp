#include <iostream>
#include "Calculadora.h"

/**
 * SOBRECARGAR FUNCIONES
 *
 *
 */

/**
 * clase Point que permita sumar dos puntos y que no
 * devuelva nada y muestre un texto con el valor de x y de y
 * @tparam T
 * @param x
 */

template <typename T>
void print(T x) {
    std::cout << x << std::endl;
}

template <typename T, typename D>
auto add(T x, D y) {
    return x + y;
}

/*void print(int x) {
    std::cout << x << std::endl;
}

void print(double d) {
    std::cout << d << std::endl;
}

void print(long l) {
    std::cout << l << std::endl;
}*/

auto multiply(auto x, auto y) {
    return x * y;
}

/*class Point {
public:
    template<typename T, typename D>
    auto sumXY(T x, D y) {
        return x + y;
    }
};*/

/*template<typename T, typename D>
class Point {
public:
    auto sumXY(T x, D y) {
        return x + y;
    }
    void mostrarX(T x) {

    }
};*/

// C++20
class Point {
public:
    auto sumXY(auto x, auto y) {
        return x + y;
    }
    void mostrarX(auto x) {

    }
};

/**
 * template calculadora
 * y va a tener los métodos de sumar, restar, dividir y multiplicar y le añadís los tyname
 *
 */

int main() {
    print(1);
    print(2.0);
    print(2L);

    std::cout << add(2, 5) << " " << typeid(add(2, 5)).name() << std::endl;
    std::cout << multiply(2, 5) << " " << typeid(multiply(2, 5)).name() << std::endl;
    std::cout << add(2.0, 5) << " " << typeid(add(2.0, 5)).name() << std::endl;
    std::cout << multiply(2.0, 5) << " " << typeid(multiply(2.0, 5)).name() << std::endl;
    std::cout << add(2L, 5.f) << " " << typeid(add(2L, 5.f)).name() << std::endl;
    std::cout << multiply(2L, 5.f) << " " << typeid(multiply(2L, 5.f)).name() << std::endl;

    Point point;

    Calculadora calculadora;
    //std::cout << calculadora.sumar(2, 3) << std::endl;
    std::cout << calculadora.restar(2, 3) << std::endl;
    std::cout << calculadora.dividir(2, 3) << std::endl;
    std::cout << calculadora.multiplicar(2, 3) << std::endl;

    std::cout << point.sumXY(2, 3) << std::endl;

    return 0;
}
