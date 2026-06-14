#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    unordered_map<int, set<int>> cols; // col index -> all values on that col?
    unordered_map<int, set<int>> rows;
    map<pair<int, int>, set<int>> squares;

    // since it's square board
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        // if its empty continue
        int elem = board[r][c];
        if (elem == '.')
          continue;

        // check if cols has it
        if (cols[c].find(elem) != cols[c].end())
          return false;

        // check if rows has it
        if (rows[r].find(elem) != rows[r].end())
          return false;

        // check for squares
        pair<int, int> sq_idx = {(r / 3), (c / 3)};
        if (squares[sq_idx].find(elem) != squares[sq_idx].end())
          return false;

        // update the cols and rows
        cols[c].insert(board[r][c]);
        rows[r].insert(board[r][c]);
        squares[sq_idx].insert(board[r][c]);
      }
    }

    return true;
  }
};
