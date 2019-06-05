#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <math.h>
#include <array>
#include <utility> 

using std::string;
using std::vector;
using std::array;
using std::set;
using std::pow;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

string bingo(vector<pair<string, int>> ticket, int win);
string to_postfix(string infix);
bool isPalindrom(const std::string& str);
int centuryFromYear(int year);
unsigned short int expressionsMatter(unsigned short int a, unsigned short int b, unsigned short int c);
vector<int> solve(vector<string> arr);
string DNAtoRNA(string dna);
void check_is_contained(int** mat1, const int mat2[3][3], const int nrows, const int ncols, int& row, int& col);
bool if_equal(int** mat1, const int mat2[3][3], int cur_row, int cur_col, int& row, int& col);
long long int maxNumber(long long int  number);
string capitalize(string s, vector<int> idxs);
unsigned long long minValue(vector <int> values);
string highAndLow(const string&);
vector<int> split(const string&, string);
int min(const vector<int>&);
int max(const vector<int>&);
template <typename T>
void print(const vector<T>&);
template <typename T>
void print(const set<T>&);
template <typename T>
void print(T);

// defined functions:

string bingo(vector<pair<string, int>> ticket, int win)
{
	int miniwin = 0;
	for (auto pair : ticket) {
		for (char ch : pair.first) {
			if (int(ch) == pair.second) {
				++miniwin;
				break;
			}
		}
	}
	if (miniwin >= win)
		return "Winner!";
	else
		return "Loser!";
}

string to_postfix(string infix) {
	return "";
}

bool isPalindrom(const std::string& str)
{
	int mid = str.size() / 2;
	for (int i = 0; i < mid; ++i)
		if (str.at(i) != str.at((str.size() - 1 - i)))
			return false;
	return true;
}

int centuryFromYear(int year)
{
	return (year / 100) + ((year % 100 > 0) ? 1 : 0);
}

unsigned short int expressionsMatter(unsigned short int a, unsigned short int b, unsigned short int c) {
	vector<unsigned short int> resvec;
	resvec.push_back(a + b + c);
	resvec.push_back(a + b * c);
	resvec.push_back(a * b + c);
	resvec.push_back(a * b * c);
	resvec.push_back((a + b) * c);
	resvec.push_back(a * (b + c));
	return *std::max_element(resvec.begin(), resvec.end());
}

vector<int> solve(vector<string> arr) {
	vector<int> match;
	for (string str : arr) {
		transform(str.begin(), str.end(), str.begin(), tolower);
		int counter = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (int(str[i]) - 96 == i + 1)
				++counter;
		}
		match.push_back(counter);
	}
	return match;
}

string DNAtoRNA(string dna) {
	replace(dna.begin(), dna.end(), 'T', 'U');
	return dna;
}

void check_is_contained(int** mat1, const int mat2[3][3], const int nrows, const int ncols, int& row, int& col)
{
	for (int i = 0; i <= nrows - 3; ++i) {
		for (int j = 0; j <= ncols - 3; ++j) {
			if (mat1[i][j] == mat2[0][0]) {
				bool equal = if_equal(mat1, mat2, i, j, row, col);
				if (equal == true) return;
			}
		}
	}
	row = -1;
	col = -1;
}

bool if_equal(int** mat1, const int mat2[3][3], int cur_row, int cur_col, int& row, int& col) {
	for (int m = 0; m < 3; ++m)
		for (int n = 0; n < 3; ++n)
			if (mat1[cur_row + m][cur_col + n] != mat2[m][n])
				return false;
	row = cur_row;
	col = cur_col;
	return true;
}

long long int maxNumber(long long int number)
{
	string s = std::to_string(number);
	std::sort(s.begin(), s.end(), [](const char& a, const char& b) { return a > b; });
	return std::stoll(s);
}

string capitalize(string s, vector<int> idxs)
{
	int size = s.size();
	for (int i : idxs) {
		if (i < size)
			s[i] = toupper(s[i]);
	}
	return s;
}

unsigned long long minValue(vector <int> values)
{
	set<int> valnique(values.begin(), values.end());
	int size = int(valnique.size());
	unsigned long long res = 0;
	for (int i = size - 1; i >= 0; --i)
		res += *std::next(valnique.begin(), i) * pow(10, size - 1 - i);
	return res;
}

string highAndLow(const string& numbers) {
	int low = min(split(numbers, " "));
	int high = max(split(numbers, " "));
	string res;
	res.append(std::to_string(high));
	res.append(" ");
	res.append(std::to_string(low));
	return res;
}

/*
vector<int> split(const string& str, string delimiter) {
	vector<int> res;
	string::size_type posl = 0;
	string::size_type posr = str.find(delimiter);
	string token = str.substr(posl, posr);
	res.push_back(std::stoi(token));
	while (posr != string::npos) {
		posl = posr;
		posr = str.find(delimiter, ++posr);
		res.push_back(std::stoi(str.substr(posl, posr)));
	}
	return res;
}
*/

vector<int> split(const string& str, string delimiter) {
	std::stringstream ss(str);
	string temp;
	vector<int> res;
	while (ss >> temp) {
		if (temp != delimiter)
			res.push_back(std::stoi(temp));
	};
	return res;
}

int min(const vector<int>& list) {
	return *std::min_element(list.begin(), list.end());
}

int max(const vector<int>& list) {
	return *std::max_element(list.begin(), list.end());
}

template <typename T>
void print(const vector<T>& vec) {
	cout << "[ ";
	for (T item : vec)
		cout << item << " ";
	cout << "]" << endl;
}

template <typename T>
void print(const set<T>& vec) {
	cout << "( ";
	for (T item : vec)
		cout << item << " ";
	cout << ")" << endl;
}

template <typename T>
void print(T str) {
	cout << str << endl;
}