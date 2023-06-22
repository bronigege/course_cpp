//
// Created by Bruno Gómez García on 21/6/23.
//

#include "Point.h"


Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

//
void Point::print() {
    std::cout << "Punto {x: " <<
        x << ", y: " <<
        y << ", z: " <<
        z << "}";
}

std::ostream& operator <<(std::ostream& out, const Point& point) {
    out << "Punto {x: " <<
              point.x << ", y: " <<
              point.y << ", z: " <<
              point.z << "}";

    return out;
}

std::istream& operator >>(std::istream& in, Point& point) {
    in >> point.x;
    in >> point.y;
    in >> point.z;

    return in;
}

void Point::operator()() {
    for (int row{0}; row < 5; ++row) {
        for (int col{0}; col < 5; ++ col) {
            points[row][col] = 0.0;
        }
    }
}

double &Point::operator()(int row, int col) {
    assert(col > 0 && col < 5);
    assert(row > 0 && row < 5);

    return points[row][col];
}

double Point::operator()(int row, int col) const {
    assert(col > 0 && col < 5);
    assert(row > 0 && row < 5);

    return points[row][col];
}