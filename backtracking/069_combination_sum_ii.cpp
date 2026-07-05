#include <bits/stdc++.h>
using namespace std;

// handle duplicate via sorting and filtering
class Solution {
private:
  vector<vector<int>> sol;

  // base: when target == 0, idx == target; target < 0
  // states: temp~ans, target, idx -for loop
  // when you get answer: when sum becomes 0
  void solve(vector<int> &candidates, vector<int> &temp, int idx, int target) {

    if (target < 0)
      return;

    if (target == 0) {
      sol.push_back(temp);
      return;
    }

    // for all choices
    for (int i = idx; i < candidates.size(); i++) {
      // filter them; out of bound check what happens when i = 0?
      if (i > idx && candidates[i] == candidates[i - 1])
        continue;

      // if already greater than target we cannot find cause its sorted
      if (candidates[i] > target)
        break;

      temp.push_back(candidates[i]); // take it

      // explore all; you cannot take same elem twice so i + 1
      solve(candidates, temp, i + 1, target - candidates[i]); // decrease sum
      temp.pop_back();                                        // untake it
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<int> temp;

    // sort it
    sort(begin(candidates), end(candidates));

    solve(candidates, temp, 0, target);
    return sol;
  }
};
