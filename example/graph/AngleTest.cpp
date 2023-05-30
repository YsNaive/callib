#include <iostream>
#include "Angle.h"

int main() {
    callib::Angle angle(45.0f);

    std::cout << "angle: " << angle << "\n\n";

    std::cout << "add: " << angle + 360 + 0.5 << '\n';
    std::cout << "sub: " << angle - 360 - 0.5 << '\n';
    std::cout << "mul: " << angle * 2 << '\n';
    std::cout << "div: " << angle / 0.5 << "\n\n";

    std::cout << "Sin: " << angle.sin() << '\n';
    std::cout << "Cos: " << angle.cos() << '\n';
    std::cout << "Tan: " << angle.tan() << '\n';

    return 0;
}
