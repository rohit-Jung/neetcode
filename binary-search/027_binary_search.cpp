#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    /// pick the pointers
    int s = 0, e = nums.size() - 1;

    // search while they crosses
    // interval is inclusive so <= (equal to)
    while (s <= e) {

      // prevents overflow
      int mid = s + (e - s) / 2;
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] > target) {
        e = mid - 1;
      } else {
        s = mid + 1;
      }
    }

    return -1;
  }
};
