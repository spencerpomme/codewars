#include "solution.hpp"
#include <cstring>
#include <stdexcept>

int main() {
	
	int nume, denum;
	cout << "Please input two numbers: " << endl;
	cin >> nume >> denum;
	cout << "Calculating " << nume << "/" << denum << endl;
	try {
		if (denum == 0)
			throw std::runtime_error("denumerator cannot be 0.");
		int res = nume / denum;
		cout << "res = " << res << endl;
	}
	catch (std::runtime_error err) {
		cout << err.what() << endl;
	}

	return 0;
}