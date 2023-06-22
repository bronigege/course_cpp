//
// Created by Bruno Gómez García on 21/6/23.
//

#ifndef FUNCTORS_FUNTOR_H
#define FUNCTORS_FUNTOR_H


class Funtor {
private:
    int count{};

public:
    int operator()(int c);
};


#endif //FUNCTORS_FUNTOR_H
