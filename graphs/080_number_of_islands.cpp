#include <bits/stdc++.h>
using namespace std;

/**
  solve; traverse through graph if 1 is encountered and mark all the
 neighbouring 1 as visited others would be zero and then you increase the number
 of island
 **/
class Solution {
private:
  static constexpr char visitedMark = '$';

  static constexpr int dr[4] = {1, -1, 0, 0};
  static constexpr int dc[4] = {0, 0, 1, -1};

  // approach1: dfs; recursion system stack
  void dfs(int r, int c, vector<vector<char>> &grid) {
    // out of bounds check
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
      return;
    }

    // already visited check or zero
    // if (grid[r][c] == visitedMark || grid[r][c] == '0') {
    if (grid[r][c] != '1') {
      return;
    }

    grid[r][c] = visitedMark;

    for (int i = 0; i < 4; i++) {
      int new_r = r + dr[i];
      int new_c = c + dc[i];

      dfs(new_r, new_c, grid);
    }

    // we don't need to unmark ?
  }

  // approach2: bfs using queue
  void bfs(int r, int c, vector<vector<char>> &grid) {
    queue<pair<int, int>> q;
    q.push({r, c});

    grid[r][c] = visitedMark;

    // lambda function to check isSafe / outOfBounds
    auto isSafe = [&](int &i, int &j) {
      if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        return false;
      if (grid[i][j] != '1')
        return false;
      return true;
    };

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      // traverse in every direction
      for (int i = 0; i < 4; i++) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];

        // if it's safe to traverse
        if (isSafe(new_r, new_c)) {
          q.push({new_r, new_c});
          // mark it as visited
          grid[new_r][new_c] = visitedMark;
        }
      }
    }
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    int islands = 0;

    // check
    if (grid.size() == 0) {
      return islands;
    }

    // traverse through each elem
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == '1') { // compare with char
          dfs(row, col, grid);
          islands++;
        }
      }
    }

    return islands;
  }
};
