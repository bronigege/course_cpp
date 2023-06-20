#include <iostream>

/**
 * ARRAYS
 *
 * Los arrays agregan datos individuales relacionados.
 *
 * Cada una de las variables de un arrary se llama elemento.
 *
 * Los arrays fijos tiene la memoria asignada en tiempo de compilación.
 * Esto genera una serie de limitaicones:
 *
 * 1. No puede modificarse por el usaurio o on cambios de ejecucción
 * 2. Obliga a recopilar para modificar el tamaño
 */

enum Students {
    JUAN,
    PEDRO,
    ANA,
    ROBERTO,
    SANTIAGO,
    SIZE
};

/**
 * Con const impedimos que dentro del array se puedan modificar sus valores
 */
void listPrimos(const int primos[5], int length) {
    // Si intentamos usar std::size o sizeof con un array llamado en una función
    // tendremos un error
    for (int i = 0; i < length; i++) {
        std::cout << primos[i] << " ";
    }
}

int main() {
    int primos[5]{};

    primos[0] = 2;
    primos[1] = 3;
    primos[2] = 5;
    primos[3] = 7;
    primos[4] = 11;

    // Desde la versión C++17 se agregó std::size(). Siempre devuelve
    // el tamaño como valor unsigned. Si necesitamos que sea signed tenemos
    // std::ssize(array) incorporada en C++20, devuelve el tamaño como valor signed.
    // Ejemplo
    // int length = sizeof(primos) / sizeof(primos[0])

    int length = std::size(primos);

    listPrimos(primos, length);

    int total =  primos[0] +  primos[1] +  primos[3] +  primos[4];

    std::cout << "El número primo más bajo es: " << primos[0] << std::endl;
    std::cout << "La suma de los cinco primeros primos es: " << total << std::endl;

    // Otra manera de inicializar arrays
    int notes[5]{6, 9, 2, 25, 6};

    length = sizeof(notes) / sizeof(notes[0]);

    for (int i = 0; i < length; i++) {
        std::cout << notes[i] << " " << std::endl;
    }

    int studentes[SIZE]{};

    int x{2};
    int y{4};

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    // INTERCAMBIA EL VALOR ENTRE DOS VARIABLES
    std::swap(x, y);

    std::cout << x << std::endl;
    std::cout << y << std::endl;



    // ORDENACIÓN
    int array[]{5, 90, 30, 40, 20, 10, 2};

    /**
     * Con constexpr el compilador calcula el tamaño del array en
     * tiempo de compilaicón. Esto es útil por los siguientes motivos:
     *
     * 1. Optimización: al permitir que ciertos cálculos se realicen en
     * tiempo de compilación se mejora el rendimiento del progrmaa.
     * 2. Seguridad en los tipos: ayuda a que los valores utilizados sean
     * del tipo esperado.
     */
    constexpr int longitud{static_cast<int>(std::size(array))};

    // Recorre cada elemento del array excepto el último porque ya estará ordenado
    // al llegar a esa posición
    for (int i{0}; i < longitud - 1; ++i) {
        // este es el índice del elemento más pequeño que encontramos en esta iteración
        int currentI{i};

        // Buscamos un elemento más pequeño en el resto del array
        for (int j{currentI + 1}; j < longitud; ++j) {

            if (array[j] < array[currentI]) {
                currentI = j;
            }
        }

        // Realizamos el intercambio
        std::swap(array[i], array[currentI]);

    }

    for (int i{0}; i < longitud; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    // Tenemos una alternativa con std::sort
    std::sort(std::begin(array), std::end(array));

    for (int i{0}; i < longitud; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
