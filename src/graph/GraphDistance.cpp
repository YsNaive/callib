#include "GraphDistance.h";

namespace callib {
	GraphDistance::GraphDistance(const GraphObject& a, const GraphObject& b)
		: a(&a), b(&b), line(GraphDistance::calculate(a, b)), distance(line.length()) {}

	Line GraphDistance::calculate(const GraphObject& a, const GraphObject& b){
		E_GraphType atype = a.getType(), btype = b.getType();
		if (atype ==		POINT) {
			if (btype ==		POINT)	return GraphDistance::calculate((Point&)(a), (Point&)(b));
			else if (btype ==	LINE)	return GraphDistance::calculate((Point&)(a), (Line&)(b));
			else if (btype ==	ARC)	return GraphDistance::calculate((Point&)(a), (Arc&)(b));
		}
		else if (atype ==	LINE) {
			if (btype ==		POINT)	return GraphDistance::calculate((Line&)(a), (Point&)(b));
			else if (btype ==	LINE)	return GraphDistance::calculate((Line&)(a), (Line&)(b));
			//else if (btype == ARC) line = GraphDistance::calculate((Line&)(a), (Arc&)(b));
		}
		std::cout << "callib:: Calculate distance from \'" << a.getTypeName() << "\' to \'" << b.getTypeName() << "\' Not Implement.\n";
		abort();
	}

	Line GraphDistance::calculate(const Point& a, const Point& b)
	{
		return Line(a, b);
	}

	Line GraphDistance::calculate(const Point& a, const Line& b)
	{
		Line toA = Line(a, b.begin), toB = Line(a, b.end);
		return (toA.length() < toB.length()) ? toA : toB;
	}

	Line GraphDistance::calculate(const Point& a, const Arc& b)
	{
		Line p2c = Line(a, b.center);
		auto intersection = GraphIntersection(p2c, b);
		if (intersection) {
			return Line(a, intersection[0]);
		}
		else
		{
			auto l1 = Line(a, b.beginPoint()), l2 = Line(a, b.endPoint());
			return (l1.length() < l2.length()) ? l1 : l2;
		}
	}

	Line GraphDistance::calculate(const Line& a, const Line& b)
	{
		GraphIntersection intersection(a, b);
		if (intersection) return Line(intersection[0], intersection[0]);

		Line line[4] = { Line(a.begin, b.begin), Line(a.begin, b.end),Line(b.begin, a.begin),Line(b.begin, a.end) };
		double len[4] = { line[0].length(), line[1].length(), line[2].length(), line[3].length() };
		int i = 0;
		if (len[i] > len[1])i = 1;
		if (len[i] > len[2])i = 2;
		if (len[i] > len[3])i = 3;
		return line[i];
	}

	Line GraphDistance::calculate(const Line& a, const Arc& b)
	{
		GraphIntersection intersection(a, b);
		if (intersection) return Line(intersection[0], intersection[0]);



		return Line();
	}

	std::ostream& operator<<(std::ostream& os, const GraphDistance& distance)
	{
		return os << "len: " << distance.distance;
	}
}