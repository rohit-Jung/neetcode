#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  static constexpr int dr[4] = { 1, -1, 0, 0 };
  static constexpr int dc[4] = { 0, 0, 1, -1 };

  int solve(vector<vector<int>>& matrix, int r, int c, int lastElem,
            vector<vector<int>>& dp) {

    // out of bounds
    if(r >= matrix.size() || r < 0 || c < 0 || c >= matrix[0].size()) {
      return 0;
    }

    // don't visit
    if(matrix[r][c] <= lastElem) {
      return 0;
    }

    if(dp[r][c] != -1)
      return dp[r][c];

    int path = 0;
    for(int i = 0; i < 4; i++) {
      int nc = c + dc[i];
      int nr = r + dr[i];

      // you can traverse means one path
      path = max(path, solve(matrix, nr, nc, matrix[r][c], dp));
    }

    return dp[r][c] = 1 + path;
  }

public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int maxPath = INT_MIN;
    int m       = matrix.size();
    int n       = matrix[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        maxPath = max(maxPath, solve(matrix, i, j, INT_MIN, dp));
      }
    }

    return maxPath;
  }
};
