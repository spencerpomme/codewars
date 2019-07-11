#include "solution.hpp"
#include "primer_objects.hpp"

int main() {
	while (true) {
		// the simplest event loop :)
		string cat;
		getline(cin, cat);
		if (cat != "")
			cout << "cat is named: " << cat << endl;
		else
			break;
	}
}
