#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  // this is staircase / greedy search but since array is sorted this
  // works 0(row + col)
  vector<int> greedySearch(vector<vector<int>> &matrix, int target) {
    int row = 0;
    int col = matrix.size() - 1;

    // search
    while (row < matrix.size() && col >= 0) {
      if (matrix[row][col] == target) {
        return vector<int>{row, col};
      }

      if (matrix[row][col] < target) {
        row++;
      } else {
        col--;
      }
    }

    return vector<int>{row, col};
  }

  // here we implement binary search
  // what if we assume the array is flatten
  // Row 0 → indices 0 to (m-1) Row 1 → indices m to (2m-1)
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(); // rows
    int m = matrix[0].size();

    int lo = 0;
    int hi = (n * m) - 1; // cause the last index would be

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      // convert back to matrix form index
      // 3 * 3 flatten and 5 then think
      int row = mid / m;
      int col = mid % m;

      // is it the elem
      if (matrix[row][col] == target) {
        return true;
      }

      if (target < matrix[row][col]) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return false;
  }
};

int main() {
  vector<vector<int>> matrix = {
      {1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
  int target = 10;

  Solution sol;
  int ans = sol.searchMatrix(matrix, target);

  cout << ans << endl;
}
