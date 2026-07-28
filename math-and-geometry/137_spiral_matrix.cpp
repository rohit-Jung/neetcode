#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();     // rows
    int m = matrix[0].size();  // cols

    int top    = 0;
    int bottom = n - 1;
    int left   = 0;
    int right  = m - 1;

    vector<int> result;
    while(top <= bottom && left <= right) {
      // left to right (row fixed -top)
      for(int i = left; i <= right; i++) {
        result.push_back(matrix[top][i]);
      }
      top++;

      // top to bottom (col fixed -right)
      for(int i = top; i <= bottom; i++) {
        result.push_back(matrix[i][right]);
      }

      right--;

      // right to left (row fixed -bottom) if row exist
      if(top <= bottom) {
        for(int i = right; i >= left; i--) {
          result.push_back(matrix[bottom][i]);
        }

        bottom--;
      }

      // bottom to top (col fixed = left) if col exist
      if(left <= right) {
        for(int i = bottom; i >= top; i--) {
          result.push_back(matrix[i][left]);
        }

        left++;
      }
    }

    return result;
  }
};
