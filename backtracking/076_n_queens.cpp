#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &t) {
  return s.find(t) != s.end();
}

class Solution {
private:
  vector<vector<string>> sol;
  int colSize;

  static constexpr char queenMark = 'Q';
  static constexpr char queenUnMark = '.';

  // approach 1: isValid
  bool isValid(vector<string> &board, int row, int col) {
    // check for upwards
    for (int i = row; i >= 0; i--) {
      if (board[i][col] == queenMark)
        return false;
    }

    // check for up right diagonal
    for (int i = row, j = col; i >= 0 && j <= colSize; i--, j++) {
      if (board[i][j] == queenMark)
        return false;
    }

    // check for up left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == queenMark)
        return false;
    }

    return true;
  }

  // marke them as you place the queen
  unordered_set<int> colsMarked;
  unordered_set<int> diagonalsMarked;
  unordered_set<int> antiDiagonalsMarked;

  // approach 2: isValidOptimized
  bool isValidOptimized(int col, int diagonal, int antiDiagonal) {
    // check if any set contains O(1)
    if (contains(colsMarked, col) || contains(diagonalsMarked, diagonal) ||
        contains(antiDiagonalsMarked, antiDiagonal)) {
      return false;
    }

    return true;
  }

  // backtracking;
  void solve(vector<string> &board, int row) {
    // base case;
    if (row >= colSize) {
      sol.push_back(board);
      return;
    }

    for (int col = 0; col < colSize; col++) {
      // this would be constant througout the diag
      int diagonal = row + col;
      int antiDiagonal = row - col;

      // if (isValid(board, row, col)) {
      if (isValidOptimized(col, diagonal,
                           antiDiagonal)) { // check if attack is not there

        colsMarked.insert(col);
        diagonalsMarked.insert(diagonal);
        antiDiagonalsMarked.insert(antiDiagonal);

        // insert into valid
        board[row][col] = queenMark; // place queen

        solve(board, row + 1); // explore another row

        // erase as you backtrack
        colsMarked.erase(col);
        diagonalsMarked.erase(diagonal);
        antiDiagonalsMarked.erase(antiDiagonal);

        board[row][col] = queenUnMark; // mark unexplore for another row
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    colSize = n;
    vector<string> board(n, string(n, '.')); // { "..." , "..."}
    solve(board, 0);
    return sol;
  }
};
