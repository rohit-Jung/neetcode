#include <bits/stdc++.h>
using namespace std;

class Solution {
  static constexpr char visitMark = '*';
  static constexpr int dr[4] = {1, -1, 0, 0};
  static constexpr int dc[4] = {0, 0, 1, -1};

private:
  // base cases;
  bool find(vector<vector<char>> &board, int r, int c, int idx, string word) {
    // if we found
    if (idx == word.length()) {
      return true;
    }

    // out of bounds
    if (r >= board.size() || c >= board[0].size() || r < 0 || c < 0) {
      return false;
    }

    // if we have already visited then
    if (board[r][c] == visitMark) {
      return false;
    }

    // word idx didn't match
    if (board[r][c] != word[idx]) {
      return false;
    }

    char ch = board[r][c];

    // mark visited
    board[r][c] = visitMark;

    // explore all four directions;
    for (int i = 0; i < 4; i++) {
      if (find(board, r + dr[i], c + dr[i], idx + 1, word)) {
        return true;
      }
    }

    // unmark
    board[r][c] = ch;

    return false;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
          return true;
        }
      }
    }

    return false;
  }
};
