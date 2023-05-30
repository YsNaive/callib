#ifndef CALLIB_ANGLE_H
#define CALLIB_ANGLE_H
#include <math.h>
#include <iostream>
#include "callibcore.h"
#include "Point.h"

namespace callib {

    class Angle {
    private:
        double value;         // Angle value in degrees
        double minValue;      // Minimum value limit
        double range;         // Maximum value limit
        double valueCheck(double val) const;
    public:
        Angle(double angle = 0.0f, double min = 0.0f, double range = 360.0f);
        Angle(const Point& from, const Point& to);

        double rad() const;
        double deg() const;
        double sin() const;
        double cos() const;
        double tan() const;

        // Overload operators 
        Angle operator+(Angle other) const;
        Angle operator-(Angle other) const;
        Angle operator*(Angle other) const;
        Angle operator/(Angle other) const;
        operator double() const;
        Angle& operator=(double other);
        Angle operator+(double other) const;
        Angle operator-(double other) const;
        Angle operator*(double other) const;
        Angle operator/(double other) const;
        Angle& operator=(int other);
        Angle operator+(int other) const;
        Angle operator-(int other) const;
        Angle operator*(int other) const;
        Angle operator/(int other) const;
        // Overload output stream operator
        friend std::ostream& operator<<(std::ostream& os, const Angle& angle);
    };

} // namespace callib

#endif
