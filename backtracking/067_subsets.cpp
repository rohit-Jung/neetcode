#include <bits/stdc++.h>
using namespace std;

// since it's subsets and exploration we must backtrack
// take the element and explore and undo it
// base case: if i exceeds the size(); know this better by recursive tree
class Solution {
private:
  vector<vector<int>> sol;
  void backtrack(vector<int> &nums, vector<int> temp, int idx) {
    // every recursive node is a valid subset
    sol.push_back(temp);

    // for all choices; for loop is the basecase itself idx == nums.size()
    for (int i = idx; i < nums.size(); i++) {
      temp.push_back(nums[i]);      // choose
      backtrack(nums, temp, i + 1); // recurse
      temp.pop_back();              // unchoose
    }
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> temp;
    backtrack(nums, temp, 0);
    return sol;
  }
};
