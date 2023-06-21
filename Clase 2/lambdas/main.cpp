#include <iostream>

/**
 * Expresiones lambda
 *
 * Nos permiten definir funciones anónimos y anidables
 */

/*int factorial(int n) {
    int result = 1;

    for (int i = 1; i < n; ++i) {
        result *= i;
    }

    return result;
}*/

/*int parImpar(int n) {
    return (n % 2 == 0);
}*/

int main() {
    /**
     * [clausalaCaptura](parametros) -> type {
     *  operaciones;
     * }
     */


    auto factorial = [](int n) {
        int result = 1;

        for (int i = 1; i < n; ++i) {
            result *= i;
        }

        return result;
    };

    /*auto parImpar = [](int n) {
        return (n % 2 == 0);
    };*/

    int numero = 2;

    auto sumanumeros = [&numero](int n) {
        return numero + n;
    };

    std::cout << factorial(6) << std::endl;
    std::cout << [](int n) {return (n % 2 == 0);} << std::endl;
    std::cout << sumanumeros(2) << std::endl;

    std::vector <int> numbers{4, 5, 6, 7, 8};

    std::vector<int> pares;


    auto lambda = [](int n) { return (n % 2 == 0);};

    std::copy_if(
            numbers.begin(),
            numbers.end(),
            std::back_inserter(pares),
        lambda
            );


    for (int number: pares) {
        std::cout << number << " ";
    }

    std::cout << std::endl;


    /**
     * Las lambdas son un tipo de objeto que se denomina
     * Functors. Los Functores son objetos que contienen
     * un operador sobrecargado
     */

    // Un puntero de función regular. Solo funciona si la clausula de captura
    // está vacía

    double (*addNumbers)(double, double) {
            [](double a, double b) {
                return (a + b);
            }
    };

    double a1 = addNumbers(1, 2);

    // Usando std::function, la lambda podría tener una cláusula de captura no vacía
    std::function addNumbers2 {
            [](double a, double b) {
                return (a + b);
            }
    };

    double a2 = addNumbers2(3, 4);

    // Usando auto. Almacena lambda con su tipo real.
    auto addNumbers3 {
            [](double a, double b) {
                return (a + b);
            }
    };

    auto a3 = addNumbers3(5, 6);
    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;
    std::cout << a3 << std::endl;


    return 0;
}
