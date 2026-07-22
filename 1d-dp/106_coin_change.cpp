#include "../debugging.h"
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/* Greedy doesn't work on this | minimum
 *
 * make an dp array of size amount+1, with any arbitary value not below amount
 * go through amount times, for dp[0] min ways is 0
 *
 * then for dp[i], min would be its value or 1 + dp[coinVal - i]
 * */
class Solution {
private:
  // bottom up approach O(amount * coins) O(amount)
  int bottomUp(vector<int>& coins, int amount) {
    vector<int> dp(amount + 2, amount + 1);
    dp[0] = 0;

    for(int i = 1; i < amount; i++) {
      for(int coin : coins) {
        if(coin - i >= 0) {
          dp[i] = min(dp[i], 1 + dp[coin - i]);  // recurrance relation
        }
      }
    }

    return dp[amount] != amount + 1 ? dp[amount] : -1;
  }

  // top down approach O(amount * coins) O(amount)
  int solve(vector<int>& coins, int amount, vector<int>& memo) {
    if(amount == 0) return 0;
    if(amount < 0) return INT_MAX;
    if(memo[amount] != -1) return memo[amount];

    int minCoins = INT_MAX;
    for(int coin : coins) {
      int res = solve(coins, amount - coin, memo);
      if(res != INT_MAX) { minCoins = min(minCoins, res + 1); }
    }

    memo[amount] = minCoins;
    return minCoins;
  }

public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> memo(amount + 1, -1);
    int res = solve(coins, amount, memo);
    return res == INT_MAX ? -1 : res;
  }
};

int main(int argc, char* argv[]) {
  vector<int> coins = { 1, 5, 10 };
  int amount        = 12;
  Solution sol {};
  cout << sol.coinChange(coins, amount) << "\n";

  return 0;
}
