#include "Point.h"

namespace callib {

    Point::Point(double x, double y)
        : x(x), y(y) {}

    void Point::offset(double offsetX, double offsetY) {
        x += offsetX;
        y += offsetY;
    }

    bool Point::operator==(const Point& other) const
    {
        return (x == other.x) && (y == other.y);
    }

    std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

} // namespace callib
