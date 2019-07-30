#include "solution.hpp"
#include "primer_objects.hpp"
#include "func_tutorial.hpp"

int main() {
	
	Sapien james(33);
	Sapien Luke(22);

	cout << "james age: " << james.getAge() << endl;
	cout << "Luke age: " << Luke.getAge() << endl;
	cout << (james > Luke ? "Yes" : "No") << endl;
	cout << (3 > 2 ? "Yeah" : "Nooo") << endl;

	return 0;
}
