#include "Point.h"

namespace callib {

    Point::Point(double x, double y)
        : x(x), y(y) {}

    Point& Point::offset(double offsetX, double offsetY) {
        x += offsetX;
        y += offsetY;
        return *this;
    }

    double Point::length() const
    {
        return std::sqrt(x * x + y * y);
    }

    Point& Point::normalize()
    {
        double len = length();
        if (len != 0){
            *this /= len;
        }
        return *this;
    }


    Point& Point::operator+=(const Point& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    Point& Point::operator-=(const Point& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Point& Point::operator*=(const Point& other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }
    Point& Point::operator/=(const Point& other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }
    Point Point::operator+(const Point& other) {
        Point result(*this);
        result += other;
        return result;
    }
    Point Point::operator-(const Point& other) {
        Point result(*this);
        result -= other;
        return result;
    }
    Point Point::operator*(const Point& other) {
        Point result(*this);
        result *= other;
        return result;
    }
    Point Point::operator/(const Point& other) {
        Point result(*this);
        result /= other;
        return result;
    }

    bool Point::operator==(const Point& other) const
    {
        return (lf_equal(x, other.x) && lf_equal(y, other.y));
    }

    std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

} // namespace callib
