#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  // complement pattern
  vector<int> twoSum(vector<int> &nums, int target) {
    // you go through the array and also maintain what you need to meet the
    // target simulatneously when you find that requirement you return the
    // solution

    // get which index needs what to fulfill
    // map 4 -> required by index 0
    unordered_map<int, int> required;
    for (int i = 0; i < nums.size(); i++) {
      int want = target - nums[i];

      // is current number needed by anyone in map to complete
      if (required.find(nums[i]) != required.end())
        return vector<int>{required[nums[i]], i};

      required[want] = i;
    }

    return vector<int>{0, 0};
  }
};
