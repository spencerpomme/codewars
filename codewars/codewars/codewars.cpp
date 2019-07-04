#include "solution.hpp"
double calc(double);

int main() {

	decltype(calc(2.0)) res;
	res = calc(2);

	return 0;
}

double calc(double num) {
	return num * 2;
}

