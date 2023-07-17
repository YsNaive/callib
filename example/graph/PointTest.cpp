#include <iostream>
#include "Point.h"

using namespace std;
using namespace callib;
int main() {
    // 建立兩個點物件
    Point p1(2.5, 3.7);
    Point p2(1.2, -0.8);

    // 輸出點的座標
    cout << "Point 1: " << p1 << endl;
    cout << "Point 2: " << p2 << endl;

    // 偏移點的座標
    p1.offset(1.0, -2.0);
    p2.offset(-0.5, 1.5);

    // 輸出偏移後的點的座標
    cout << "Offset Point 1: " << p1 << endl;
    cout << "Offset Point 2: " << p2 << endl;

    // 比較兩個點是否相等
    bool isEqual = (p1 == p2);
    cout << "Points are equal   : " << boolalpha << isEqual << endl;
    isEqual = (p2 == Point(0.7, 0.7));
    cout << "Point2 == (0.7,0.7): " << boolalpha << isEqual << endl;

    return 0;
}