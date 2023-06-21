//
// Created by Bruno Gómez García on 21/6/23.
//

#ifndef UNTITLED_COMPARADOR_H
#define UNTITLED_COMPARADOR_H

struct Comparador {
    bool operator()(auto& l, auto& r) const {
        return l > r;
    }
};

#endif //UNTITLED_COMPARADOR_H
