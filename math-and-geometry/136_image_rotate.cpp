#include <bits/stdc++.h>
using namespace std;

/*
 * transpose the matrix
 * and reverse the rows
 * */
class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int m = matrix.size();  // squar matrix so

    // transpose upper triangular reverse
    for(int i = 0; i < m; i++) {
      for(int j = i + 1; j < m; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    // reverse the rows
    for(int i = 0; i < m; i++) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};
