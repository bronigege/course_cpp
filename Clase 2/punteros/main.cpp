#include <iostream>

struct Box { // POD
    double largo;
    double ancho;
    double alto;
};


struct Element {
    Element* next{};

    void insertAfter(Element* newElement) {
        newElement->next = next;
        next = newElement;
    }

    char prefix[2];
    short operatinNumber;
};

struct Account {
    int money;
    void addMoney() {
        money++;
    }
};

struct AccountPrivate {
private:
    int money;
public:
    void addMoney() {
        money++;
    }
    /**
     * En C++, la palabra clave const después de una declaración de
     * función miembro de una clase significa que esa función no
     * puede modificar los miembros de datos de la clase. En otras
     * palabras, es una promesa de que la función es "de solo lectura"
     * con respecto al estado del objeto.
     *
     * Esto es útil porque permite a la función ser llamada en
     * objetos const, y proporciona una garantía a las personas que
     * usan la clase de que ciertas funciones no cambiarán el estado del objeto.
     * @return
     */
    [[nodiscard]] int getMoney() const {
        return money;
    }

    void setMoney(int money) {
        this->money = money;
    }

    /**
     * [[nodiscard]] es un atributo de C++ introducido en C++17 que se puede usar para
     * indicar que el valor de retorno de una función no debe ser descartado, es decir,
     * no debe ser ignorado.
     *
     * Esto es útil en casos en los que ignorar el resultado de una función es probablemente
     un error. Por ejemplo, funciones que devuelven un estado de error, o funciones que
     calculan y devuelven un valor pero no tienen efectos secundarios.

     Si una función marcada con [[nodiscard]] es llamada sin utilizar su valor de
     retorno, el compilador emitirá una advertencia.
     */

    /**
     * Un constructor son métodos especiales. Nunca establecen un tipo de retorno
     * y su nombre siempre coincide con el nombre de la clase de la que forman
     * parte. Se inicializan los objetos desde el momento en el que se inicia
     * la vida de un objeto.
     * Fuerzan las invariantes de clase.
     * Evitan problemas. Con la asignación de memoria o aplicación de valores
     * inadecuados. Podemos implementar múltiples constructors en una clase
     */

    AccountPrivate() {

    }
    AccountPrivate(int money) {
        this->money = money;
    }

    ~AccountPrivate() {
        std::cout << "Destruido" << std::endl;
    }

    // Los métodos destructor se llaman automáticamente antes de que el
    // objeto sea destruido. No toma argumentos, ni devuelve un tipo de objeto.
    // Se usa para liberar y limpiar. No se llaman explícitamente. El compilador se
    // encarga de llamarlos en el momento apropiado.
    // No es obligatorio definir ni el constructor ni el desctructor, aunque
    // siempre son llamados.

};


void print(int* elements) {
    // el array es tratado como un puntero aquí
    std::cout << sizeof(elements) << std::endl; // imprime el tamaño de un puntero, no el tamaño del array
    std::cout << &elements << std::endl;
}

