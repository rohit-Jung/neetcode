#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  // find the pivot ? the element right next to pivot is the  min
  int findMin(vector<int> &nums) {
    // [3,4,5,6,1,2]
    int lo = 0;
    int hi = nums.size() - 1;

    // its not rotated; if rotated enough it reaches the original state
    if (nums[lo] <= nums[hi])
      return nums[lo];

    // find pivot
    while (lo <= hi) {
      // find mid
      int mid = lo + (hi - lo) / 2;

      // this is pivot condition
      // mistake; dont' mix up index and val

      // checking when mid falls on two conditions
      if (mid < hi && nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
      }

      if (mid > lo && nums[mid - 1] > nums[mid]) {
        return nums[mid];
      }

      // binary search
      if (nums[lo] <= nums[mid]) {
        // we are in increasing part of array
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    return -1;
  }

  int findMin2(vector<int> &nums) {
    int lo = 0;
    int hi = nums.size() - 1;

    // its not rotated or rotated enough then lo is the min
    if (nums[lo] <= nums[hi])
      return nums[lo];

    // this works cause we are shrinking the search space to low - high
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      // we are in increasing part of array
      if (nums[lo] <= nums[mid]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    return nums[lo];
  }
};
