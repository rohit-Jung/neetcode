#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

/**
  solve: atlantic and pacific visit mark array
  because you are not revisiting
  T.C : O(m*n)
  S.C : O(m*n)
  **/
class Solution {
private:
  // TODO: Solve it using BFS
  static constexpr int dr[4] = {1, -1, 0, 0};
  static constexpr int dc[4] = {0, 0, 1, -1};

  void dfs(vector<vector<int>> &heights, int i, int j,
           vector<vector<bool>> &visited, int prev) {

    // out of bounds
    if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) {
      return;
    }

    // already visited
    if (visited[i][j]) {
      return;
    }

    // if the height is greater ?
    if (heights[i][j] < prev) {
      return;
    }

    // mark as visited
    visited[i][j] = true;

    // traverse in all four directions
    for (int k = 0; k < 4; k++) {
      int nr = i + dr[k];
      int nc = j + dc[k];

      dfs(heights, nr, nc, visited, heights[i][j]);
    }
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> ans;

    vector<vector<bool>> pacificVisited(m, vector<bool>(n, false));
    vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false));

    // first row and last row: col is fixed
    for (int j = 0; j < n; j++) {
      dfs(heights, 0, j, pacificVisited, INT_MIN);
      dfs(heights, m - 1, j, atlanticVisited, INT_MIN);
    }

    // first col and last col: row is fixed
    for (int i = 0; i < m; i++) {
      dfs(heights, i, 0, pacificVisited, INT_MIN);
      dfs(heights, i, n - 1, atlanticVisited, INT_MIN);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (pacificVisited[i][j] && atlanticVisited[i][j]) {
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }
};
