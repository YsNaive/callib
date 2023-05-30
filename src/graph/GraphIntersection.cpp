#include "GraphIntersection.h"

namespace callib {
	GraphIntersection::GraphIntersection(const GraphObject& a, const GraphObject& b)
	{
		bool hasImplement = true;
		GraphType atype = a.getType(), btype = b.getType();
		if (atype == POINT) {
			if (btype ==		LINE)	points = GraphIntersection::calculate((Point&)(a), (Line&)(b));
			//else if (btype ==	ARC)	points = GraphIntersection::calculate((Point&)(a), (Arc&)(b));
			else hasImplement = false;
		}		
		else if (atype == LINE) {
			if (btype ==		POINT)	points = GraphIntersection::calculate((Line&)(a), (Point&)(b));
			else if (btype ==	LINE)	points = GraphIntersection::calculate((Line&)(a), (Line&)(b));
			else if (btype ==	ARC)	points = GraphIntersection::calculate((Line&)(a), (Arc&)(b));
			else hasImplement = false;
		}
		else if (atype == ARC) {
			//if (btype ==		POINT)	points = GraphIntersection::calculate((Arc&)(a), (Point&)(b));
			if (btype ==	LINE)	points = GraphIntersection::calculate((Arc&)(a), (Line&)(b));
			else if (btype ==	ARC)	points = GraphIntersection::calculate((Arc&)(a), (Arc&)(b));
			else hasImplement = false;
		}
		else hasImplement = false;

		intersectionCount = points.size();
		if (!hasImplement) {
			std::cout << "callib:: Calculate intersection between \'" << a.getTypeName() << "\' and \'" << b.getTypeName() << "\' Not Implement.\n";
			abort();
		}
	}

	std::vector<Point> GraphIntersection::calculate(const Point& a, const Line& b) {
		std::vector<Point> out;
		auto equ = b.equation();
		if (callibRound(a.y) == callibRound(equ.a * a.x + equ.b)) {
			if ((a.x >= std::min(b.begin.x, b.end.x)) &&
				(a.x <= std::max(b.begin.x, b.end.x)) &&
				(a.y >= std::min(b.begin.y, b.end.y)) &&
				(a.y <= std::max(b.begin.y, b.end.y)))
				out.push_back(a);
		}
		return out;
	}

	std::vector<Point> GraphIntersection::calculate(const Point& a, const Arc& b)
	{
		std::vector<Point> out;
		if (callibRound(Line(a, b.center).length()) == callibRound(b.radius)) {
			if (b.isAngleBetween(Angle(b.center, a)))
				out.push_back(a);
		}
		return out;
	}

	std::vector<Point> GraphIntersection::calculate(const Line& a, const Line& b)
	{
		std::vector<Point> out;

		// 使用直線方程式求交點
		double x1 = a.begin.x;
		double y1 = a.begin.y;
		double x2 = a.end.x;
		double y2 = a.end.y;
		double x3 = b.begin.x;
		double y3 = b.begin.y;
		double x4 = b.end.x;
		double y4 = b.end.y;

		double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

		// 如果分母為零，則兩線段平行或共線，無交點
		if (d != 0) {
			double numerator1 = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
			double numerator2 = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
			Point p = Point(numerator1 / d, numerator2 / d);
			if(GraphIntersection(p,a) && GraphIntersection(p,b))
				out.push_back(p);
		}
		return out;
	}

	std::vector<Point> GraphIntersection::calculate(const Line& a, const Arc& b)
	{
		std::vector<Point> out;
		auto line = a.equation();
		auto circle = b.equation();

		double A = pow(line.a, 2) + 1;
		double B = 2 * (line.a * line.b - line.a * circle.b - circle.a);
		double C = pow(circle.a, 2) + pow(line.b - circle.b, 2) - pow(circle.r, 2);
		double d = pow(B, 2) - 4 * A * C;
		// 只有一個交點
		if (d == 0) {
			double x = -B / (2 * A);
			Point point = Point(x, line.a * x + line.b);
			if (b.isAngleBetween(Angle(b.center, point)) && GraphIntersection(point, a))
				out.push_back(point);
		}// 有兩個交點
		else if (d>0)
		{
			double sd = sqrt(d);
			double x = (-B + sd) / (2 * A);
			Point point = Point(x, line.a * x + line.b);
			if (b.isAngleBetween(Angle(b.center, point)) && GraphIntersection(point, a))
				out.push_back(point);
			x = (-B - sd) / (2 * A);
			point = Point(x, line.a * x + line.b);
			if (b.isAngleBetween(Angle(b.center, point)) && GraphIntersection(point, a))
				out.push_back(point);
		}
		return out;
	}

	std::vector<Point> GraphIntersection::calculate(const Arc& a, const Arc& b)
	{
		std::vector<Point> out;
		if (a.center == b.center) return out;

		Line a2b = Line(a.center, b.center);
		double len = a2b.length();
		if (len > (a.radius + b.radius)) return out;

		double d = (a.radius * a.radius - b.radius * b.radius + len * len) / (2 * len);
		double h = sqrt(a.radius * a.radius - d * d);
		double mx = a.center.x + d * (b.center.x - a.center.x) / len;
		double my = a.center.y + d * (b.center.y - a.center.y) / len;

		if (callibRound(len) == callibRound(a.radius + b.radius)) {
			Point p = Point(mx, my);
			if(a.isAngleBetween(Angle(a.center,p)) && b.isAngleBetween(Angle(b.center,p)))
				out.push_back(p);
		}
		else {
			double dx = h * (b.center.y - a.center.y) / len;
			double dy = h * (b.center.x - a.center.x) / len;

			Point p = Point(mx + dx, my - dy);
			if (a.isAngleBetween(Angle(a.center, p)) && b.isAngleBetween(Angle(b.center, p)))
				out.push_back(p);
			p = Point(mx - dx, my + dy);
			if (a.isAngleBetween(Angle(a.center, p)) && b.isAngleBetween(Angle(b.center, p)))
				out.push_back(p);
		}
		return out;
	}

	GraphIntersection::operator bool() const {
		return intersectionCount != 0;
	}

	Point GraphIntersection::operator[](int i) {
		return points[i];
	}

	std::ostream& operator<<(std::ostream& os, const GraphIntersection& intersection)
	{
		os << intersection.intersectionCount << " intersection: ";
		for (auto &p : intersection.points)
			os << p << ' ';
		return os;
	}
}