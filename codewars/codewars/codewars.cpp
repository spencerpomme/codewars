#include "solution.hpp"
#include "primer_objects.hpp"
#include "func_tutorial.hpp"

int main() {
	
	Fighter fighter1("Jerry", 30, 3);
	Fighter fighter2("Harald", 20, 5);

	cout << declareWinner(&fighter1, &fighter2, "Jerry") << endl;
	cout << ceil(30 * 1.0 / 5) << " " << ceil(20 *1.0/ 3) << endl;

	return 0;
}
