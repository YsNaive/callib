#include <iostream>
#include <string>
#include "callib.h"

using namespace std;
using namespace callib;

int main() {
    Line l1(Point(0, 0), Point(1, 1));
    Line l2(Point(1, 0), Point(0, 1));
    cout << "Line1: " << l1 << " Line2: " << l2 << "\n    " << GraphIntersection(l1, l2) << "\n\n";

    l1 = Line(Point(0, 0), Point(1, 0));
    l2 = Line(Point(0, 0), Point(0, 1));
    cout << "Line1: " << l1 << " Line2: " << l2 << "\n    " << GraphIntersection(l1, l2) << "\n\n";

    l1 = Line(Point(0, 1), Point(1, 1));
    l2 = Line(Point(0, 2), Point(1, 0));
    cout << "Line1: " << l1 << " Line2: " << l2 << "\n    " << GraphIntersection(l1, l2) << "\n\n";

    l1 = Line(Point(0, 0), Point(1, 0));
    l2 = Line(Point(0, 1), Point(1.5, 0));
    cout << "Line1: " << l1 << " Line2: " << l2 << "\n    " << GraphIntersection(l1, l2) << "\n\n";
    return 0;
}
