#include "Angle.h"

namespace callib {

    Angle::Angle(double angle, double min, double range)
        : minValue(min), range(range) {
        this->value = valueCheck(angle);
    }

    Angle::Angle(const Point& from, const Point& to)
        : minValue(0), range(360) {
        this->value = valueCheck((atan2(to.y - from.y, to.x - from.x) * RAD2DEG));
    }

    double Angle::valueCheck(double val) const {
        while (val < minValue)
            val += range;
        while (val > minValue + range)
            val -= range;
        return val;
    }

#pragma region Angle overload

    Angle Angle::operator+(Angle other) const {
        return Angle(valueCheck(value + other), minValue, range);
    }

    Angle Angle::operator-(Angle other) const {
        return Angle(valueCheck(value - other), minValue, range);
    }

    Angle Angle::operator*(Angle other) const {
        return Angle(valueCheck(value * other), minValue, range);
    }

    Angle Angle::operator/(Angle other) const {
        return Angle(valueCheck(value / other), minValue, range);
    }
#pragma endregion

#pragma region double overload
    Angle::operator double() const {
        return value;
    }

    Angle& Angle::operator=(double other) {
        value = valueCheck(other);
        return *this;
    }

    Angle Angle::operator+(double other) const {
        return Angle(valueCheck(value + other), minValue, range);
    }

    Angle Angle::operator-(double other) const {
        return Angle(valueCheck(value - other), minValue, range);
    }

    Angle Angle::operator*(double other) const {
        return Angle(valueCheck(value * other), minValue, range);
    }

    Angle Angle::operator/(double other) const {
        return Angle(valueCheck(value / other), minValue, range);
    }
#pragma endregion

#pragma region int overload

    Angle& Angle::operator=(int other) {
        value = valueCheck((double)other);
        return *this;
    }

    Angle Angle::operator+(int other) const {
        return Angle(valueCheck(value + other), minValue, range);
    }

    Angle Angle::operator-(int other) const {
        return Angle(valueCheck(value - other), minValue, range);
    }

    Angle Angle::operator*(int other) const {
        return Angle(valueCheck(value * other), minValue, range);
    }

    Angle Angle::operator/(int other) const {
        return Angle(valueCheck(value / other), minValue, range);
    }
#pragma endregion

    double Angle::deg() const {
        return value;
    }

    double Angle::rad() const {
        return value * DEG2RAD;
    }

    double Angle::sin() const {
        return std::sin(rad());
    }

    double Angle::cos() const {
        return std::cos(rad());
    }

    double Angle::tan() const {
        return std::tan(rad());
    }

    std::ostream& operator<<(std::ostream& os, const Angle& angle) {
        os << angle.value;
        return os;
    }

} // namespace callib
