#include "../../debugging.h"
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  int solve(int n, vector<int>& v, vector<int>& wt, int c,
            vector<vector<int>>& dp) {
    if(n <= 0 || c == 0) { return 0; }  // base case
    if(dp[n][c] != -1) return dp[n][c];

    int take = 0;
    if(wt[n - 1] <= c) {  // can we take it
      take = v[n - 1] + solve(n - 1, v, wt, c - wt[n - 1], dp);
    }

    int skip        = solve(n - 1, v, wt, c, dp);
    return dp[n][c] = max(take, skip);
  }

public:
  using t = tuple<int, int, double>;

  // this is not dp (greedy): but a kind of knapsack
  double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    // profit per weight vect
    int n = val.size();
    vector<t> perWeight(n);

    for(int i = 0; i < val.size(); i++) {
      perWeight[i] = { val[i], wt[i], (double)val[i] / wt[i] };
    }

    // compare the per weight
    auto cmp = [](t& p1, t& p2) { return get<2>(p1) > get<2>(p2); };
    sort(perWeight.begin(), perWeight.end(), cmp);

    double result = 0.0;
    // take decrease capacity
    for(auto& [v, w, r] : perWeight) {
      if(w <= capacity) {
        result += v;  // add the value to result
        capacity -= w;
      } else {
        // take fraction if wt is not less or equal
        result += r * capacity;
        capacity = 0;
        break;
      }
    }
    return result;
  }

  int knapsackRecursive(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return solve(n, val, wt, W, dp);
  }

  // T.C - O(n * W)
  // S.C - O(n * W)
  int knapsackBottomUp(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // fill in the dp table { 0th row and col already has 0}
    // they are teh base cases with no weight and no value
    for(int i = 1; i < n + 1; i++) {    // number of items
      for(int j = 1; j < W + 1; j++) {  // weight of knapsack
        int take = 0;
        if(wt[i - 1] <= j) { take = val[i - 1] + dp[i - 1][j - wt[i - 1]]; }

        int skip = dp[i - 1][j];
        dp[i][j] = max(take, skip);
      }
    }

    return dp[n][W];
  }

  // S.C - O(W)
  int knapsackBottomUpSpaceOptimized(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();

    vector<int> prev(W + 1, 0);  // previous row dp[i - 1]
    vector<int> curr(W + 1, 0);  // current row dp[i]

    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= W; j++) {
        int take = 0;
        if(wt[i - 1] <= j) {
          // take = val[i -1 ] + dp[i - 1][j - wt[i - 1]]
          take = val[i - 1] + prev[j - wt[i - 1]];
        }

        // skip -> dp[i - 1][j]]
        int skip = prev[j];

        // dp[i][j] = max(take, skip)
        curr[j] = max(take, skip);
      }

      prev = curr;
    }

    return curr[W];
  }
};

int main() {
  Solution sol {};
  vector<int> val = { 1, 2, 3 };
  vector<int> wt  = { 4, 5, 1 };
  sol.knapsackBottomUp(4, val, wt);
}
