#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int solve(vector<int>& prices, int day, bool buy, vector<vector<int>>& dp) {
    if(day >= prices.size()) return 0;
    int profit = 0;

    if(dp[day][buy] != -1) { return dp[day][buy]; }

    if(buy) {  // buy at this point or not
      int take     = solve(prices, day + 1, false, dp) - prices[day];  // buy
      int not_take = solve(prices, day + 1, true, dp);  // not buy
      profit       = max({ profit, take, not_take });
    } else {  // we are selling
      // profit + a cooldown period and buy again
      int sell     = prices[day] + solve(prices, day + 2, true, dp);
      int not_sell = solve(prices, day + 1, false, dp);  // sell
      profit       = max({ profit, sell, not_sell });
    }

    return dp[day][buy] = profit;
  }

  int bottomup(vector<int>& prices) {
    int n = prices.size();

    vector<int> dp(n, 0);
    if(n == 0 || n == 1) return 0;

    dp[0] = 0;
    dp[1] = max(prices[1] - prices[0], 0);  // can go neg so;

    for(int i = 2; i < n; i++) {
      dp[i] = dp[i - 1];  // take of first

      // until today
      for(int j = 0; j < i; j++) {
        int prev_profit  = j >= 2 ? dp[j - 2] : 0;
        int today_profit = prices[i] - prices[j];
        dp[i]            = max(dp[i], today_profit + prev_profit);
      }
    }

    return dp[n - 1];
  }

public:
  int maxProfit(vector<int>& prices) {
    if(prices.size() <= 1) return 0;
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    return solve(prices, 0, true, dp);
  }
};
