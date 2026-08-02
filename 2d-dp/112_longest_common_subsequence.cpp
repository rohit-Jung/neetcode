#include <bits/stdc++.h>
using namespace std;

/* DP on strings: a type of Dp
 *
 * repeating sub problems, optimal (longest)
 * */
class Solution {
private:
  /* O(m * n)
   * */
  int solve(int i, int j, string text1, string text2, vector<vector<int>>& dp) {
    if(i >= text1.size() || j >= text2.size()) { return 0; }
    if(dp[i][j] != -1) return dp[i][j];

    if(text1[i] == text2[j])
      return dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2, dp);

    return dp[i][j] = max(solve(i + 1, j, text1, text2, dp),
                          solve(i, j + 1, text1, text2, dp));
  }

  /* state definition dp[i][j] at [i][j] postion how many subsequence can be
     formed with s1 length of and s2 length of j
   */
  int bottomup(string text1, string text2) {
    int n = text2.size();
    int m = text1.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    // first row and first col as zero
    // any one's length is zero case
    for(int row = 0; row < m + 1; row++) {
      dp[row][0] = 0;
    }

    for(int col = 0; col < n + 1; col++) {
      dp[0][col] = 0;
    }

    for(int i = 1; i < m + 1; i++) {
      for(int j = 1; j < n + 1; j++) {
        if(text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[m][n];
  }

public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text2.size();
    int m = text1.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solve(0, 0, text1, text2, dp);
  }
};
