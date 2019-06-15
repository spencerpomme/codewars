#include "solution.hpp"

int main() {
	PartList problem;
	vector<string> vec{ "cdIw", "tzIy", "xDu", "rThG" };
	auto result = problem.partlist(vec);
	for (auto r : result)
		cout << r.first << r.second << endl;
	return 0;
}
