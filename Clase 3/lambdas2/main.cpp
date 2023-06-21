#include <iostream>

int main() {
    std::vector<std::string> words = {"hola", "adios", "qué", "tal"};

    auto print_element = [](const std::string& elem) {
        std::cout << elem << std::endl;
    };

    std::for_each(words.begin(), words.end(), print_element);

    std::vector<int> numbers = {100, 20, 13, 4, 52};

    // Le indicamos con una lambda como queremos ordenar, descendente o ascendente
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });

    std::for_each(numbers.begin(), numbers.end(), [](int i) {
        std::cout << i << std::endl;
    });

    int multi = 2;
    int c;
    c = std::count_if(numbers.begin(), numbers.end(), [=](int x) {
        return !(x % multi);
    });

    std::cout << "Enteros que son múltiplos de " << multi << " : " << c << std::endl;

    int sum = 0;
    std::for_each(numbers.begin(), numbers.end(), [&](int x) {
        sum += x;
    });

    std::cout << "La suma es " << sum << std::endl;

    return 0;
}
