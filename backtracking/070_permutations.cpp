#include <bits/stdc++.h>
using namespace std;

// we don't need to pass idx here as we will always be taking all elems
// it's permutation so, also no same element twice, so set
// approach 2: using the swap
class Solution {
private:
  vector<vector<int>> sol;
  unordered_set<int> st;

  // basecase: temp.size >= nums.size
  void solve(vector<int> &nums, vector<int> &temp) {
    if (temp.size() >= nums.size()) {
      sol.push_back(temp);
      return;
    }

    // for all choices; we are starting from i
    for (int i = 0; i < nums.size(); i++) {
      // if it's duplicate continue
      if (st.count(nums[i]))
        continue;

      temp.push_back(nums[i]); // take
      st.insert(nums[i]);

      solve(nums, temp); // explore

      temp.pop_back(); // undo
      st.erase(nums[i]);
    }
  }

  // approach 2: using the swap technique
  // permutation is just swapping the positions of nums in array, so

public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> temp;
    solve(nums, temp);
    return sol;
  }
};
