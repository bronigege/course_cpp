#include <iostream>
#include <array>
#include <deque>
#include <list>
#include <set>
#include <forward_list>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include "Alumno.h"
#include "Comparador.h"

/**
 * Contenedores:
 *
 * 1. Secuenciales
 * 2. Asociativas
 * 3. Adaptativas
 *
 */

/*template<typename T, std::size_t S>
void sizeArray(std::array<T, S> array) {
    std::cout << array.size() << std::endl;
}

template<typename T>
void sizeArray(std::vector<T> array) {
    std::cout << array.size() << std::endl;
}*/


// Esto se puede hacer desde C++
//void sizeArray(auto array) {
//    std::cout << array.size() << std::endl;
//}

int main() {
   /* *//*std::cout << "Escribe un tamaño del array: ";
    int tamanho{};
    std::cin >> tamanho;
    int* array{new int[tamanho]{}};*//*

    *//**
     * CONTENEDORES SECUENCIALES: mantienen el orden de
     * los elementos en el contenedor:
     * 1. std::array
     * 2. std::vector
     * 3. std::deque
     * 4. std::list
     * 5. std::forward_list
     * 6. std::basic_string
     *//*

    *//**
     * std::array
     *
     * at() verificar los límites
     *
     *
     *//*

    // Hasta C++17
    std::array array1{2, 4, 6};

    std::cout << array1.size() << std::endl;

    sizeArray(array1);

    for (int elemento: array1) {

    }

    *//**
     * std::vector
     *//*

    std::vector<int> vect;

    for (int i{0}; i < 6; ++i) {
        vect.push_back(10 - i);
    }

    vect.pop_back();

    for (int i{0}; i < vect.size(); ++i) {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;

    std::cout << vect.size() << std::endl;

    sizeArray(vect);

    std::cout << std::endl;

    *//**
     * std::deque. Array dinámico que puede crecer
     * desde el principio o desde el final
     *//*
     std::deque<int> deq;

    for (int i{0}; i < 6; ++i) {
        deq.push_back(i);
        deq.push_front(10 - i);
    }

    for (int i{0}; i < deq.size(); ++i) {
        std::cout << deq[i] << " ";
    }

    std::cout << std::endl;

    std::cout << deq.size() << std::endl;

    sizeArray(deq);

    std::cout << std::endl;

    *//**
     * std:list
     *//*

    std::list<int> l{7, 5, 16, 166};

    l.push_front(698);
    l.push_back(25);

    auto insert = std::find(l.begin(), l.end(), 16);
    if (insert != l.end()) {
        insert++;
        l.insert(insert, 123);
    }

    for (int n: l) {
        std::cout << n << " ";
    }

    std::cout << std::endl;

    std::vector<std::string> nombresVect{"Juan", "Luis", "Ana", "Pedro"};
    nombresVect.clear();
    // std::cout << "Inserta un nuevo nombre";
    std::string name{"Carlos"};
    //std::cin >> name;
    nombresVect.push_back(name);

    for (int i{0}; i < nombresVect.size(); ++i) {
        std::cout << nombresVect[i] << " ";
    }
    std::cout << std::endl;

    std::deque<std::string> nombresDeq{"Juan", "Luis", "Ana", "Pedro"};
    nombresDeq.clear();
    nombresDeq.push_front(name);

    for (int i{0}; i < nombresDeq.size(); ++i) {
        std::cout << nombresDeq[i] << " ";
    }
    std::cout << std::endl;

    std::list<std::string> nombresList{"Juan", "Luis", "Ana", "Pedro"};
    // nombresList.clear();
    auto iterator = nombresList.begin();
    std::advance(iterator, 3);
    nombresList.insert(iterator, name);

    iterator = nombresList.begin();
    std::advance(iterator, 0);
    nombresList.erase(iterator);

    for (std::string& element: nombresList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;




    // std::vector, std::deque y std::list crearlos con typo std::string obtener el tamaño del
    // array. Insertar nuevos elementos y lo vais a insertar a través de std::cin;
    // en std::list buscáis un elemento dentro de la list y le vais a añadir uno antes y
    // uno después

    *//**
     * std::forward_list
     *//*

    std::forward_list<int> forwardList{5, 56, 43, 2};

    forwardList.push_front(0);

    auto it = forwardList.begin();
    std::advance(it, 0);
    forwardList.erase_after(it);

    for (int element: forwardList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    *//**
     * std::basic_string
     *//*

    std::basic_string<char> str = "Esto es un curso de C++";

    std::cout << "Longitud " << str.length() << " Posicion " << str[4] << std::endl;
    std::cout << " Substring " << str.substr(4, 3) << std::endl;

    str.replace(5, 5, "hola");

    std::cout << str  << std::endl;

    *//**
     * CONTENEDORES ASOCIATIVOS. Ordenan sus elementos automáticamente. Internamente
     * comparan los elementos usando el operodor <
     *
     * 1. std::set ordena sus elementos de menor a myor y no por orden de inserción, NO PERMITE ELEMENTOS REPETIDOS
     * 2. std::map: clave / valor. NO PERMITE ELEMENTOS REPETIDOS
     * 3. std::multiset PERMITE ELEMENTOS REPETIDOS
     * 4. std::multimap PERMITE ELEMENTOS REPETIDOS
     *
     *//*

    *//*
     * std::set
     *//*

    //std::set<int> characters;
    std::multiset<char> characters;
    characters.insert('G');
    characters.insert('A');
    characters.insert('Z');
    characters.insert('A');
    characters.insert('G');
    characters.insert('B');
    characters.insert('B');
    characters.insert('D');
    characters.insert('A');

    for (char element: characters) {
        std::cout << element << " ";
    }

    std::cout << std::endl;

    *//*
    * std::map
    *//*

    std::map<int, std::string> alumnos;
    alumnos.insert(std::pair<int, std::string>(1, "Alba"));
    alumnos.insert(std::pair<int, std::string>(2, "Juan"));
    alumnos.insert(std::pair<int, std::string>(3, "Luisa"));
    alumnos.insert(std::pair<int, std::string>(1, "Alba"));
    alumnos.insert(std::pair<int, std::string>(2, "Alba"));

    // Esto desde C++20 se puede sustituir por auto
    for(std::map<int, std::string>::iterator it = alumnos.begin(); it != alumnos.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    std::cout << std::endl;

    *//**
     * Crear un struct o class en otra archivo con dos campos un id y un nombre
     * vais a crear varias para set y para map y vais a recorre los contenedores
     *//*



    std::set<Alumno> alumnosSet{
        Alumno{1, "Juan"},
        Alumno{2, "Pedro"},
        Alumno{2, "Pedro"},
        Alumno{3, "Luisa"}
    };

    for (const Alumno& alumno: alumnosSet) {
        std::cout << alumno.name << " ";
    }

    std::cout << std::endl;*/

   /* std::map<int, Alumno> alumnosMap;

    Alumno alumno1{1, "Luisa"};

    alumnosMap.insert(std::pair<int, Alumno>(alumno1.getId(), alumno1));
    alumnosMap.insert(std::pair<int, Alumno>(2, Alumno(2, "Juan")));
    alumnosMap.insert(std::pair<int, Alumno>(3, Alumno(3, "Ana")));
    alumnosMap.insert(std::pair<int, Alumno>(4, Alumno(4, "Luis")));
    alumnosMap.insert(std::pair<int, Alumno>(1, Alumno(5, "Alberto")));

    for (auto& alumno: alumnosMap) {
        std::cout << alumno.first << " " << alumno.second.name << " ";
    }

    std::cout << std::endl;

    *//**
     * CONTENEDORES ADAPTATIVOS:
     *
     * 1. std::stack LIFO
     * 2. std::queue FIFO
     * 3. std::priority_queue
     *//*

    *//**
     * std::stck LIFO
     *//*

    std::stack<int> pila;
    pila.push(21);
    pila.push(13);
    pila.push(78);
    pila.push(453);
    pila.push(90);

    while(!pila.empty()) {
        std::cout << pila.top() << std::endl;
        pila.pop();
    }

    std::cout << std::endl;


    *//**
     * std::queue
     *//*

    std::queue<int> cola;

    cola.push(21);
    cola.push(13);
    cola.push(78);
    cola.push(453);
    cola.push(90);

    while(!cola.empty()) {
        std::cout << cola.front() << std::endl;
        cola.pop();
    }

    std::cout << std::endl;

    *//**
     * std::priority_queue
     *//*

    std::priority_queue<int, std::vector<int>, Comparador> cola_priority;

    cola_priority.push(21);
    cola_priority.push(13);
    cola_priority.push(78);
    cola_priority.push(453);
    cola_priority.push(90);

    while(!cola_priority.empty()) {
        std::cout << cola_priority.top() << std::endl;
        cola_priority.pop();
    }

    std::cout << std::endl;

    std::stack<std::string> stackString;
    stackString.push("Casa");
    stackString.push("Tela");
    stackString.push("Gato");
    stackString.push("Camilla");

    while(!stackString.empty()) {
        std::cout << stackString.top() << std::endl;
        stackString.pop();
    }

    std::cout << std::endl;

    std::queue<std::string> queueString;
    queueString.push("Casa");
    queueString.push("Tela");
    queueString.push("Gato");
    queueString.push("Camilla");

    while(!queueString.empty()) {
        std::cout << queueString.front() << std::endl;
        queueString.pop();
    }

    std::cout << std::endl;

    std::priority_queue<std::string, std::vector<std::string>, Comparador> queuePriorityString;
    queuePriorityString.push("Casa");
    queuePriorityString.push("Tela");
    queuePriorityString.push("Gato");
    queuePriorityString.push("Camilla");

    while(!queuePriorityString.empty()) {
        std::cout << queuePriorityString.top() << std::endl;
        queuePriorityString.pop();
    }

    std::cout << std::endl;

    *//**
     * Funciones miembro básicas:
     *
     * * begin(): devuelve un iterado que apunta al primero de los elementos del contenedor
     * * end(): devuelve un puntero que apunta a la posición de memoria justo después
     * del último  elemento
     *
     * Todos los contenedores tienen al menos de iteradores:
     * * container::iterator; proporciona un iterador de lectura / escritra
     * * container::const_iterator el iterador solo es de lectura
     *//*


    std::cout << "VECTOR MODIFICADO" << std::endl;

    std::vector<int> vect{2, 65, 5, 5, 8};
    std::vector<int>::const_iterator iterator;
    iterator = vect.begin();

    while (iterator != vect.end()) {
        //*iterator *= 2;
        std::cout << *iterator << std::endl;

        ++iterator;
    }



    std::cout << std::endl;

    *//*
     * Lo vais a probar en std::list, std::array, std::set, std::map
     *//*

    std::list<int> l{7, 5, 16, 166};
    std::list<int>::iterator iteratorl;
    iteratorl = l.begin();

    while (iteratorl != l.end()) {
        std::cout << *iteratorl << std::endl;

        ++iteratorl;
    }

    std::cout << std::endl;


    std::array array1{2, 4, 6};
    std::array<int, 3>::iterator iteratorA;
    iteratorA = array1.begin();

    while (iteratorA != array1.end()) {
        std::cout << *iteratorA << std::endl;

        ++iteratorA;
    }

    std::cout << std::endl;

    std::multiset<char> characters;
    characters.insert('G');
    characters.insert('A');
    characters.insert('Z');
    characters.insert('A');
    characters.insert('G');
    characters.insert('B');
    characters.insert('B');
    characters.insert('D');
    characters.insert('A');

    std::multiset<char>::iterator iteratorSet;
    iteratorSet = characters.begin();

    while (iteratorSet != characters.end()) {
        std::cout << *iteratorSet << std::endl;

        ++iteratorSet;
    }

    std::map<int, std::string> alumnos;
    alumnos.insert(std::pair<int, std::string>(1, "Alba"));
    alumnos.insert(std::pair<int, std::string>(2, "Juan"));
    alumnos.insert(std::pair<int, std::string>(3, "Luisa"));
    alumnos.insert(std::pair<int, std::string>(1, "Alba"));
    alumnos.insert(std::pair<int, std::string>(2, "Alba"));*/

     /**
      * Contenedores:
      * 1. Secuenciales
      * 2. Asociativos
      * 3. Adaptativos
      *
      * Iteradores:
      * 1. iterator -> lectura/escritura
      * 2. const_iterator -> lectura
      *
      * Algoritmos
      *
      * distintos tipos de contendores, esos contenedores tiene un conjunto de elementos
      * y nos vamos poder mover entre ellos con los iteradores, vamos a poder hacer acciones
      * sobre -> algoritmos
      */

     /**
      * std::sort
      */

     std::vector<int> vector{5, 4, 5, 7};
     std::sort(vector.begin(), vector.end());

     for (const int num: vector) {
         std::cout << num << " ";
     }

    std::cout << std::endl;

     /**
      * std::find
      */

     std::vector<int>::iterator iterator = std::find(vector.begin(), vector.end(), 4);

     if (iterator != vector.end()) {
         std::cout << "Elemento encontrado " << *iterator << std::endl;
     }

     /**
      * std::accumulate
      */
      int suma = std::accumulate(vector.begin(), vector.end(), 0);
      std::cout << "Suma " << suma << std::endl;

      /**
       * std::count
       */
       int total = std::count(vector.begin(), vector.end(), 5);
    std::cout << "El 5 aparece " << total << " veces " << std::endl;

    /**
     * std::transform
     */
     std::vector<int> vectorCuadrado(2);

     /*std::transform(vector.begin(), vector.end(), vectorCuadrado.begin(), [](int n) {
         return n * n;
     });

     for (int num: vectorCuadrado) {
         std::cout << num << " ";
     }

     std::cout << std::endl;*/

     /**
      * std::copy
      */

    /*std::copy(vector.begin() + 1, vector.end() - 1, vectorCuadrado.begin());

    for (int num: vectorCuadrado) {
        std::cout << num << " ";
    }

    std::cout << std::endl;*/

    /**
     * std::reverse
     */
     std::reverse(vector.begin(), vector.end());

    for (int num: vector) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    /**
     * std::max_element
     * std::min_element
     */

    // max_element
    std::vector<int>::iterator elementoGrande = std::min_element(vector.begin(), vector.end());

    std::cout << "Elemento más grande " << *elementoGrande;
    std::cout << std::endl;

    /**
     * std::for_each
     */

    std::for_each(vector.begin(), vector.end(), [](int n) {
        std::cout << n << std::endl;
    });

    return 0;
}
