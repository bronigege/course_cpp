//
// Created by Bruno Gómez García on 21/6/23.
//

#include "AccountPrivate.h"

AccountPrivate::AccountPrivate(int total) {
    this->total = total;
}

int AccountPrivate::getTotal() const {
    return total;
}

AccountPrivate AccountPrivate::operator +(int value) const {
    return {this->total + value};
}

AccountPrivate AccountPrivate::operator +(const AccountPrivate &account) const {
    return { this->total + account.total};
}

AccountPrivate AccountPrivate::operator -() const {
    /*
     * Como el tipo de retorno es AccountPrivate, hace
     * una conversión implícita de int a AccountPrivate usando el constructor
     * AccountPrivate(int)
     */
    return -total;
}

AccountPrivate AccountPrivate::operator --() {
    --total;
    return *this;
}

AccountPrivate AccountPrivate::operator --(int) {
    AccountPrivate temp(*this);
    --(*this);
    return temp; // devuelve el estado salvado antes del incremento
}

AccountPrivate AccountPrivate::operator +() const {
    return +total;
}

AccountPrivate AccountPrivate::operator ++() {
    ++total;
    return *this;
}

AccountPrivate AccountPrivate::operator ++(int) {
    AccountPrivate temp(*this);
    --(*this);
    return temp;
}

bool AccountPrivate::operator !() const {
    return (total > 0);
}

AccountPrivate::operator bool() const {
    return (total > 0);
}

AccountPrivate AccountPrivate::operator ==(const AccountPrivate &account1) const {
    return (total == account1.getTotal());
}

AccountPrivate AccountPrivate::operator !=(const AccountPrivate &account1) const {
    return (total != account1.getTotal());
}