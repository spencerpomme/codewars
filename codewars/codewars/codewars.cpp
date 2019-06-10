#include "solution.hpp"

int main()
{
	char a = '1';
	char b = '2';
	cout << balancedNum(121) << endl;
	cout << balancedNum(1221) << endl;
	cout << balancedNum(11) << endl;
	cout << balancedNum(2) << endl;
	cout << balancedNum(2345432) << endl;
	cout << balancedNum(21112) << endl;
	string num = "2332";
	int mid = num.size() / 2;
	cout << num.substr(0, mid-1) << endl;
	cout << num.substr(mid+1, num.size() - 1) << endl;
	return 0;
}
