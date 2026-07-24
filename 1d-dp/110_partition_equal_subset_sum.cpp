#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

/**
 * solve(i, x) =
 *      solve(i + 1, x)                    // don't take nums[i]
 *|     solve(i + 1, x - nums[i])          // take nums[i]
 */
class Solution {
private:
  // memoized: take if sum becomes 0 or if present in dp
  // else take and notTake and return ||
  bool solve(vector<int>& nums, int x, int i, vector<vector<int>>& dp) {
    if(i >= nums.size()) return false;

    if(x == 0) return true;
    if(dp[x][i] != -1) return dp[x][i];

    bool take = false;
    if(nums[i] <= x) { take = solve(nums, x - nums[i], i + 1, dp); }

    bool skip = solve(nums, x, i + 1, dp);

    // any one because other has to be >> 1 check
    return dp[x][i] = take || skip;
  }

  // approach 2 knapsack bottomup
  // why knapsack why not greedy ? because options - recursive
  // t[i][j] = is it possible to get subset of sum j having i number of elem
  bool isSubsetSum(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // first col true - base case
    for(int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }

    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= sum; j++) {
        bool skip = dp[i - 1][j];
        bool take = false;
        if(nums[i - 1] <= j) { take = dp[i - 1][j - nums[i - 1]]; }

        dp[i][j] = take || skip;
      }
    }

    return dp[n][sum];
  }

  // TODO: space optimized - see knapsack 0/1

public:
  bool canPartition(vector<int>& nums) {
    int s = accumulate(begin(nums), end(nums), 0);
    if(s & 1) return false;

    int n = nums.size();
    int t = s >> 1;

    vector<vector<int>> dp(t + 1, vector<int>(n, -1));  // x is the sum so
    return solve(nums, t, 0, dp);
  }
};
