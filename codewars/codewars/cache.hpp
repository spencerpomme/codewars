#pragma once
#include <map>
#include <queue>
#include <stdexcept>

using std::map;
using std::pair;
using std::queue;


class LRUCache {
public:
	LRUCache() = default;
	LRUCache(int capacity) : cap(capacity), cnt(0), dict(), q() {}

	int get(int key) {
		try {
			int val = dict.at(key);
			put(key, val);
			return val;
		}
		catch (std::out_of_range) {
			return -1;
		}
	}

	void put(int key, int value) {
		if (dict.find(key) == dict.end() && cnt >= cap) {
			auto poped = q.front();
			q.pop();
			dict.erase(poped);
			--cnt;
		}
		q.push(key);
		dict[key] = value;
		++cnt;
	}
private:
	int cap = 0;
	int cnt = 0;
	map<int, int> dict;
	queue<int> q;
};