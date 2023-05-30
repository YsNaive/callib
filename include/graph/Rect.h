#ifndef CALLIB_RECT_H
#define CALLIB_RECT_H

#include <iostream>
#include <math.h>
#include "Point.h"
#include "Line.h"
#include "Arc.h"
namespace callib {
    class Rect : public GraphObject{
    public:
        GraphType getType() const { return GraphType::RECT; };

        double x;
        double y;
        double width;
        double height;

        Rect(double x = 0.0, double y = 0.0, double width = 0.0, double height = 0.0);
        // bounding rect
        Rect(GraphObject& obj);

        double xMax() const;
        double yMax() const;
        double area() const;
        Point leftTop() const;
        Point rightBottom() const;
        void borderOffset(double dx, double dy);
        bool isCover(const GraphObject& obj);

        Rect operator-(const Rect& other) const;
        Rect operator+(const Rect& other) const;


        friend std::ostream& operator<<(std::ostream& os, const Rect& rect);
    };

    std::ostream& operator<<(std::ostream& os, const Rect& rect) {
        os << "Rect(x=" << rect.x << ", y=" << rect.y << ", width=" << rect.width << ", height=" << rect.height << ")";
        return os;
    }

} // namespace callib

#endif // CALLIB_RECT_H
