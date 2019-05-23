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

