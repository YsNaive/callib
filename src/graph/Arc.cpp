#include "Arc.h"

namespace callib {

    Arc::Arc(const Point& center, double radius, const Angle& startAngle, const Angle& endAngle, E_Direction direction)
        : center(center), radius(radius), beginAngle(startAngle), endAngle(endAngle), direction(direction) {}

    bool Arc::isAngleBetween(Angle angle) const
    {
        double now, gap;
        now = angle - beginAngle;
        gap = endAngle - beginAngle;

        if (direction == E_Direction::CounterClockWise) {
            return ((now < gap) || (lf_equal(now, gap)));
        }
        else {
            return ((now == 0) || (now > gap) || lf_equal(now, gap));
        }
    }

    double Arc::length() const {
        return radius * abs(beginAngle.deg() - endAngle.deg()) * DEG2RAD;
    }

    Point Arc::beginPoint() const
    {
        return Point(center.x + (beginAngle.sin() *radius), center.y + (beginAngle.cos() * radius));
    }

    Point Arc::endPoint() const
    {
        return Point(center.x + (endAngle.sin() * radius), center.y + (endAngle.cos() * radius));
    }

    std::ostream& operator<<(std::ostream& os, Arc& arc) {
        return os << "center: " << arc.center << " radius: " << arc.radius << "  From " << arc.beginAngle << " to " << arc.endAngle;
    }

    Arc::Equation Arc::equation() const
    {
        Arc::Equation out;
        out.a = center.x;
        out.b = center.y;
        out.r = radius;
        return out;
    }

} // namespace callib
