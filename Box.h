//
// Created by Bruno Gómez García on 19/6/23.
//

#ifndef ROL_BOX_H
#define ROL_BOX_H

#include <iostream>
#include <string>

using namespace std;

class Box {
    int height;
    int width;
public:
    Box(int height, int width);
    void getDimensions();
};

#endif //ROL_BOX_H
