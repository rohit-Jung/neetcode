#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<vector<int>> sol;

  void solve(vector<int> &nums, vector<int> &temp, int idx) {
    sol.push_back(temp);

    //  for all choices
    for (int i = idx; i < nums.size(); i++) { // base case i == nums.size()
      // duplicate filtering skip if same
      if (i > idx && nums[i] == nums[i - 1])
        continue;

      temp.push_back(nums[i]);  // take it
      solve(nums, temp, i + 1); // we don't take the same again?
      temp.pop_back();          // pop back
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> temp;

    // for duplicate filtering
    sort(begin(nums), end(nums));

    solve(nums, temp, 0);
    return sol;
  }
};
