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
std::sort(s.begin(), s.end(), [](const char& a, const char& b) { return a > b; });
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

