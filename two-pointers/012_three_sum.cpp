#include <bits/stdc++.h>
#include <vector>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  // solution is basically take the first one
  // sort em
  // then perform two sum with two pointer method on the other ones
  // also remember that if sorted the duplicates would be adjacent
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> sol;

    int n = nums.size();
    // 2 cause we would be iterating j and k
    for (int i = 0; i < n - 2; i++) {
      // skip the duplicate thing
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int l = i + 1;
      int r = n - 1;

      while (l < r) {
        // we see if the sum is zero or not
        int three_sum = nums[i] + nums[l] + nums[r];

        // the array is sorted so duplicate values are adjacent
        if (three_sum > 0) {
          r--;
        } else if (three_sum < 0) {
          l++;
        } else {
          sol.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
          l++;
          r--;

          // check for duplicates
          while (l < r && nums[l] == nums[l - 1])
            l++;
          while (l < r && nums[r] == nums[r + 1])
            r--;
        }
      }
    }

    return sol;
  }
};
