//
// Created by Bruno Gómez García on 21/6/23.
//

#ifndef FUNCTORS_ACCOUNT_H
#define FUNCTORS_ACCOUNT_H


class Account {
private:
    double total;
public:
    explicit Account(double total);

    /*
     * FUNCIONES AMIGAS
     * tiene la capacidad de acceder a los miembros privados
     * y protegidos de la clase, lo que puede ser una violación
     * del principio de encapsulamiento
    friend Account operator +(const Account& account1, const Account& account2);

    friend Account operator +(double valor, const Account& e);

    friend Account operator +(const Account& e, double valor);
     */

    [[nodiscard]] double getTotal() const;
};

// Funciones normales que respetan el principio de encapsulamiento
Account operator +(const Account& account1, const Account& account2);

Account operator +(double valor, const Account& e);

Account operator +(const Account& e, double valor);

#endif //FUNCTORS_ACCOUNT_H
