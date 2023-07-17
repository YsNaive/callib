#include "Line.h"

namespace callib {
	std::ostream& operator<<(std::ostream& os, const Line& line)
	{
		return os << "[" << line.begin << ", " << line.end << "]";
	}
	std::ostream& operator<<(std::ostream& os, const Line::Equation& e)
	{
		return os << "y = " << e.a << "x + " << e.b;
;	}
	double Line::length() const
	{
		return sqrt(pow(begin.x - end.x, 2) + pow(begin.y - end.y, 2));
	}

	Line::Equation Line::equation() const
	{
		Line::Equation out;
		out.isVertical = begin.x == end.x;
		if (out.isVertical) out.a = INFINITY;
		else out.a = (end.y - begin.y) / (end.x - begin.x);
		out.b = begin.y - out.a * begin.x;
		return out;
	}

}