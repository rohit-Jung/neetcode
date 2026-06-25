#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class TimeMap {
public:
  // map of "key" -> [[value, timestamp]]
  unordered_map<string, vector<pair<string, int>>> timeMap;
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    // check for exists | empty vector is automatically created
    timeMap[key].push_back({value, timestamp});
  }

  string get(string key, int timestamp) {
    // check for exists
    string result = "";

    // vector<pair<string, int>> vals = timeMap[key];

    // auto is for easiness and & because we don't want to create a copy (if
    // thousands of vals)
    auto &vals = timeMap[key];

    // binary search over
    int lo = 0;
    int hi = vals.size() - 1;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      // go towards higher
      if (vals[mid].second < timestamp) {
        // lo can be answer
        result = vals[mid].first;
        lo = mid + 1;
      } else if (vals[mid].second > timestamp) {
        hi = mid - 1;
      } else {
        result = vals[mid].first;
        break;
      }
    }

    return result;
  }
};
