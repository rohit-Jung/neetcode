#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
  // TODO: try doing with custom DLL too

  // maintain a dll for actual cache
  list<int> dll;
  // map [key, [address, value]] for O(1) access
  map<int, pair<list<int>::iterator, int>> mp;

  // capacity
  int n;

  LRUCache(int capacity) { n = capacity; }

  void updateRecentlyUsed(int key) {
    // clear it from dll cause we are gonna update it
    dll.erase(mp[key].first);

    // put that in front
    dll.push_front(key);
    mp[key].first = dll.begin();
  }

  int get(int key) {
    // check if the key  exist
    if (mp.find(key) == mp.end()) {
      return -1;
    }

    // update to recently used and return val;
    updateRecentlyUsed(key);
    return mp[key].second;
  }

  void put(int key, int value) {
    // if it exist update the value;
    if (mp.find(key) != mp.end()) {
      mp[key].second = value;
      updateRecentlyUsed(key);
      return;
    }

    dll.push_front(key);
    mp[key] = {dll.begin(), value};

    if (mp.size() > n) {
      // get back and remove it that's least recently used
      int old = dll.back();
      dll.pop_back();
      mp.erase(old);
    }
  }
};
