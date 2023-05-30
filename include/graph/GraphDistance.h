#ifndef CALLIB_GRAPH_DISTANCE_H
#define CALLIB_GRAPH_DISTANCE_H

#include "GraphObject.h"
#include "Point.h"
#include "Line.h"
#include "Arc.h"
#include "GraphIntersection.h"

namespace callib {

    class GraphDistance {
    public:
        double distance;
        Line line;
        GraphDistance(const GraphObject& a, const GraphObject& b);

        static Line calculate(const Point& a, const Point& b);
        static Line calculate(const Point& a, const Line& b);
        static Line calculate(const Point& a, const Arc& b);

        static Line calculate(const Line& a, const Line& b);
        static Line calculate(const Line& a, const Arc& b);
        static Line calculate(const Line& a, const Point& b) { return GraphDistance::calculate(b, a); };

        static Line calculate(const Arc& a, const Arc& b);
        static Line calculate(const Arc& a, const Point& b) { return GraphDistance::calculate(b, a); };
        static Line calculate(const Arc& a, const Line& b) { return GraphDistance::calculate(b, a); };;


        friend std::ostream& operator<<(std::ostream& os, const GraphDistance& distance);
    };
}

#endif
