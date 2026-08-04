#include "../debugging.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  // to memoize you need 2d; why ? two values are changing
  // or use map and key i.to_string() + "_" + curr.to_string()
  int solve(int i, int currSum, vector<int>& nums, int target,
            vector<vector<int>>& dp, int offset) {

    // its end and we got the result
    if(i == nums.size()) return currSum == target;

    // but negative index ? we use total sum
    if(dp[i][currSum + offset] != -1) return dp[i][currSum + offset];

    int ways = 0;
    ways += solve(i + 1, currSum + nums[i], nums, target, dp, offset);  // add
    ways += solve(i + 1, currSum - nums[i], nums, target, dp, offset);  // sub

    return dp[i][currSum + offset] = ways;
  }

  // state definition: for i elements and j sum how many ways do we have
  int bottomup(vector<int>& nums, int target) {
    int total = accumulate(begin(nums), end(nums), 0);
    if(abs(target) > total) return 0;

    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, 0));

    dp[0][total] = 1;  // 0 elements 0 sum -> 1 way

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 2 * total; j++) {
        if(dp[i][j] == 0) continue;  // no ways for that

        // +x out of bounds check too ?
        if(j + nums[i] <= 2 * total) { dp[i + 1][j + nums[i]] += dp[i][j]; }
        if(j - nums[i] >= 0) { dp[i + 1][j - nums[i]] += dp[i][j]; }  // -x
      }
    }

    return dp[n][target + total];  // at last
  }

public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int total = accumulate(begin(nums), end(nums), 0);
    if(abs(target) > total) return 0;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * total + 1, -1));
    return solve(0, 0, nums, target, dp, total);
  }
};
