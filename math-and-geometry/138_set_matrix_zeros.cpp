#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // bruteforce: take a temp matrix mark zeros if any zero
  // T.C : O(m*n*(m+n))
  // S.C : O(m*n)
  void setZeroesExtraSpace(vector<vector<int>>& matrix) {
    int m = matrix.size();     // rows
    int n = matrix[0].size();  // cols

    vector<vector<int>> temp = matrix;

    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(matrix[i][j] == 0) {
          // set rows 0
          for(int k = 0; k < m; k++) {
            temp[i][k] = 0;
          }

          // set cols 0
          for(int k = 0; k < m; k++) {
            temp[k][j] = 0;
          }
        }
      }
    }

    matrix = temp;
  }

  // Space optimized - S.C. O(m+n)
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();     // row
    int n = matrix[0].size();  // col

    vector<bool> row(m, false);
    vector<bool> col(n, false);

    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(matrix[i][j] == 0) {
          row[i] = true;
          col[j] = true;
        }
      }
    }

    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(row[i] || col[j]) matrix[i][j] = 0;
      }
    }
  }

  // inplace and constant space
  void setZeros(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    //  for edge case
    bool firstRowImpacted = false;
    bool firstColImpacted = false;

    // get if any of first row or col is zero
    for(int i = 0; i < m; i++) {
      if(matrix[0][i] == 0) {
        firstRowImpacted = true;
        break;
      }
    }

    for(int i = 0; i < n; i++) {
      if(matrix[i][0] == 0) {
        firstColImpacted = true;
        break;
      }
    }

    // go through and make the markers (note: traverse through 1st)
    for(int i = 1; i < m; i++) {
      for(int j = 1; j < n; j++) {
        if(matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    // according to markers change the cols
    for(int i = 1; i < m; i++) {
      for(int j = 1; j < n; j++) {
        if(matrix[0][j] == 0 || matrix[i][0] == 0) { matrix[i][j] = 0; }
      }
    }

    // for the first row and col
    if(firstRowImpacted) {
      for(int i = 0; i < n; i++) {
        matrix[0][i] = 0;
      }
    }

    if(firstColImpacted) {
      for(int i = 0; i < m; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};
