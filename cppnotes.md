# C++ Notes

#### Find min/max element in vector

```c++
// not using sort
#include <vector>
#include <algorithm>

int findSmallest(const std::vector<int>& list) { 
	return *std::min_element(list.begin(), list.end());
}
```

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

#### Make sub string

```c++
#include <string>
using namespace std;
// remove first and last element in the string:
string sliceString (string str) {
	return str.substr(1, str.length()-2);
}
```

The difference between `str.size() `and `str.length` see [here](<https://stackoverflow.com/questions/905479/stdstring-length-and-size-member-functions>).