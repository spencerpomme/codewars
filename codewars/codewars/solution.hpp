#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <array>
#include <utility>
#include <regex>
#include <cstdlib>
#include <numeric>
#include <cstring>
#include <stdexcept>
#include <initializer_list>
#include <ctime>
#include <functional>

using std::string;
using std::vector;
using std::array;
using std::set;
using std::pow;
using std::cout;
using std::cin;
using std::endl;
using std::pair;
using std::sqrtl;
using std::regex;
using std::sort;
using std::max;
using std::to_string;
using std::accumulate;
using std::stoi;
using std::stringstream;
using std::getline;
using std::initializer_list;
using std::find;
using std::greater;

int maxSequence(const vector<int>& arr);
string balancedNum(unsigned long long int number);
bool comparelr(string left, string right);
string twoSort(vector<string> s);
string replace(const string& s);
bool isPrime(long long number);
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
int _min(const vector<int>&);
int _max(const vector<int>&);

template <typename T> void print(const vector<T>&);
template <typename T> void print(const set<T>&);
template <typename T> void print(T);

string highandLow(const string& numbers);
string highestScoringWord(const string& str);
int addAdjacent();
unsigned int hotpo(unsigned int n);
int countVowel(string);

//------------------------ c++ primer some interesting problem -------------------------//
int compare(const int val, const int* ptr);
int listSum(initializer_list<int> list);
const string& shorterString(const string& s1, const string& s2);
// original array pointer return type declaration:
string(&func1(string(&ref)[3]))[3];
// using typedef
using strarref = string(&)[3];
strarref func2(strarref in);
// using trailing return type syntax
auto func3(string(&ref)[3])->string(&)[3];

int lookup(int);
int lookup(int*);
int lookup(const int*);

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int add(int, int);
int sub(int, int);
int mul(int, int);
int divide(int, int);

vector <int> menFromBoys(vector <int> values);

//---------------------------------------------------------------------------------------//
int add(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}

int mul(int x, int y) {
	return x * y;
}

int divide(int x, int y) {
	if (y == 0)
		throw std::exception("Division by zero.");
	return x / y;
}

void f() {
	cout << "f() is called." << endl;
}

void f(int n) {
	cout << "f(int) is called. " << " n = " << n << endl;
}

void f(int n, int m) {
	cout << "f(int, int) is called. " << "numbers: " << n << ", " << m << endl;
}

void f(double x, double y) {
	cout << "f(double, double=3.14) is called. " << "numbers: " << x << ", " << y << endl;
}

// defined functions and classes
int lookup(int num) {
	cout << "First definition ";
	return num;
}

int lookup(int* ptr) {
	cout << "Second definition ";
	return *ptr;
}

int lookup(const int* num) {
	cout << "Third definition ";
	return *num;
}

string(&func1(string(&ref)[3]))[3]{

	return ref;
}

strarref func2(strarref in) {
	return in;
}

auto func3(string(&ref)[3])->string(&)[3]{
	return ref;
}

void recursivePrint(vector<int> list, int index) {
	auto size = list.size();
	if (size != 0 && index < size) {
		cout << list[index] << " ";
		recursivePrint(list, index + 1);
	}
}


const string& shorterString(const string& s1, const string& s2) {
	return s1.size() <= s2.size() ? s1 : s2;
}

int listSum(initializer_list<int> list) {
	int sum = 0;
	for (auto ele : list)
		sum += ele;
	return sum;
}

int compare(const int val, const int* ptr) {
	return val > * ptr ? val : *ptr;
}
int countVowel(string line) {
	int vcnt = 0;
	int ccnt = 0;
	int scnt = 0;

	for (auto ch : line) {
		switch (ch) {
		case 'a': case 'e': case 'i': case 'o': case 'u': ++vcnt; break;
		case ' ': ++scnt; break;
		default: ++ccnt;
		}
	}
	cout << "vowel: " << vcnt << " | " << "consona: " << ccnt << " | " << "space: " << scnt << endl;
	return vcnt;
}

unsigned int hotpo(unsigned int n) {
	if (n == 0 || n == 1) return 0;
	else if (n % 2 == 0) return hotpo(n / 2) + 1;
	else if (n % 2 != 0) return hotpo(3 * n + 1) + 1;
}

int addAdjacent() {
	string line;
	getline(cin, line);
	stringstream is(line);
	vector<int> numbers;
	int temp;
	while (is >> temp)
		numbers.push_back(temp);

	print(numbers);
	
	return 0;
}

