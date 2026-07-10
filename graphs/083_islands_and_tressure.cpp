#include <bits/stdc++.h>
using namespace std;

/**
  solve: you would traverse get all the treasures first
  and from them mark every level of land as prev + 1, stop till it's out of
 bound or it's not land
 **/
class Solution {
private:
  static constexpr int waterMark = -1;
  static constexpr int tressureMark = 0;
  static constexpr int landMark = 2147483647;

  static constexpr int dr[4] = {1, -1, 0, 0};
  static constexpr int dc[4] = {0, 0, 1, -1};

  // base case: out of bounds / water
  bool isSafe(int &i, int &j, vector<vector<int>> &grid) {
    // out of bounds check
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
      return false;
    }

    // only visit empty land
    return grid[i][j] == landMark;
  };

  // DFS explores deep, not closest.
  // nearest, minimum distance, or shortest path in an unweighted grid,- BFS
  void bfs(queue<pair<int, int>> q, vector<vector<int>> &grid) {
    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // skip the ones not safe to travel
        if (!isSafe(nr, nc, grid)) {
          continue;
        }

        // parent has the shortest distance so
        grid[nr][nc] = grid[r][c] + 1;
        q.push({nr, nc});
      }
    }
  }

public:
  void islandsAndTreasure(vector<vector<int>> &grid) {
    // visit all the treasures first
    // push them to queue
    queue<pair<int, int>> q;
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        // if it's  a tressure
        if (grid[r][c] == tressureMark) {
          q.push({r, c});
        }
      }
    }

    // traverse  from the treasures back
    bfs(q, grid);
  }
};
