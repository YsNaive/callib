#ifndef CALLIB_POINT_H
#define CALLIB_POINT_H

#include <iostream>
#include "GraphObject.h"
namespace callib {

    class Point : public GraphObject {
    public:
        GraphType getType() const { return GraphType::POINT; };

        double x;  // x ����
        double y;  // y ����

        Point(double x = 0, double y = 0);
        void offset(double offsetX, double offsetY);

        bool operator==(const Point& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Point& point);
    };
} // namespace callib

#endif // CALLIB_POINT_H
