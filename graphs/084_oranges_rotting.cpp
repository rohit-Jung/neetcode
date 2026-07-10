#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  static constexpr int rottenMark = 2;
  static constexpr int emptyMark = 0;
  static constexpr int freshMark = 1;
  static constexpr int dr[4] = {1, -1, 0, 0};
  static constexpr int dc[4] = {0, 0, 1, -1};

  bool isSafe(vector<vector<int>> &grid, int r, int c) {
    // out of bounds
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
      return false;
    }

    // if it's fresh then you can spread
    return grid[r][c] == freshMark;
  }

  int bfs(vector<vector<int>> &grid, queue<pair<int, int>> q, int &fresh) {
    if (fresh == 0)
      return 0;

    int dist = -1;
    while (!q.empty() && fresh > 0) {

      int s = q.size();

      while (s--) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
          int nr = r + dr[i];
          int nc = c + dc[i];

          if (isSafe(grid, nr, nc)) {
            // mark the oragne as rotten
            grid[nr][nc] = rottenMark;
            fresh--;
            q.push({nr, nc});
          }
        }
      }

      dist++;
    }

    // if any fresh remains we couldn't rot
    return fresh == 0 ? dist : -1;
  }

public:
  int orangesRotting(vector<vector<int>> &grid) {
    // find the rotting orange
    // on every level the distance increases
    queue<pair<int, int>> q;
    int freshOranges = 0;

    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c] == rottenMark) {
          q.push({r, c});
        } else if (grid[r][c] == freshMark) {
          freshOranges++;
        }
      }
    }

    return bfs(grid, q, freshOranges);
  }
};
