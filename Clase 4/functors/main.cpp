#include <iostream>
#include "Account.h"
#include "AccountPrivate.h"
#include "Point.h"
#include "Clientes.h"
#include "Funtor.h"


int main() {
    /**
     * Modos de sobrecargar los operadores
     *
     */
    Account account1{7};
    Account account2{90};

    Account account3{account1 + account2};
    Account account4{10 + account1};
    Account account5{account1 + 20};

    std::cout << "Tengo " << account1.getTotal() << std::endl;
    std::cout << "Tengo " << account2.getTotal() << std::endl;
    std::cout << "Tengo " << account3.getTotal() << std::endl;
    std::cout << "Tengo " << account4.getTotal() << std::endl;
    std::cout << "Tengo " << account5.getTotal() << std::endl;

    Point point{7.9, 6.0, 8.2};
    Point point2{7.9, 6.0, 8.2};

    /*std::cout << "Punto {x: " <<
        point.getX() << ", y: " <<
        point.getY() << ", z: " <<
        point.getZ() << "}";*/


    //point.print();

    std::cout << point << ", " << point2 << std::endl;

    // std::cin >> point;

    std::cout << point << ", " << point2 << std::endl;

    AccountPrivate accountPrivate1{7};
    AccountPrivate accountPrivate2{accountPrivate1 + 2};
    AccountPrivate accountPrivate3{accountPrivate1 + accountPrivate2};

    std::cout << accountPrivate1.getTotal() << std::endl;
    std::cout << accountPrivate2.getTotal() << std::endl;
    std::cout << (-accountPrivate1).getTotal() << std::endl;

    if (accountPrivate1) {
        std::cout << "Hay dinero en el banco" << std::endl;
    } else {
        std::cout << "No hay dinero en el banco" << std::endl;
    }

    --accountPrivate1;
    --accountPrivate1;
    --accountPrivate1;
    ++accountPrivate1;
    /**
     * Los valores posfijo son menos eficientes que los prefijo
     * debido a dos cargas adicionales, una la de tener que
     * instanciar una variable temporal y otra la de tener
     * que devolver por valor en vez de por referencia.
     *
     */
    accountPrivate1--;
    std::cout << accountPrivate1.getTotal() << std::endl;

    /**
     * Reglas para determinar el tipo de función más adecuada para
     * sobrecargar operadores
     *
     * 1. Usar funciones miembro
     *  * Para sobrecargar los operadores
     *      - asignación(=)
     *      - subíndice([])
     *      - Llamada a función [()]
     *      - Selección puntero (->)
     *  * Para sobrecargar operadores unarios
     *  * Para sobrecargar operadores binarios
     *  que modifican el operando a la izquierda
     *  (como operator +=) y podemos modificar la
     *  definición del operando izquierdo.
     *
     * 2. Usar funciones normales o amigas.
     *  * Para sobrecargar operadores binarios que no modifican
     *  su operando izquierdo (como operator+)
     *  * Para sobrecargar operadores binarios que modifican su
     *  operando izquierdo, pero a los que no podemos agregar
     *  miembros a la definición de clase del operador izquierdo
     *  (como operator <<, cuyo operando izquierdo de tipo ostream
     *  obligatorio)
     */

    Clientes clientes{};
    clientes[0] = 4;

    std::cout << clientes[0] << std::endl;

    Point point1;

    point1(2, 1) = 3.5;
    std::cout << point1(2, 1) << std::endl;
    point1();
    std::cout << point1(2, 1) << std::endl;

    Funtor funtor{};
    std::cout << funtor(10) << std::endl;
    std::cout << funtor(110) << std::endl;

    return 0;
}
