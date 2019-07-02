#include "solution.hpp"
#include <cstring>

int main() {
	int grade;
	string lettergrade;
	cin >> grade;
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	if (grade < 60)
		lettergrade = scores[0];
	else
		lettergrade = scores[(grade - 50) / 10];
	cout << lettergrade << endl;
	return 0;
}