#include "cache.hpp"
#include "solution.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	
	LRUCache* cache = new LRUCache(2);

	cache->put(1, 1);
	cache->put(2, 2);
	cout << cache->get(1) << endl;;      // returns 1
	cache->put(3, 3);                    // evicts key 2
	cout << cache->get(2) << endl;       // returns -1 (not found)
	cache->put(4, 4);                    // evicts key 1
	cout << cache->get(1) << endl;       // returns -1 (not found)
	cout << cache->get(3) << endl;       // returns 3
	cout << cache->get(4) << endl;       // returns 4

	vector<int> node{ 1,2,3,4 };
	print(node);
	vector<vector<int>> nodes;
	nodes.push_back(node);
	for (auto node : nodes) {
		print(node);
	}

	return 0;
}
