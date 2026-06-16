#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (i < j) {
      int sum = numbers[i] + numbers[j];

      if (sum == target) {
        // its one based indexing the question says you are dumb
        return vector<int>{i + 1, j + 1};
      }

      // because the bigger number is at back
      sum > target ? j-- : i++;
    }

    return vector<int>{0, 0};
  }
};
