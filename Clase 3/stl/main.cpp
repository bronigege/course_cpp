#include <iostream>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

int main() {
    /**
     * La STL forma parte de la especificación oficial de C++, de su ISO,
     * y se va ampliando con cada versión, que aparece cada 3 años.
     *
     * El core de C++ como cualquier cosa de C++ que podemos acceder
     * sin necesidad de incluir ningún encabezado.
     *
     * C++ es un lenguaje de bajo nivel, al que la biblioteca Standard
     * le proporciona un enorme conjunto de clases y algortmos de alto
     * nivel.
     *
     * C++ se ha ido construyendo sobre cinco pilares:
     *
     * 1. El lenguaje C
     * 2. El procesador de macros
     * 3. El modelo clase / objeto
     * 4. Programación genérica
     * 5. La biblioteca STL
     *
     * La STL suele dividirse entre:
     * 1. Iteradores
     * 2. Algoritmos
     * 3. Contenedores
     *
     * En la STL las clases contenedor son objetos que contienen una colección
     * de otros objetos que se suelen llamr elementos (Un array o un vector, ...)
     * Estas clases contenedor suelen clasificarse en:
     * 1. Secuenciales
     * 2. Asociativas
     * 3. Adaptativas
     *
     * Los contenedores contienen otros objetos así que un segundo
     * grupo de herramientas imprescindibles son las que nos
     * permiten movernos a través de los objetos. Son los iteradores.
     *
     * En definitiva la STL está formada por distintos tipos contenedores
     * que contienen un conjunto de elementos por los que nos podemos mover
     * con iteradores y llevan a cabo acciones sobre ellos con algortmos.
     */

    /**
     * ALGORITMOS
     *
     * Se dividen en:
     *
     * 1. Algoritmos inspectores: Se utilizan para ver, pero sin modificar
     * 2. Algoritmos mutadores: Se utilizan para modificar datos de un contenedor
     * 3. Algoritmos facilitadores: Se utilizan para genera resultados a partir de datos
     * de contenedores
     */


    /**
     * Arrays dinámicos
     *
     * Los arrays fijos decaen a punteros y no conocen su tamaño si se pasan a funciones
     * lo que limita su operabilidad.
     *
     * Los arrays dinámicos también presentan problemas tanto para ser desasignados,
     * tarea que depende del programador. Tampoco se conoce su tamaño y no pueden ser redimensionados.
     * El tamaño del array se asigna en tiempo de ejecución, pero después de asignarle un
     * tamaño no podemos cambiarlo
     *
     * Los corchetes le indican que debe usar la versión array de la asignación dinámica
     * de memoria. El tipo del tamaño debe ser convertible a std::size_t (el compilador
     * se encarga implícitamente de convertir el tipo en in en std::size_t)
     *
     * En su funcinamiento los arrays dinámicos se comportan muy similar a los fijos.
     * Un array dinámico tiene un puntero que apunta al primer elemento. La diferencia
     * reside en que la gestión del array dinámico depende del programador
     *
     * Desde C+11 se puede usar una lista de inicialización en los arrays asignados
     * dinámicamente
     *
     * Los términos fijo o dinámico lo usamos para referirnos a los arrays cuyo tamaño
     * tiene que conocerse en tiempo de compilación y los arrays a los que se asigna
     * memoria dinámicamente, cuyo tamaño debe conocerse en tiempo de ejecución.
     *
     * La única diferencia es que en la inicialización de los arrays asignados dinámicamente
     * no aparece el operador de asignación
     * int arrayFijo[5] = {9, 7, 5, 1} // inicializa un array fijo antes de C++
     * int arrayFijo[]{67, 2, 6}; el tamaño es opcional si tiene inicializadores
     */

    /**
     * CONTENEDORES
     *
     * Los CONTENEDORES SECUENCIALES mantienen el orden de los
     * elementos en el contenedor. std::vector, std::dque, std::array
     * std::list, std::forward_list, std::basic_string
     */

    std::cout << "Scribe un tamaño del array: ";
    int tamanho{6};
    // std::cin >> tamanho;
    //int* array{new int[tamanho] {9, 7, 43, 24, 76}};
    int * array{new int[tamanho]{}};
    array[0] = 5;
    delete[] array; // Se usa delete array para desasignar array. Devuelve el control de ese espacio en memoria al
    // Sistema operativo
    // No se necesita configurar array a nullptr, pero solo
    // porque sale de alcance inmediantamente después de usar delete

    /**
     * std::array
     * Se usa para solventar los problemas de los arrays fijos nativos. Sigue siendo un array
     * fijo pero que no decae a puntero cuando se pasa a una función, no olvida su tamaño
     *
     * std::array cuenta con la función at() que verifica los límites
     *
     * std::array se limpia automáticamente cuando sale de alcance
     */
     std::array<int, 3> array1; // Hasta C++17 no se podía omitir el tamaño de un std::array, incluso
     // aunque tenga una lista de inicialización.
     std::array array2{2, 4, 5, 6, 7}; // Desde C++ 17

     if (array2.at(29)) {
         std::cout << array2.size() << " ";
     } else {
         std::cout << array2.size() << " -----------";
     }

    std::cout << array2.size() << " "; // Popdemos obtener el tamaño y se puede saber aunque se pase a una función

    // los loops son
    for (int elemento: array2) {

    }


     /**
      * Desde C++20 es posible especificar solo uno de los dos, pero usando la función std::to_array
      */
     auto arrayNew1{std::to_array<int, 6>({9, 7, 5, 3, 1, 6})}; // Especifica tipo y tamaño
     auto arrayNew2{std::to_array<int>({9, 7, 5, 3, 1, 6})}; // Especifica tipo y deduce tamaño
     auto arrayNew3{std::to_array({9, 7, 5, 3, 1, 6})}; // Deduce tipo y tamaño



    /**
     * std::vector
     * Se usa para solventar los problemas de los arrays asignados dinámicamente
     */

    std::vector<int> vect;

    for (int i{0}; i < 6; ++i) {
        vect.push_back(10 - i);
    }

    for (int i{0}; i < vect.size(); ++i) {
        std::cout << vect[i] << " ";
    }

    std::cout << std::endl;

    /**
     * Es un array dinámico (como std::vector) que puede crecer
     * desde el principio o desde el final del contenedor
     */
    std::deque<int> deq;

    for (int i{0}; i < 3; ++i) {
        deq.push_back(i);
        deq.push_front(10 - i);
    }

    for (int i{0}; i < deq.size(); ++i) {
        std::cout << deq[i] << " ";
    }

    std::cout << std::endl;

    /**
     * std::list
     * Es un tipo de contenedor secuencial. Cada elemento del contenedor
     * contiene punteros a su elemento anterior y posterior. No cuenta
     * con un modo de acceso aleatorio. Si queremos acceder a un elmento
     * en el medio debemos comenzar en un extremo y recorrer la lista
     * hasta llegar al elemento deseado. La ventaja es que insertar
     * elementos en ellas es muy rápido.
     */

    std::list<int> l{7, 5, 16, 24};

    // Añade un integer al principio
    l.push_front(56);

    // Añade un elemneto al final
    l.push_back(13);

    // Inserta un integer después de 5
    auto insert = std::find(l.begin(), l.end(), 16);
    if (insert != l.end()) {
        l.insert(insert, 42);
    }

    for (int n: l) {
        std::cout << n << " ";
    }

    std::cout << std::endl;

    /**
     * CONTENEDORES ASOCIATIVOS, ordenan sus elementos automáticamente. De forma predeterminada
     * compara elementos usando el operador <
     * 1. std::set: ordena sus elementos de menor a mayor, no por orden de
     * inserción y no permite elementos repetidos.
     * 2. std:map: llamado por clave/valor. La clave es usada para indexar los datos y el
     * valor son los datos reales
     * 3. std::multiset: es similar a std::set, pero permite elementos repetidos
     * 4. std::multimap; similar a std::map pero permite elementos repetidos
     */

    /**
     * std::set
     */

    std::set<char> characters;

    characters.insert('G');
    characters.insert('A');
    characters.insert('B');
    characters.insert('C');
    characters.insert('A');
    characters.insert('G');
    characters.insert('B');

    for (auto& str: characters) {
        std::cout << str << " ";
    }

    std::cout << std::endl;

    /**
     * std::map
     */

    std::map<int, std::string> alumnos;
    alumnos.insert(std::pair<int, std::string>(001, "Alba"));
    alumnos.insert(std::pair<int, std::string>(002, "Juan"));
    alumnos.insert(std::pair<int, std::string>(003, "Pedro"));
    alumnos.insert(std::pair<int, std::string>(001, "Alba"));

    std::cout << "Tamaño " << alumnos.size() << std::endl;

    for (std::map<int, std::string>::iterator it = alumnos.begin(); it != alumnos.end(); ++it) {
        std::cout << (*it).first << ": " << (*it).second << std::endl;
    }

    std::cout << std::endl;

    /**
     * CONTENEDORES ADAPTATIVOS: son contenedores predefinidos para usos específicos. Combinables con otros
     * contenedores
     *
     * 1. std::stack: contenedores cuyos elementos operan en un contexto LIFO (Last Input, First Output).
     * Los elementos son insertados (push) de abajo a arriba y eliminados (pop) de arriba a abajo.
     * 2. std::queue: contenedores cuyos elementos operan en un contexto FIFO (First Input, First Output).
     * Los elementos son insertados (push) de arriba a abajo y elminados (pop) también de arriba a abajo.
     * 3. std::priority_queue: contenedor cuyos elementos se mantienen ordenados con el operador menor que <. El
     * push los ordena de mayor a menor, y el pop elimina el mayor de todos
     */

    /**
     * std::stack
     */

    std::stack<int> pila;
    pila.push(21);
    pila.push(13);
    pila.push(78);
    pila.push(90);

    while(!pila.empty()) {
        std::cout << pila.top() << std::endl;
        pila.pop();
    }

    std::cout << std::endl;

    /**
    * std::queue
    */

    std::queue<int> cola;
    cola.push(21);
    cola.push(13);
    cola.push(78);
    cola.push(90);

    while(!cola.empty()) {
        std::cout << cola.front() << std::endl;
        cola.pop();
    }

    std::cout << std::endl;

    /**
    * std::priority_queue
    */

    std::priority_queue<int> cola_priority;
    cola_priority.push(21);
    cola_priority.push(13);
    cola_priority.push(78);
    cola_priority.push(90);

    while(!cola_priority.empty()) {
        std::cout << cola_priority.top() << std::endl;
        cola_priority.pop();
    }

    std::cout << std::endl;

    /**
     * ITERADORES
     *
     * Es un objeto que puede atravesar una clase contenedor y acceder a toddos sus
     * elementos
     *
     * Es básicamente un puntero a un elemento del contenedor y un grupo de operadores
     * sobrecargados.
     *
     * Operadores sobrecargados:
     *
     * * Operator * : operador de indirección para acceder al contenido
     * * Operator ++ : Operador de incremento
     * * Operator -- : Operador de decremento
     * * Operator == : Operador de igualdad
     * * Operator != : Operador de desigualdad
     * * Operator = : Operador de asignacion. Indirecciona y accede.
     *
     * Funciones miembro básicas:
     *
     * * begin(): devuelve un iterado que apunta al primero de los elementos del contenedor
     * * end(): devuelve un puntero que apunta al elemento después del último de contenedor
     * * cbegin(): como begin(), pero el puntero que devuelve es const.
     * * cend(): como end() pero el puntero que devuelve es const.
     *
     * end() y cend() devuelven punteros que no apuntan a la dirección en memoria del último elemento
     * del contenedor, sino a la dirección en memoria inmediatamente posterior, lo que asegura siempre
     * haber recorrido todo el contenedor.
     *
     * Todos los contenedores proporcionan al menos dos tipos de iteradores:
     *
     * * container::iterator: proporciona un iterador de lectura/escritura
     * * container::const_iterator: proporciona un iterador de solo lectura
     */

    /**
     * Algoritmos: Son funciones que operan a través de los iteradores de modo estandarizado. Buscar
     * ordenar, copiar, insertar, reordenar, eliminar.
     *
     *
     */

    std::list<int> li(6);
    // poblamos

    return 0;
}
