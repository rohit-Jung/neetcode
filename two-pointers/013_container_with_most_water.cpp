#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  // two pointer approach
  int maxArea(vector<int> &heights) {
    int n = heights.size();

    int l = 0;
    int r = n - 1;
    int maxArea = 0;

    while (l < r) {
      // length * breadth dumb take care about operator precedence too ?
      int area = (r - l) * min(heights[l], heights[r]);

      cout << area << l << r << endl;
      if (area > maxArea)
        maxArea = area;

      // move the pointer on which less side is there
      heights[l] < heights[r] ? l++ : r--;
    }

    return maxArea;
  }

  // bruteForce
  int maxAreaBrute(vector<int> &heights) {
    // this exceeds time limit as it's O(n^2)
    int maxArea = 0;

    int n = heights.size();
    for (int l = 0; l < n; l++) {
      for (int r = l + 1; r < n; r++) {
        int area = (r - l) * min(heights[l], heights[r]);
        maxArea = max(maxArea, area);
      }
    }

    return maxArea;
  }
};
