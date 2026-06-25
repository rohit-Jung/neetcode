#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  // we would be shrinking
  int search(vector<int> &nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      if (nums[mid] == target) {
        return mid;
      }

      // conditions
      // left part
      if (nums[lo] <= nums[mid]) {
        // can we search in between lo and mid { lo -> 1 2.. 3 <- mid}
        if (nums[lo] <= target && target < nums[mid]) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      } else {
        // right part
        // can we search in between mid and hi { mid -> 1 2...3 <- hi}
        if (nums[mid] < target && target <= nums[hi]) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
    }

    return -1;
  }
};
