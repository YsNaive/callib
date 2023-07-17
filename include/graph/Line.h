#ifndef CALLIB_LINE_H
#define CALLIB_LINE_H

#include "GraphObject.h"
#include "Point.h"

namespace callib {
    class Line : public GraphObject {
    public:
        E_GraphType getType() const { return E_GraphType::LINE; };

        Point begin;
        Point end;
        Line(const Point& start = Point(), const Point& end = Point()) { this->begin = start; this->end = end; };
        Line(double x1, double y1, double x2, double y2) { this->begin = Point(x1, y1); this->end = Point(x2, y2); };
        double length() const;
        void offset(double offsetX, double offsetY);

        friend std::ostream& operator<<(std::ostream& os, const Line& line);

        struct Equation
        {
            double a, b;
            bool isVertical;

            friend std::ostream& operator<<(std::ostream& os, const Line::Equation& e);
        };
        // y = ax+b
        Line::Equation equation() const;
    };
}

#endif
