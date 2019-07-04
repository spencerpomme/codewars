#include "solution.hpp"

int main() {
	int j[2] = { 0, 1 };
	auto ptr = std::begin(j);
	cout << "ptr: " << ptr << " " << "*ptr: " << *ptr << endl;
	return 0;
}

