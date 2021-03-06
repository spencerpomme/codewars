# C++ Notes For Python Programmers

This note is to help Python:snake: programmers who are not a **匠** of C++ to pick it up in various day to day tasks when needed. You may want to get some minimum understanding of language before diving in this note.  Here are some suggested resources:

+ Udacity free course: [C++ for Programmers](https://classroom.udacity.com/courses/ud210) :rocket:

+ C++ Primer 5th Edition (If you have a month or two :snail:) 

+ Essential C++ (If you prefer learn as you go​ :running:) 

The above only listed a small fraction of all the good resources, so please feel free to follow your own favorite! :cowboy_hat_face:

 

#### 1. Find min/max element in a collection

This task is absurdly trivial in Python:

```python
# use list as vector equivalence:
ls = [1,2,3,4,5]
min_ele = min(ls)
max_ele = max(ls)
```

In C++ you can:

```c++
// not using sort
#include <vector>
#include <algorithm>

int findSmallest(const std::vector<int>& list) { 
	return *std::min_element(list.begin(), list.end());
}
```

Or you can also do this:
```c++
// using sort
#include <vector>
#include <algorithm>
using namespace std;

int findSmallest(vector <int> list) {
	sort(list.begin() , list.end());
	return list[0];
}
```



#### 2. Make sub string

In Python :

```python
string = "What a good day today, let's go for a walk!"
sub = string[7:15]
# >>> "good day"
```

In C++ it can be a little bit tedious:

```c++
#include <string>
using namespace std;
// remove first and last element in the string:
string sliceString (string str) {
	return str.substr(1, str.length()-2);
}
```

The difference between `str.size() `and `str.length` see [here](<https://stackoverflow.com/questions/905479/stdstring-length-and-size-member-functions>).



#### 3. Split string given a delimiter

In Python it is really easy:

```python
string = "abc|def|ghi|jkl"
subs = string.split("|")
# >>> ['abc', 'def', 'ghi', 'jkl']
```

In C++ you can write this functionality yourself:

```c++
// The hard way
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string& str, string delimiter) {
	vector<string> res;
	string::size_type posl = 0;
	string::size_type posr = str.find(delimiter);
	string token = str.substr(posl, posr);
	res.push_back(token);
	while (posr != string::npos) {
		posl = posr;
		posr = str.find(delimiter, ++posr);
		res.push_back(str.substr(posl, posr));
	}
	return res;
}
```

There's also a smart way to do this when in the special case which delimiter is white space using **string stream**:

```c++
// A smarter way
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(const string& str, string delimiter){
	stringstream ss(str);
    string temp;
	vector<string> res;
	while (ss >> temp) {
		if (temp != delimiter)
            res.push_back(temp);
    };
    return res;
}
```



#### 4. String to number and vise versa

In Python this operation is very intuitive:

```python
# string -> number
int_str = "100"
number_int = int(int_str)
number_float = int("4.24")

# number -> string
string_num = str(123456)
```

Python does all the underlying type conversions for you and protects you from psychological burdens such as remembering  abbreviated function names:

```c++
// String <-> number conversion in C++
#include <iostream>
#include <string>

using std::string;

int main() {
    string integer = "100";
    string realnum = "123.456";
    string lli = "1234567891234567";
    // string to number
    int numi = std::stoi(integer);
    float numf = std::stof(realnum);
    long long int numlli = std::stoll()
    
    // number to string
    int number = 10;
    int fnum = 10.11;
    string snum = to_string(number);
    string sfnm = to_string(fnum);
    
    return 0;
}
```

Consult [stoi](http://www.cplusplus.com/reference/string/stoi/) , [stof](http://www.cplusplus.com/reference/string/stof/)  and [to_string](<http://www.cplusplus.com/reference/string/to_string/>) definitions for other use cases. 

Apart from those, there are in fact a whole family of conversion functions, most of them (if not all of them) provide pointer argument for further manipulation.  Search for more info [here](<http://www.cplusplus.com/reference/>).



#### 5. Obtain an unduplicated collection (List/Vector)

To achieve this in Python you can convert the list to a set then convert back:

```python
dup = [1, 1, 3, 4, 4, 5]
unq = list(set(dup))
print(unq)
# >>> [1, 3, 4, 5]
```

In C++ similar manipulation can be done too:

```c++
#include <set>
#include <vector>

using std::set;
using std::vector;

int main() {
    vector<int> v{1, 1, 2, 3, 4, 4, 4, 5};
    set<int> s(v.begin(), v.end());
    
    return 0;
}
```



#### 6. Get type of a value

In Python you can use the `type` function:

```python
val = 3
print(type(val))
# >>> int
```

In C++ is also very simple:

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Harry Potter";
    cout << "Name " << name << " is of type " << typeid(name).name() << endl;
    
    return 0;
}
// >>> class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
```

You can see that the readability of the C++ version of 'type' is awful.  But indeed, **string in C++ is a template instead of a type**. If try with built-in types, then:

```c++
int value = 3;
cout << typeid(value).name();
// >>> int
```



#### 7. String upper and lower

In Python:

```python
s = "abc"
S = s.upper()
# >>> "ABC"
s = S.lower()
# >>> "abc"
```

In C++ you need to modify at character level:

```c++
#include <string>

using std::string;
int main() {
    string s = "abcdefghijklmn";
	
	for (string::iterator ic = s.begin(); ic < s.end(); ++ic) {
		*ic = toupper(*ic);
	}
}
```

Another more compact way of doing this is :

```c++
#include <algorithm>
#include <string> 
using std::string;

string data = "Abc"; 
transform(data.begin(), data.end(), data.begin(), tolower);
```



#### 8. Sort a collection

In Python:

```python
ls = [1,5,7,2,9,4]
new_ls = sorted(ls, reverse=False)
# new_ls: [1,2,4,5,7,9]
# or inplace sort:
ls.sort(reverse=True)
# ls = [9, 7, 5, 4, 2, 1]
```

In C++ we can do the similar:

```c++
// s could be any sequence, e.g. string, vector, set, etc.
// default sort ordering is ascending, provide a compare object if need descend ordering
#include <algorithm>
std::sort(s.begin(), s.end(), [](const type& a, const type& b) { return a > b; });
```



#### 9. String Replace

In Python:

```python
dna = "ACTGACTGGAACCTGACTA"
rna = dna.replace("T", "U")
```

In C++ is equally simple:

```c++
#include <string>
using std::string;

int main()
{
	string dna = "ATCGATCG";
	replace(dna.begin(), dna.end(), 'T', 'U');
	return 0;
}
```



#### 10. Accumulate sum of a collection

In Python you can use functional tool:

```python
from functools import reduce

ls = [1,2,3,4,5,6,7,8,9,10]
sum_ls = reduce(lambda x,y: x+y, ls)
```

In C++ there's also a similar functionality:

```c++
#include <vector>
#include <numeric>
using namespace std;

int positive_sum (const vector<int> arr){
  return accumulate(arr.begin(), arr.end(), 0, [](int a, int b) {return a + b;});
}
```

The C++ solution also used lambda, and the accumulate can serve as similar goal in this scenario. But again, Python code is more terse.



#### 11. Sub-string

In Python:

```python
s = "string"
sb = s[2:4] # >>> "ri"
sb = s[:3]  # >>> "str"
sb = s[3:]  # >>> "ing"
```

In C++  you need this function:

```c++
#include <string>
string input = "string";
input.substr(size/2-1, 2); // get the middle two
```



#### 12. Vector indexing reverse iteration

In Python indexing is easy. But in C++ there are many ways to do it:

```c++
#include <vector>

// reverse iterate
std::vector<int> evenNumbers(std::vector<int> arr, int n) {
    std::vector<int> res = {};
    for (std::vector<int>::iterator it = arr.end()-1; n > 0; --it)
        if (*it % 2 == 0) {
            res.insert(res.begin(), *it);
            --n;
        }
    return res;
}
```



#### 13. Get first and last element of string

In Python just `s[0] ` and `s[-1]` are good enough. In C++ there are many ways doing it. One possible way is:

```c++
s.front();
s.back();
```

The above two get char instead of string.



#### 14. Another way to iterate over a vector

Instead of using iterator, you can use a syntax sugar like this:

```c++
for (auto x: vec) {
    ...
}
```



#### 15. Count number of element

In Python you can count like this:

```python
ls = [1,1,1,1,3,3,3,4]
ls.count(1)
# >>> 4
```

In C++ this operation is trivial too:

```c++
#include <algorithm>
#include <vector>

int count_sheep(std::vector<bool> v) {
  return std::count(v.cbegin(), v.cend(), true);
}
```



#### 16. Direct modify a string

In Python string is immutable hence cannot be modified in place. In C++, you can:

```c++
#include <string>

std::string correct(std::string str) {
    for (auto &ch : str) {
        switch (ch) {
            case '5': ch = 'S';
            break;
            case '0': ch = 'O';
            break;
            case '1': ch = 'I';
            break;
        }
    }
    return str;
}
```

Just use a reference will do.



#### 17. Absolute value

In Python `abs` is a built-in function, in C++ you have to include a library named `<cmath>`:

```c++
#include <cmath>

abs(someNumber);
```



#### 18. Mutate elements in a collection

Python has a handy `map` built in function. In C++ though, you can use:

```c++
#include <vector>
#include <algorithm>

std::vector<int> invert(std::vector<int> values)
{
    transform(values.begin(), values.end(), values.begin(), std::negate<int>());;
    return values;
}
```



#### 19. Calculate average of a list of numbers

In Python you can:

```python
ls = [1,2,3,4,5,6]
average = sum(ls) / len(ls)
```

In C++ you'll need to do this:

```c++
#include <vector>
#include <numeric>
vector<int> ls = {1,2,3,4,5,6};

double average = std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
```



#### 20. Use Regular Expression in C++

In Python if you want to use regex you'll need to import the [re](<https://docs.python.org/3/library/re.html>) library:

```python
import re
```

In C++ there is a similar library named [regex](<http://www.cplusplus.com/reference/regex/>):

```c++
#include <string>
#include <regex>
using namespace std;

string fakeBin(string str){
	str = regex_replace(str, regex("[1234]"), "0");
	str = regex_replace(str, regex("[56789]"), "1");
	return str;
}
```



#### 21. Decimal to binary

In Python, it's again ridiculously easy:

```python
deci = 10
bina = bin(deci)
bina = 0b1111
deci = int(bina)
```

In C++ you have to do it manually:

```c++

```



#### 22. Round float to decimal places

In Python:

```python
round(2.333333333, 2)
# >>> 2.33
```

In C++:

```c++
#include <cmath>
using std::round

round(2.333333 * 100) / 100;
// >>> 2.33
```



#### 23. Function `min` and `max`  (C++ version)

Consider the following scenario:

```python
bigger = max(10, 2)
```

In C++ you just need to include algorithm library:

```c++
#include <algorithm>

int bigger = std::max(10, 2);
```



#### 24. Join strings in a vector into one string

There are scenarios you'd like to do this:

```c++
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
```



#### 25. Dynamic Planning (simplest example)

Consider a [problem](<https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c>). The solution could simply be in O(n):

```c++
#include <vector>

using namespace std;

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
```



#### 26. Vector element membership check

```c++
const bool is_in = std::find(vec.begin(), vec.end(), element) != vec.end();
```

Very simple.



#### 27. Vector Partition According to a criterion

See an example from [this problem](https://www.codewars.com/kata/sort-out-the-men-from-boys-1/cpp). The best practice is shown below:

```c++
#include <functional> // greater
#include <vector>
#include <algorithm> // sort, unique

std::vector<int> menFromBoys(std::vector<int> values)
{
    auto it = std::partition(begin(values), end(values), [](auto n) {return n % 2 == 0;});
    std::sort(begin(values), it);
    std::sort(it, end(values), std::greater<>());
    values.erase(std::unique(begin(values), end(values)), end(values));
    return values;
}
```



#### 28. Handle IO get line

Sometimes in C++ we want a kind of command line interaction that each line input is a record and flushed by an enter. This process continues until an empty line is entered. For the simplest example, where we don't consider type check or corner cases like that, is not as simple as you might expect:

```c++
while (true) {
		// the simplest event loop :)
		string cat;
		getline(cin, cat);
		if (cat != "")
			cout << "cat is named: " << cat << endl;
		else
			break;
	}
```



#### 29. Operator Overloading

In C++ and Python, operator behaviour can be redefined to better suit the purpose of classes. 

```c++
// a simple example
class Sapien {
private:
	int age;
public:
	Sapien(int age) : age(age) {}
	int getAge() const { return age; }
};

bool operator==(const Sapien& a, const Sapien& b) {
	return a.getAge() == b.getAge();
}

bool operator!=(const Sapien& a, const Sapien& b) {
	return a.getAge() != b.getAge();
}

bool operator<=(const Sapien& a, const Sapien& b) {
	return a.getAge() <= b.getAge();
}

bool operator>=(const Sapien& a, const Sapien& b) {
	return a.getAge() >= b.getAge();
}

bool operator<(const Sapien& a, const Sapien& b) {
	return a.getAge() < b.getAge();
}

bool operator>(const Sapien& a, const Sapien& b) {
	return a.getAge() > b.getAge();
}
```



#### 30. Read File

```c++
#include <fstream> // header file needed
#include <string>
using std::ifstream; // in file stream
using std::string;

int main() {
    string path = "./to_be_loaded.csv"
    ifstream file(path);
    if (file) {
    string line;
    while (getline(myfile, line)) {
      // ...do something...
    }
  }
}
```

