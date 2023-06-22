#include <iostream>
#include <thread>

void contador(int id, int numeroIteraciones) {
    for (int i{0}; i < numeroIteraciones; i++) {
        std::cout << "Contador " << id << " tiene un valor " << i << std::endl;
    }
}

void decirHola(int numeroIteraciones) {
    for (int i{0}; i < numeroIteraciones; i++) {
        std::cout << "Hola " << std::endl;
    }
}

int main() {
    /**
     * Permite dividir una tarea en varis subprocesos paralelos. Cada subproceso
     * puede ejecutar:
     *
     * * Función global
     * * Función local
     * * Expesión lambda
     * * Función miembro
     */

    std::jthread hilo1{contador, 1, 20};
    std::thread hilo2{contador, 2, 20};
    std::thread hilo3{decirHola, 20};

    /**
     * Le dice a la aplicación que no termine antes que estos dos hilo
     */
    hilo1.join();
    hilo2.join();
    hilo3.join();

    return 0;
}
