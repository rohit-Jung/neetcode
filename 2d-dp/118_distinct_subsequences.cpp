#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int solve(int i, int j, string s, string t, vector<vector<int>>& dp) {
    if(j == t.size()) {
      return 1;  // matched all at the end
    }

    if(i >= s.size())
      return 0;  // consumed all s

    if(dp[i][j] != -1) {
      return dp[i][j];
    }

    int take = 0;
    if(s[i] == t[j]) {
      take = solve(i + 1, j + 1, s, t, dp);
    }

    int skip = solve(i + 1, j, s, t, dp);  // we did not match the j so

    return dp[i][j] = take + skip;
  }

  /*
   * State:
   * dp[i][j] = number of distinct subsequences of s[i:]
   *            that equal t[j:].
   */
  using ll = long long;
  int bottomup(string s, string t) {
    int m = s.size();
    int n = t.size();

    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));
    // dp[m][j] = 0; i == m

    // exact 1 subsequence when the t is 0 empty suffix
    for(int i = 0; i <= m; i++) {
      dp[i][n] = 1;  // j == n
    }

    for(int i = m - 1; i >= 0; --i) {
      for(int j = n - 1; j >= 0; --j) {
        dp[i][j] = dp[i + 1][j];  // skip s[i]

        if(s[i] == t[j])
          dp[i][j] += dp[i + 1][j + 1];  // take s[i]
      }
    }

    return dp[0][0];
  }

public:
  int numDistinct(string s, string t) {
    if(t.size() > s.size())
      return 0;

    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return solve(0, 0, s, t, dp);
  }
};

int main() {
  string s = "caaat";
  string t = "cat";
  Solution sol {};
  cout << sol.numDistinct(s, t);
}
