#include <bits/stdc++.h>
using namespace std;

// solve; backtrack decrease the sum on each call with relevant one
// base is when the target == 0; or target goes to negative
class Solution {
private:
  vector<vector<int>> result;

  void backtrack(vector<int> &nums, int target, int idx, vector<int> &temp) {
    if (target < 0)
      return;
    // if target is zero; we got the answer
    if (target == 0) {
      result.push_back(temp);
      return;
    }

    // for all choices
    // idx == nums.size() handled by the loop
    for (int i = idx; i < nums.size(); i++) {
      temp.push_back(nums[i]); // take it
                               // expl0re with target reduced

      // i or i+1 depends on are you allowed to reuse the element
      // in combination sum yes so i
      backtrack(nums, target - nums[i], i, temp);
      temp.pop_back(); // untake it
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &nums, int target) {
    vector<int> temp;
    backtrack(nums, target, 0, temp);
    return result;
  }
};