string highestScoringWord(const string& str)
{
	auto lp1 = str.begin();
	auto rp1 = str.begin();
	auto lp2 = lp1;
	auto rp2 = rp1;
	auto maxl = lp1;
	auto maxr = lp2;
	int sum1 = 0;
	int sum2 = 0;
	while ((rp1 < str.end()) && (rp2 < str.end())) {
		cout << "*rp1: " << *rp1 << endl;
		while (*rp1 != ' ') {
			sum1 += (int(*rp1) - 96);
			++rp1;
		}
		lp2 = rp1 + 1;
		rp2 = lp2;
		while (*rp2 != ' ') {
			sum2 += (int(*rp2) - 96);
			++rp2;
		}
		if (sum2 > sum1) {
			lp1 = rp2 + 1;
			rp1 = lp1;
			sum1 = 0;
			maxl = lp2;
			maxr = rp2;
		}
		else {
			lp2 = rp2 + 1;
			rp2 = lp2;
			sum2 = 0;
			maxl = lp1;
			maxr = rp1;
		}
	}
	string res = "";
	for (auto i = maxl; i < maxr; i++)
		res.push_back(*i);
	return res;
}

string highandLow(const string& numbers) {
	stringstream ss(numbers);
	string temp;
	int max = -2147483647;
	int min = 2147483647;
	int number;
	while (ss >> temp) {
		if (temp != " ") {
			number = stoi(temp);
			if (number > max)
				max = number;
			if (number < min)
				min = number;
		}
	}
	return to_string(max) + " " + to_string(min);
}

int maxSequence(const vector<int>& arr) {
	int max_sum = 0;
	int sum = 0;
	for (auto ele : arr) {
		sum = sum > 0 ? sum + ele : ele;
		if (sum > max_sum)
			max_sum = sum;
	}
	return max_sum;
}

string balancedNum(unsigned long long int number)
{
	string numstr = to_string(number);
	int len = numstr.size();
	if (len < 3)
		return "Balanced";

	string left = numstr.substr(0, len / 2 - 1 + len % 2);
	string right = numstr.substr(len / 2 + 1, len - 1);
	
	return comparelr(left, right) ? "Balanced" : "Not Balanced";
}

bool comparelr(string left, string right) {
	int suml = 0;
	int sumr = 0;
	for (auto ch : left)
		suml += (int(ch) - 48);
	for (auto ch : right)
		sumr += (int(ch) - 48);
	cout << "suml: " << suml << " " << "sumr: " << sumr << endl;
	return suml == sumr;
}

vector<int> humanYearsCatYearsDogYears(int humanYears) {
	vector<int> res = { humanYears };
	int catYears = 15 * std::min(humanYears, 1) + 9 * std::min(humanYears - 1, 1) + 4 * max(humanYears - 2, 0);
	int dogYears = 15 * std::min(humanYears, 1) + 9 * std::min(humanYears - 1, 1) + 5 * max(humanYears - 2, 0);
	res.push_back(catYears);
	res.push_back(dogYears);
	return res;
}

string twoSort(vector<string> s)
{
	sort(s.begin(), s.end());
	string word = "";
	for (char ch : s.at(0)) {
		word.push_back(ch);
		word.append("***");
	}
	for (int i = 0; i < 3; i++)
		word.pop_back();
	return word;
}

string replace(const string& s)
{
	regex pattern("[aeiouAEIOU]");
	
	return regex_replace(s, pattern, "!");
}

class GapInPrimes
{
public:
	static pair <long long, long long> gap(int g, long long m, long long n) {

	}
};

bool isPrime(long long number) {
	for (long long i = 2; i < sqrtl(long double(number)); ++i)
		if (number % i == 0)
			return false;
	return true;
}

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
	int low = _min(split(numbers, " "));
	int high = _max(split(numbers, " "));
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

int _min(const vector<int>& list) {
	return *std::min_element(list.begin(), list.end());
}

int _max(const vector<int>& list) {
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

template <typename T>
void print(const pair<T, T>& p) {
	cout << "{";
	for (auto item : p)
		cout << "{" << p.first << "," << p.second << "} ";
}


class PartList
{
public:
	static vector<pair<string, string>> partlist(vector<string>& arr)
	{
		vector<pair<string, string>> result;
		auto combine = [](string a, string b) { return a + ' ' + b; };
		for (int i = 1; i < arr.size(); i++)
		{
			result.emplace_back(
				accumulate(arr.begin() + 1, arr.begin() + i, arr[0], combine),
				accumulate(arr.begin() + i + 1, arr.end(), arr[i], combine));
		}
		return result;
	}
};


vector<int> menFromBoys(vector<int> values)
{
	auto it = partition(begin(values), end(values), [](auto n) {return n % 2 == 0; });
	sort(begin(values), it);
	sort(it, end(values), greater<>());
	values.erase(unique(begin(values), end(values)), end(values));
	return values;
}

