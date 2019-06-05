#include "solution.hpp"

int main()
{
	typedef std::pair<std::string, int> p;
	cout << bingo({ p("ABC", 65), p("HGR", 74), p("BYHT", 74) }, 2) << endl;

	return 0;
}
