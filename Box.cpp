#include "Box.h"


Box::Box(int height, int width) {
    this->width = width;
    this->height = height;
}

void Box::getDimensions() {
    std::cout << "Ancho " << width << " Alto " << height;
}
