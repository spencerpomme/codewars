#include "solution.hpp"

int main()
{
	int num = 123456;
	while (num > 0) {
		cout << "digit: " << num % 10 << endl;
		num = num / 10;
	}

	return 0;
}
