#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int dp[101][101][201];  // according to the constraint

  // TC - max visit - 101, 101, 201 O(m*n) and SC - O(m*n)
  bool solve(int i, int j, string s3, string s1, string s2) {
    int k = i + j;
    if(i == s1.size() && j == s2.size() && k == s3.size())
      return true;

    if(k >= s3.size())
      return false;  // empty string case

    if(dp[i][j][k] != -1)
      return dp[i][j][k];

    bool result = false;

    // move k and  i
    if(s1[i] == s3[k]) {
      result = solve(i + 1, j, s3, s1, s2);
    }

    if(result)
      return dp[i][j][k] = true;

    if(s2[j] == s3[k]) {
      result = solve(i, j + 1, s3, s1, s2);
    }
    return dp[i][j][k] = result;
  }

  // dp[i][j] represents whether the suffixes
  // s1[i:], s2[j:] can interleave to form s3[i+j:].
  bool bottomup(string s1, string s2, string s3) {
    int m = s1.size();
    int n = s2.size();
    int N = s3.size();

    if(m + n != N)
      return false;

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp[m][n] = true;  // for last one

    for(int i = m; i >= 0; i--) {
      for(int j = n; j >= 0; j--) {
        if(i < m && dp[i + 1][j] && s1[i] == s3[i + j])
          dp[i][j] = true;

        if(j < n && dp[i][j + 1] && s2[j] == s3[i + j])
          dp[i][j] = true;
      }
    }

    return dp[0][0];
  }

public:
  bool isInterleave(string s1, string s2, string s3) {
    memset(dp, -1, sizeof(dp));
    if(s1.size() + s2.size() < s3.size()) {
      return false;
    }
    return solve(0, 0, s3, s1, s2);
  }
};
