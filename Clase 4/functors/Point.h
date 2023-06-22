//
// Created by Bruno Gómez García on 21/6/23.
//

#ifndef FUNCTORS_POINT_H
#define FUNCTORS_POINT_H
#include <iostream>


class Point {
private:
    double x;
    double y;
    double z;
    double points[5][5]{};

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0);

    // std::cout es un objeto de tipo std::ostream
    friend std::ostream& operator <<(std::ostream& out, const Point& point);

    // std::cin es un objeto de tipo std::istream
    friend std::istream& operator >>(std::istream& in, Point& point);

    double& operator()(int row, int col);
    double operator()(int row, int col) const;
    void operator()();

    void print();
};





#endif //FUNCTORS_POINT_H
