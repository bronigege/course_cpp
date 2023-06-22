#include <iostream>
#include <vector>
#include <ranges>
#include <list>
#include "Persona.h"

void printRange(std::string message, auto& rango) {
    std::cout << message;
    for (auto valor: rango) {
        std::cout << valor << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vector = {1, 3, 67, 2, 9, 102};
    std::vector<int>::iterator iterator;

    // Clásica
    for(iterator = vector.begin(); iterator != vector.end(); ++iterator) {
        std::cout << *iterator << " ";
    }

    std::cout << std::endl;

    // Versión C++11
    /**
     * Solo puede utilizarse en ocntendores que cuenten con los metodos
     * begin() y end()
     */
    for (int item: vector) {
        std::cout << item << " ";
    }

    // Versión C++20
    /**
     * RANGOS
     *
     * * Encapsulan los métodos begin() y end(), ya no aparecen
     * explícitamente.
     *
     * cinco componentes:
     * * Rangos: deben conocer previamente los requisitos del contenedor
     * * Algoritmos basados en rangos: Acceden y transforman los elementos del contendor
     * * Proyecciones: Permiten imágenes a partir de callbacks personalizados
     * * Vistas: Muestran los cambios en rangos sin hacer copias ni modificar el original
     * * Fábricas de rangos: Genera secuencias de valroes a petición
     */

    std::cout << std::endl;

    for (auto i = std::ranges::rbegin(vector); i != std::ranges::rend(vector); i++) {
        std::cout << *i << " ";
    }


    std::cout << std::endl;

    if (std::ranges::empty(vector)) {
        std::cout << "Está vacío.";
    } else {
        std::cout << "Tiene elementos";
    }

    std::cout << std::endl;
    // Devuelve puntero al vector
    /**
     * Toma todo el contenedor y devuelve un puntero al primero de sus elementos
     */
    int* data = std::ranges::data(vector);
    int size = vector.size();

    for (int i{0}; i < size; i++) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;

    /**
     * std::span permite acceder a un rango de un contenedor,
     * pasándole el puntero al primero elemento y un tamaño
     */
    std::span<int> sliceVector(vector.data(), 3);
    int* dataSlice = std::ranges::data(sliceVector);
    int sizeSlice = sliceVector.size();

    for (int i{0}; i < sizeSlice; i++) {
        std::cout << dataSlice[i] << " ";
    }

    std::cout << std::endl;

    /**
     * Algoritmos
     */

    /*std::sort(std::begin(vector), std::end(vector));*/
    std::ranges::sort(vector);

    for(int element: vector) {
        std::cout << element << " ";
    }

    std::cout << std::endl;

    /*std::list l{33, 12, 456, 213, 21};
    std::ranges::sort(l);*/

    // auto position = std::find(vector.begin(), vector.end(), 67);
    auto position = std::ranges::find(vector, 67);

    if (position != vector.end()) {
        std::cout << *position;
    }

    std::cout << std::endl;


    /**
     * Proyecciones: permiten ordenar los elementos de distintos contenedores
     */

    std::vector personas{
        Persona{"Juan", "Gómez", "32131231G"},
        Persona{"Alberto", "García", "23121421A"},
        Persona{"Luisa", "Pérez", "121235233C"},
    };


    // std::sort(std::begin(personas), std::endl(personas));
    /*std::ranges::sort(personas, std::greater<>{}, [](Persona persona) {
        return persona.getDni();
    });*/

    std::ranges::sort(personas, std::greater<>{}, &Persona::getDni );


    for(auto person: personas) {
        std::cout << person.getName() << std::endl;
    }

    std::cout << std::endl;

    /**
     * VISTAS DE RANGO
     * 1. No se evaluan al crearse, sino cuando sea llamado el adaptador de rango
     * 2. Las vistas nunca son propietarias. Los elementos siempre pertenece al
     * rango subyacente, o a uno nuevo que se cree nunca a la vista
     * 3. Las vistas nunca modifican la estructra de los rangos origianeles
     */

    std::vector<int> numeros = {1, 4, 110, 3, 67, 2, 9, 102, 82};
//    printRange("Original ", vector);
//
//    // filtrado de todos los valores impares, y solos vamos a dejar los pares
//    auto pares{numeros | std::views::filter([](int n) {
//        return n % 2 == 0;
//    })};
//    printRange("Solo valores pares ", pares);
//
//    // Transformar todos los valores a su valor doble
//    auto paresDobles{pares | std::views::transform([](int n) {
//        return n * 2;
//    })};
//
//    printRange("Pares dobles ", paresDobles);
//
//    // Eliminar los dos primeros elementos
//    auto paresEliminados{paresDobles | std::views::drop(2)};
//    printRange("Pares eliminados ", paresEliminados);
//
//    // Invertir la vista
//    auto inversion{paresEliminados | std::views::reverse};
//    printRange("Invertido ", inversion);

    auto result{ numeros
        | std::views::filter([](const int& n) {return n % 2 == 0;})
        | std::views::transform([](const int& n) { return n * 2; })
        | std::views::drop(2)
        | std::views::reverse
    };

    // VECTOR DE NÚMEROS. FILTRO QUE OS GUARDE LOS MAYORES DE 50
    // ELIMINA 2
    // TRANSFORME TODOS LOS ELEMENTOS MULTIPLICÁNDOLES POR 10

    // Vamos a tener una clase Vehiculo con atributos matrícula
    // marca, modelo, itv (false). Crear un vector o array en el que guardéis
    // 5 elementos, los ordenéis por matrícula y otro filter que ponga
    // que pasaron la itv(true)

    printRange("Resultado final ", result);

    return 0;
}