int main() {
    /**
     * Los arrays y los punteros están relacionados.
     *
     * Los arrays se encuentran dentro de los denominados tipos derivados. También
     * es conocido como un tipo de referencia, junto a los punteros y referencias.
     */

    /**
     * Para el compilador esto es una variable int a la que
     * se le han asignado cinco valores contiguos diferentes.
     *
     * El compilador convierte impícitamente el array en un puntero
     * que apunta al primer elemento del array
     *
     * Siempre que se conozca la dirección de memoria del primer elemento
     * podra saber donde se encuentran el resto de los elementos del array
     */

    int array[5]{8, 2, 5, 6, 1};

    // Imprime el valor del puntero
    std::cout << array << std::endl;
    // Imprime la dirección del primer elmento del array
    std::cout << &array[0] << std::endl;

    // Imprime el valor del primer elemento del array
    std::cout << *array << std::endl;

    // Si creamos un puntero de forma explícita
    int* ptr{array};
    std::cout << *ptr << std::endl;
    // No se comportarán igual
    std::cout << sizeof(array) << std::endl; // Imprime sizeof(int) * array length 4bytes * 5
    std::cout << sizeof(ptr) << std::endl; // Imprime tamaño de un puntero

    // tipo int[5]
    std::cout << array << std::endl;
    // tipo int(*)[5]
    std::cout << &array << std::endl;

    // tipo int*
    std::cout << ptr << std::endl;
    // tipo int** devuelve la propia dirección de memoria de ptr, no del array
    std::cout << &ptr << std::endl;

    // No copia el array, ya que es una tarea costosa. Se le pasa un puntero a la función
    std::cout << &array << std::endl;
    print(array);

    /**
     * Uno de los papeles clave de los punteros es evitar tener que copiar grandes
     * cantidades de datos en distintas partes del código. En su lugar se pasa un
     * puntero que tiene la dirección en memoria donde se encuentran esos datos. Esto evita
     * el costo en recursos y rendimiento que supondría crear nuevas copias de datos ya existentes.
     *
     * * Operador de dirección (&). Antepuesto al nombre de un objeto, nos permite acceder a la dirección
     * enb memoria en la que se almacena.
     * * Operador asterisco (*):
     * 1. Declara Puntero "int* nombre_variable"
     * 2. Desreferencia Puntero "*nombre variable". Operador de desreferencia,
     * antepuesto al nombre del puntero, nos permite acceder al objeto almacenado en
     * la dirección en memoria.
     * * Operador flecha (->), operador miembro puntero:
     * 1. Desreferencia el puntero (como el operador *)
     * 2. Accede al miembro del Objeto apuntado que indiquemos
     */

    /**
     * Tipos de referencia. Son tipos que se encuentra dentro de los tipos derivados construidos
     * usando los tipos de datos primitivos. Los más importantes son los punteros y las referencias,
     * encargados de almacenar las direcciones en memoria de los objetos y principales
     * responsables de garantizar el rendimiento del programa.
     *
     * Los punteros son ojbetos de muy
     * bajo nivel que C y C++ utilizan para comunicarse con la memoria. Para hacerlo cada puntero
     * contiene dos piezas de información:
     * 1. Tipo de Objeto que se almacena
     * 2. Dirección en memoria asignada
     *
     */

    // Es lo mismo que si hubiésemos hecho int points = 0;
    int points{};

    // Lo que nos indica que es un puntero es el asterisco. Si no se
    // inicializan se conocen como punteros colgantes. Lo que es
    // muy peligroso. & es el operador de dirección. La variación constante
    // de la dirección de memoria se debe a la Address Space Layout Randomization
    // Es una característica de seguridad que evita poder acceder directamente
    // a direcciones base de regiones de memoria importantes que podrían
    // sufrir vulnerabilidades a través de exploits que permiten acceder a las
    // apis del sistema. El operador de dirección &, es por tanto un operador binario
    // que antepuesto al nombre de un objeto nos permite acceder a la dirección
    // en moemoria en la que se almacena. Los punteros solo pueden almacenar
    // direcciones en memoria pero nos permiten realizar todo tipo de operaciones
    // sobre el objeto que se almacene en esa dirección. El operador de desreferencia *
    // accede al objeto que se encuentra en la dirección almacenada en el puntero.
    // El otro operador clave al trabajar con punteros es el operador miembro puntero (->)
    // Operador flecha. Realiza dos operaciones:
    // 1. desreferencia el puntero (como el operador *)
    // 2. Accede al miembro del Objeto apuntado que indiquemos.
    int* pointsMemory{ &points };

    std::cout << "Valor: " << points << std::endl;
    std::cout << "Valor: " << pointsMemory << std::endl;
    *pointsMemory = 345;
    std::cout << "Valor: " << points << std::endl;
    std::cout << "Valor: " << pointsMemory << std::endl;

    Account account;
    // maneras de llamar al constructor
    AccountPrivate accountPrivate{};
    // Account account{};

    /*
     * Las referencias son otro tipo derivado fundamental. Lo podemos comparar con un alias.
     * No almacenan direcciones en memoria, sino un nombre alternativo para una variable existente
     *
     * Podemos declarar una variable como referencia usando el & pero no tiene nada que ver con el
     * Operador de dirección de los Punteros
     *
     * Comparten con los punteros que evitan la copia constante de grandes estructuras de datos.
     * Tienen limitaciones:
     * * No podemos tener referencias null
     * * Una vez que la referencia es inicializada no puede ser cambiada para referenciar a otro objeto
     * * Una referencia tiene que ser inicializada cuando es creada.
     *
     * Usaremos punteros siempre que tengamos que cambiar el valor de su tipo de referencia
     * o asignar un nullptr (puntero nulo)
     *
     * Usaremos referencias, cuando queremos garantizar una mayor sencillez de uso y evitar
     * posibles pérdidas de memoria
     */
    int x = 10;
    int& ref = x;
    std::cout << "Valor: " << x << std::endl;
    std::cout << "Valor: " << ref << std::endl;
    ref = 20;
    std::cout << "Valor: " << x << std::endl;
    std::cout << "Valor: " << ref << std::endl;

    account.money = 223;
    std::cout << "monedas: " << account.money;
    account.addMoney();
    std::cout << "monedas: " << account.money;

    Account* myAccount = &account;
    account.addMoney();
    std::cout << "monedas: " << account.money << std::endl;

    Box caja1;

    caja1.alto = 5.0;
    caja1.largo = 3.0;
    caja1.ancho = 4.0;

    /**
     * Ejemplo de listas enlazadas
     */
    Element element1;
    Element element2;
    Element element3;

    element1.prefix[0] = 'T';
    element1.prefix[1] = 'K';
    element1.operatinNumber = 421;
    element1.insertAfter(&element2);
    element2.prefix[0] = 'F';
    element2.prefix[1] = 'N';
    element2.operatinNumber = 213;
    element2.insertAfter(&element3);
    element3.prefix[0] = 'L';
    element3.prefix[1] = 'S';
    element3.operatinNumber = 1;


    for (Element* cursor = &element1; cursor; cursor = cursor->next) {
        std::cout << "Elemento " << cursor->prefix[0] << cursor->prefix[1] << " " << cursor->operatinNumber << std::endl;
    }

    return 0;
}
