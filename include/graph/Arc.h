#ifndef CALLIB_ARC_H
#define CALLIB_ARC_H

#include "GraphObject.h"
#include "Point.h"
#include "Angle.h"

namespace callib {
    class Arc : public GraphObject {
    public:
        GraphType getType() const { return GraphType::ARC; };

        Point center;
        double radius;
        Angle beginAngle;
        Angle endAngle;
        Direction direction;

        Arc(const Point& center = Point(), double radius = 0, const Angle& startAngle = 0, const Angle& endAngle = 0, Direction direction = CounterClockWise);

        bool isAngleBetween(Angle angle) const;
        double length() const;
        Point beginPoint() const;
        Point endPoint() const;

        friend std::ostream& operator<<(std::ostream& is, Arc& arc);

        // (x-a)^2 + (y-b)^2 = r^2
        struct Equation
        {
            double a, b, r;
        };
        Arc::Equation equation() const;
    };

} // namespace callib

#endif // CALLIB_ARC_H
