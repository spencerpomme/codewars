# C++ Notes For Python Programmers

This note is for Python programmers to pick up C++ in various daily tasks when writing code. You may want to get some basic understanding of C++ before reading this note.  Here are some suggested resources:

+ Udacity free course: [C++ for Programmers](https://classroom.udacity.com/courses/ud210)

+ C++ Primer 5th Edition (If you have a month or two)

+ Essential C++ (If you prefer learn as you go)

The above only listed a small fraction of all the good resources, so please feel free to follow your own favorite:smiley:

  

#### 1. Find min/max element in vector

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

Or you can also do:
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



