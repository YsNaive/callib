#ifndef CALLIB_GRAPH_INTERSECTION_H
#define CALLIB_GRAPH_INTERSECTION_H

#include <vector>
#include "GraphObject.h"
#include "Point.h"
#include "Line.h"
#include "Arc.h"

namespace callib {

    class GraphIntersection {
    public:
        int intersectionCount;
        std::vector<Point> points;
        

        GraphIntersection(const GraphObject& a, const GraphObject& b);

        static std::vector<Point> calculate(const Point& a, const Line& b);
        static std::vector<Point> calculate(const Point& a, const Arc& b);

        static std::vector<Point> calculate(const Line& a, const Line& b);
        static std::vector<Point> calculate(const Line& a, const Arc& b);
        static std::vector<Point> calculate(const Line& a, const Point& b) { return calculate(b, a); };

        static std::vector<Point> calculate(const Arc& a, const Arc& b);
        static std::vector<Point> calculate(const Arc& a, const Point& b) { return calculate(b, a); };
        static std::vector<Point> calculate(const Arc& a, const Line& b) { return calculate(b, a); };

        operator bool() const;
        Point operator[](int i);
        friend std::ostream& operator<<(std::ostream& os, const GraphIntersection& distance);
    };
}

#endif
