#include <iostream>

int main() {
    std::array<std::string_view, 4> colors{"amarillo", "naranja", "verde", "rojo"};

    std::cout << "Buscar por: ";
    std::string search{};
    std::cin >> search;

    /**
     * Las variables capturadas de una lambda son clones de la variable original. Comparten identificado y valor,
     * pero puede que no tipo (search).
     *
     * Las variables que aparecen en la cláusula de captura de una lambda se convierten en variables miembro
     * del objeto especial functior que crea la lambda
     *
     * La cláusula de captura el clon de la variable clonada es declarado como const por lo que la lambda no
     * puede modificarlo.
     */
    auto find{std::find_if(colors.begin(), colors.end(), [search](std::string_view str) {
        return (str.find(search) != std::string_view::npos);
    })};

    if (find == colors.end()) {
        std::cout << "No encontrado" << std::endl;
    } else {
        std::cout << "Encontrado " << *find << std::endl;
    }

    int disparos{10};

    auto disparar{
        // añadimos a la definición de la lambda "mutable" después de paréntesis
        // parámetro. Elimina el calificador "const" y permite a la lambda
        // modificar el valor de la variable clonada.

        // También podemos capturar una variable por referencia, no solo por valor.
        // No son constantes a menos que lo sea la variable origen.
        [&disparos]() /*mutable*/ {
            // Ahora ya podemos modificar balas (pero modificará el clon, no afectará al original
            --disparos;
            std::cout << "balas que quedan " << disparos << " disparos" << std::endl;
        }
    };

    disparar();

    std::cout << "balas que quedan " << disparos << " disparos" << std::endl;



    std::array areas{100, 25, 121, 40, 56};

    int ancho{2};
    int alto{3};

    // El signo = capturará por defecto ancho y alto por valor
    // Y si pusieramos un & lo haría por referencia
    auto find2{std::find_if(areas.begin(), areas.end(), [=](int a) {
        return (ancho * alto == a);
    })};

    if (find2 == areas.end()) {
        std::cout << "Area desconocida" << std::endl;
    } else {
        std::cout << "Area encontrada" << std::endl;
    }

    return 0;
}
