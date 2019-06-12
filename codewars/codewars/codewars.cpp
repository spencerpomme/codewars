#include "solution.hpp"

int main() {
	int n;
	int m;
	std::cin >> n >> m;
	int mm = m;
	int sum = 0;
	int k = -1;
	for (int i = 1; i <= n; ++i) {
		while (m > 0) {
			sum += k * i;
			cout << k * i << " " << sum << " " << m << endl;
			++i; --m;
		}
		--i;
		k *= -1;
		m = mm;
	}
	cout << sum;
	return 0;
}
