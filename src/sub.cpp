#include <iostream>
static int static_sub = []() {std::cout << "static_sub\n"; return 0; }();