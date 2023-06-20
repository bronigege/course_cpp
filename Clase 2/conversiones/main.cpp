#include <iostream>

/**
 * CONVERSIÓN DE TIPOS
 *
 * 1. Se puede hacer implícitamente. Llevada a cabo por el compilador.
 * También se denominan conversiones automáticas de tipos o coerción.
 * La mayoría de las conversiones son implícitas.
 *
 * 2. Se puede hace explícitamente. Llevada a cabo por el programador.
 */

// Valor de retorno diferente al tipo de retorno declarado en la función
float getDouble() {
    return 7; // valor int 7 implícitamente convertido a tipo float
}

void setLong(long l) {

}

void convert(int i) { }


auto add(int a, int b) -> int {
    return a + b;
}

// Esto se puede hacer desde C++11
auto add2(int a, int b) -> int {
    return a + b;
}

int main() {
    // Asignar o inicializar variable con tipo de dato diferente
    double decimal{5}; // Valor int implícitamente convertido a tipo double
    decimal = 7; // valor int 7 convertido a tipo double

    // Operadores binarios con operandos de diferentes tipos.
    double division{9.0 / 2}; // valor int 2 implícitamente converitdo a tipo double

    // Cuando se usa un valor no booleano como condición en un if
    if (4) { // valor int 4 implícitamente convertido a tipo bool
        // Si es diferente de cero el compilador lo convertirá
        // directamente en true
        std::cout << "Entré" << std::endl;
    }

    // Argumento pasado a función de tipo diferente al del parámetro
    // de la función
    setLong(60); // valor int 60 implícitamente convertido a tipo long

    // int x{4.6}; La inicialización entre llaves no permite conversiones con pérdida de datos
    // por tanto esta conversión dará error


    /*
     * 1. Conversiones numéricas seguras
     * int -> long
     * int -> double
     * ...
     *
     * 2. Conversiones numéricas con pérdida de datos
     * double -> int
     * int -> short
     * ...
     */
    int number1 = 7.2; // El .2 se elimina. Hay pérdida de datos
    int number2 = 6.0; // Se convierte a 6. Sin pérdida de datos

    // En ocasiones será necesario hacer una conversión de restricción (con pérdida de datos).
    // En ese caso debemos hacer explícita la conversión de restricción implícita con el
    // uso de static_cast
    double numberDecimal{16.0};
    convert(static_cast<int>(numberDecimal)); // No genera advertencia warning generated

    // No se debe convertir a tipos fuera de rango
    int i{4300};
    char c = i; // char tiene un rango de -128 a 127

    // Reducción en misma familia válidas
    int integer{2};
    short shortNumber = i; // Convierte int a short
    double dec{0.4134};
    float floatNumber = dec; // Convierte de double a float

    // Falta de precisión en floating
    float floatNumber2 = 0.123456789; // valor double que tiene 9 dígitos pero float solo admite 7

    // De entero a punto flotante si está en rango
    int integerNumber{10};
    float floatDecimal = integerNumber;

    // De punto flotante a entero, siempre que el valor que esté dentro del rango int. Se pierde la parte decimal
    int number3 = 3.6;

    /*
     * Operadores que requieren que los operandos sean del mismo tipo:
     *
     * 1. Operadores aritméticos binarios: +, -, *, /, %
     * 2. Operadores aritméticos binarios bit a bit: &, ^, |
     * 3. Operadores relacionales binarios <, >, <=, >=, ==, !=
     *
     * Reglas de prioridad de tipos:
     *
     * 1. El más bajo se convierte al más alto
     * 2. Si no están en la lista se usan las reglas de la promoción numérica
     *
     * Prioridad más alta
     *
     * 1. long double
     * 2. double
     * 3. float
     * 4. unsigned long long
     * 5. long long
     * 6. unsigned long
     * 7. long
     * 8. unsigned int
     * 9. int
     */
    std::cout << typeid(7 + 2.5).name() << " " << 7 + 25 << std::endl;

    short shortA{75};
    short shortB{12};
    std::cout << typeid(shortA + shortB).name() << " " << shortA + shortB << std::endl;

    // el operando unsigned int tiene mayor prioridad que int. Se produce un desbordamiento
    std::cout << typeid(5u - 10).name() << " " << 5u - 10 << std::endl; // evitar unsigned int



    /*
     * CONVERSIONES DE TIPO EXPLÍCITO
     *
     * Cinco tipos de Type Casting:
     *
     * 1. Casts estilo-C
     * 2. static casts
     * 3. const casts
     * 4. dynamic casts
     * 5. reinterpret casts
     */

    // 1. Casts estilo C (es aconsejable no utilizar este tipo de cast)
    // * Primera forma con (typo_a_convertir) variable
    int x{10};
    int y{30};
    double Point{(double) x / y};
    // * Segunda forma con typo_a_convertir(variable)
    double Point2{double(x) / y};

    // 2. static_cast. Se suele usar. Nos proporciona verificación de tipos
    // en tiempo de compilación. Es aconsejable usarlo para hacer la mayoría
    // de conversiones explícitas.
    char character = 'a';
    std::cout << character << " " << static_cast<int>(character) << std::endl;


    /**
     * DEDUCCION O INFERENCIA DE TIPOS
     *
     * Usando la palabra clave auto e deduce el tipo de un objeto a
     * partir de su inicializador. No funciona con objetos sin
     * inicializador o que sus inicializadores estén vacíos.
     *
     * Precauciones;
     *
     * 1. auto elimina la calificación const de los
     * tipos deducidos, la solución será añadir la palabra const
     * antes de auto
     * 2. La deducción de tipos con auto también elimina las
     * referencias
     * 3. El uso de auto con literales string devuelve un puntero de char
     *
     * Ventajas:
     *
     * 1. Alinea los nombres de las variables, haciéndolas más legibles
     * 2. auto evita el uso de variables sin inicializador
     * 3. auto evita conversiones de tipos no deseadas
     */

    auto impar{7.0};
    std::cout << typeid(impar).name() << std::endl;
    auto par{2 + 6};
    std::cout << typeid(par).name() << std::endl;
    auto z{i};
    std::cout << typeid(z).name() << std::endl;

    /**
     * Desde C++14 la deducción de tipos se aplica también al retorno de las funciones
     * Cuando se usa una función con tipo de retorno auto todos los return
     * tiene que ser del mismo tipo, de lo contrario dará error.
     *
     *  El uso de auto como tipo de retorno de las funciones hace que estas solo podrán
     *  ser llamadas desde el mismo archivo que están definidas. Eso limita su uso, el uso
     *  de auto no está generalizado en funciones, pero si lo está en objetos.
     *
     *  Desde C++ el tipo de retorno se puede añadir al final del prototiop de la función
     */
    std::cout << typeid(add2(2, 5)).name() << std::endl;


    return 0;
}
