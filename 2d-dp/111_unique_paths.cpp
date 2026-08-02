#include <bits/stdc++.h>
using namespace std;

/** Grid based question **/
class Solution {
private:
  // recursive exponential
  // T.C. O(m * n)  S.C. O(m * n)
  int solve(int i, int j, int m, int n, vector<vector<int>>& dp) {
    // base case if at the end
    if(i == m - 1 && j == n - 1) { return 1; }
    if(dp[i][j] != -1) return dp[i][j];

    auto isSafe = [&](int i, int j) {
      if(i < 0 || j < 0 || i >= m || j >= n) return false;
      return true;
    };

    if(!isSafe(i, j)) { return 0; }

    int right       = solve(i, j + 1, m, n, dp);
    int left        = solve(i + 1, j, m, n, dp);
    return dp[i][j] = left + right;
  }

  /**
   * state definition: t[i][j] ways to reach t[i][j] by t[0][0]
   * usually the first row and first col are base cases
   *
   * which neighbor cell affects i, j here it's top and left (right and down ?)
   * T.C. O(m * n)  S.C. O(m * n)
   */
  int bottomup(int m, int n, vector<vector<int>>& dp) {
    dp[0][0] = 0; // this is according to question from 0, 0 to 0, 0

    for(int col = 0; col < n; col++) {
      dp[0][col] = 1;  //  first row
    }

    for(int row = 0; row < m; row++) {
      dp[row][0] = 1;  // first col
    }

    for(int i = 1; i <= m; i++) {
      for(int j = 1; j <= n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];  // top and left
      }
    }

    return dp[m - 1][n - 1];
  }

public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solve(0, 0, m, n, dp);
  }
};
