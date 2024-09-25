#include "iostream"
using namespace std;

static int static_main = []() {cout << "static_main\n"; return 0; }();

int main() {
	cout << "main\n";
	return 0;
}