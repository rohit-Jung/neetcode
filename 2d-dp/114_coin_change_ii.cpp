#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  // returns no of  ways of getting amount using coins
  int solve(int amount, vector<int>& coins, int i, vector<vector<int>>& dp) {
    if(amount == 0) return 1;  // 1 way since you have reached 0
    if(i >= coins.size()) return 0;
    if(dp[i][amount] != -1) { return dp[i][amount]; }

    if(amount < coins[i]) {
      return dp[i][amount] = solve(amount, coins, i + 1, dp);
    }

    // you can retake the coin so
    int take = solve(amount - coins[i], coins, i, dp);
    int skip = solve(amount, coins, i + 1, dp);  // move to next

    return dp[i][amount] = take + skip;
  }

  int bottomup(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1);
    dp[0] = 1; // only one way to make amount 0: use no coins

    for (int coin: coins) { // update the dp array 
      for (int j = coin; j<=amount; j++) { // 
        dp[j] += dp[j - coin];
      }
    }

    return dp[amount];
  }

  // todo: 2d dp

public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
    return solve(amount, coins, 0, dp);
  }
};
