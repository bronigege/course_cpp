//
// Created by Bruno Gómez García on 21/6/23.
//

#ifndef FUNCTORS_ACCOUNTPRIVATE_H
#define FUNCTORS_ACCOUNTPRIVATE_H


class AccountPrivate {
private:
    int total;
public:
    AccountPrivate(int total);

    int getTotal() const;

    AccountPrivate operator +(int value) const;
    AccountPrivate operator +(const AccountPrivate& account1) const;

    AccountPrivate operator ==(const AccountPrivate& account1) const;
    AccountPrivate operator !=(const AccountPrivate& account1) const;

    /*
     * La función miembro no necesita ningún parámetro, porque
     * opera sobre el puntero oculto this
     */
    AccountPrivate operator -() const;
    AccountPrivate operator --(); // Versión --variable
    AccountPrivate operator --(int); // Versión variable--
    AccountPrivate operator +() const;
    AccountPrivate operator ++(); // Versión ++variable
    AccountPrivate operator ++(int); // Versión variable++

    bool operator !() const;

    explicit operator bool() const;
};


#endif //FUNCTORS_ACCOUNTPRIVATE_H
