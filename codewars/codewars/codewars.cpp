#include "solution.hpp"

int main() {
	
	vector<int (*)(int, int)> func_vec{ add, sub, mul, divide };
	for (auto ptr : func_vec)
		cout << __FUNCTION__ << " : " << ptr(4, 2) << endl;

	return 0;
}
