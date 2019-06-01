// katas.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "solutions.hpp"

int main()
{
	string animal = "blue dog";
	string dish = "bacon log";
	cout << *animal.begin() << " " << *dish.begin() << endl;
	cout << *(animal.end() - 1) << " " << *(dish.end()-1) << endl;
	return 0;
}

