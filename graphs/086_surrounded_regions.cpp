#include <bits/stdc++.h>
using namespace std;

/**
  solve;
  start from boundry, find 0
  to all of the connected O from them, mark as they can't be converted

  then go through the board once more and if can be marked
  mark as 'X'

  T.C: O(m * n) : boundry m + n; dfs m * n at most once; traversal m * n
  S.C: O(m * n) : visited array + recursion stack
  **/
class Solution {
private:
  static constexpr int dr[4] = {1, -1, 0, 0};
  static constexpr int dc[4] = {0, 0, 1, -1};

  void dfs(vector<vector<char>> &board, int r, int c,
           vector<vector<bool>> &visited) {

    auto isSafe = [&](const int &i, const int &j) {
      // out of bounds
      if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0)
        return false;

      // it's an X
      if (board[i][j] == 'X')
        return false;

      // already visited
      if (visited[i][j])
        return false;

      return true;
    };

    if (!isSafe(r, c)) {
      return;
    }

    visited[r][c] = true;

    // go through all directions
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      dfs(board, nr, nc, visited);
    }
  }

public:
  void solve(vector<vector<char>> &board) {
    if (board.empty()) {
      return;
    }

    int m = board.size();
    int n = board[0].size();

    if (m <= 1 || n <= 1) {
      return;
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // go and find the boundry ones
    // row wise
    for (int r = 0; r < m; r++) {
      if (board[r][0] == 'O') {
        // do a dfs and mark visited
        dfs(board, r, 0, visited);
      }

      if (board[r][n - 1] == 'O') {
        dfs(board, r, n - 1, visited);
      }
    }

    // col wise
    for (int c = 0; c < n; c++) {
      if (board[0][c] == 'O') {
        dfs(board, 0, c, visited);
      }

      if (board[m - 1][c] == 'O') {
        dfs(board, m - 1, c, visited);
      }
    }

    // mark other as as 'X'
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j] && board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};
