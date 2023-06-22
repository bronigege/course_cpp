//
// Created by Bruno Gómez García on 21/6/23.
//

#include "Account.h"
Account::Account(double total) {
    this->total = total;
}

double Account::getTotal() const {
    return total;
}

Account operator+(const Account& account1, const Account& account2) {
    return Account{account1.getTotal() + account2.getTotal()};
}

Account operator+(double total, const Account& account) {
    return Account(total + account.getTotal());
}

Account operator+(const Account& account, double total) {
    return Account(total + account.getTotal());
}
