#include "solution.hpp"
#include <cstring>

int main() {
	
	int mda[2][3] = { {1,2,3}, {4,5,6} };
	for (auto& row : mda)
		for (auto col : row)
			cout << col << endl;
	return 0;
}
