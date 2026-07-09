#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  // since it's vector of int so visit mark is also int
  static constexpr int visitMark = -1;
  static constexpr int dr[4] = {1, -1, 0, 0};
  static constexpr int dc[4] = {0, 0, 1, -1};

  // isSafe function: out of bounds and visited check
  bool isSafe(int &i, int &j, vector<vector<int>> grid) {
    // out of bounds
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
      return false;

    // visited char or zero
    if (grid[i][j] != 1)
      return false;

    return true;
  };

  // approach1: using dfs; recursion systemstack
  void dfs(int r, int c, vector<vector<int>> &grid, int &area) {
    // check if its safe
    if (!isSafe(r, c, grid)) {
      return;
    }

    // increase the area and mark it as visited
    area++;
    grid[r][c] = visitMark;

    // traverse in all four directions
    for (int i = 0; i < 4; i++) {
      int new_r = r + dr[i];
      int new_j = c + dc[i];

      dfs(new_r, new_j, grid, area);
    }
  }

  // approach2: using bfs; queue
  void bfs(int r, int c, vector<vector<int>> &grid, int &area) {
    queue<pair<int, int>> q;
    q.push({r, c});
    grid[r][c] = visitMark;
    area++;

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      // traverse in all four
      for (int i = 0; i < 4; i++) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];

        // if the new ones are safe then add to queue and mark visted
        // also increase the area
        if (isSafe(new_r, new_c, grid)) {
          q.push({new_r, new_c});
          grid[new_r][new_c] = visitMark;
          area++;
        }
      }
    }
  }

public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxArea = 0;
    int area = 0;

    // base check
    if (grid.size() <= 0) {
      return maxArea;
    }

    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c] == 1) {
          bfs(r, c, grid, area);
          maxArea = max(maxArea, area);
          area = 0;
        }
      }
    }

    return maxArea;
  }
};
