#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  // allowed actions delete, replace, insert
  // T.C 3^m+n without memo with Memo (m * n)
  int solve(int i, int j, string& word1, string& word2,
            vector<vector<int>>& dp) {
    if(i == word1.size()) {
      return word2.size() - j;  // insert em
    }

    if(j == word2.size()) {
      return word1.size() - i;  // delete em
    }

    if(dp[i][j] != -1)
      return dp[i][j];

    // match so skip
    if(word1[i] == word2[j])
      return dp[i][j] = solve(i + 1, j + 1, word1, word2, dp);

    // we are allowed to do three operations
    int deleteOp  = 1 + solve(i + 1, j, word1, word2, dp);
    int insertOp  = 1 + solve(i, j + 1, word1, word2, dp);
    int replaceOp = 1 + solve(i + 1, j + 1, word1, word2, dp);

    return dp[i][j] = min({ deleteOp, insertOp, replaceOp });
  }

  int solveBackwards(int m, int n, string word1, string word2,
                     vector<vector<int>>& dp) {
    {
      if(m == 0 || n == 0) {
        return m + n;  // either case is exhausted
      }

      if(dp[m][n] != -1)
        return dp[m][n];

      if(word1[m - 1] == word2[n - 1]) {
        return dp[m][n] = solve(m - 1, n - 1, word1, word2, dp);
      } else {
        int deleteOp  = 1 + solve(m - 1, n, word1, word2, dp);
        int insertOp  = 1 + solve(m, n - 1, word1, word2, dp);
        int replaceOp = 1 + solve(m - 1, n - 1, word1, word2, dp);

        return dp[m][n] = min({ deleteOp, insertOp, replaceOp });
      }

      return -1;
    }
  }

  // dp[i][j] = minimum operations to make word1[i...] to word2[j...]
  int bottomup(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for(int i = 0; i <= m; i++) {
      for(int j = 0; j <= n; j++) {
        if(i == 0 || j == 0) {
          dp[i][j] = i + j;  // base case
        } else if(word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          int deleteOp  = 1 + dp[i - 1][j];
          int insertOp  = 1 + dp[i][j - 1];
          int replaceOp = 1 + dp[i - 1][j - 1];

          dp[i][j] = min({ deleteOp, insertOp, replaceOp });
        }
      }
    }

    return dp[m][n];
  }

public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, word1, word2, dp);
  }
};
