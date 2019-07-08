#include "solution.hpp"

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main() {
	
	//f(2.56, 42);
	vector<void (*)(int, int)> vec;
	for (int i = 0; i < 5; ++i)
		vec.push_back(f);
	print(vec);
}

void f() {
	cout << "f() is called." << endl;
}

void f(int n) {
	cout << "f(int) is called. " << " n = " << n << endl;
}

void f(int n, int m) {
	cout << "f(int, int) is called. " << "numbers: " << n << ", " << m << endl;
}

void f(double x, double y) {
	cout << "f(double, double=3.14) is called. " << "numbers: " << x << ", " << y << endl;
}
