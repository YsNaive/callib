#ifndef CALLIB_POINT_H
#define CALLIB_POINT_H

#include <iostream>
#include "GraphObject.h"
namespace callib {

    class Point : public GraphObject {
    public:
        E_GraphType getType() const { return E_GraphType::POINT; };

        double x;  // x §¤¼Ð
        double y;  // y §¤¼Ð

        Point(double x = 0, double y = 0);

        Point& operator+=(const Point& other);
        Point& operator-=(const Point& other);
        Point& operator*=(const Point& other);
        Point& operator/=(const Point& other);
        Point operator+(const Point& other);
        Point operator-(const Point& other);
        Point operator*(const Point& other);
        Point operator/(const Point& other);
        bool operator==(const Point& other) const;

        double length() const;
        Point& offset(double offsetX, double offsetY);
        Point& normalize();

        friend std::ostream& operator<<(std::ostream& os, const Point& point);
    };
} // namespace callib

#endif // CALLIB_POINT_H
