#ifndef CALLIB_ARC_H
#define CALLIB_ARC_H

#include "GraphObject.h"
#include "Point.h"
#include "Angle.h"

namespace callib {
    class Arc : public GraphObject {
    public:
        E_GraphType getType() const { return E_GraphType::ARC; };

        Point center;
        double radius;
        Angle beginAngle;
        Angle endAngle;
        E_Direction direction;

        Arc(const Point& center = Point(), double radius = 0.0, const Angle& startAngle = 0.0, const Angle& endAngle = 360.0, E_Direction direction = CounterClockWise);

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
