#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int maxArea = INT_MIN;
    vector<pair<int, int>> stack;

    for (int i = 0; i < heights.size(); i++) {
      // remove until less is found
      // we keep track of start too; we want to know where the smaller one area
      // actually covers
      int start = i;

      while (!stack.empty() && heights[i] < stack.back().first) {
        int height = stack.back().first;
        int index = stack.back().second;

        maxArea = max(maxArea, height * (i - index));
        start = index;

        stack.pop_back();
      }

      stack.push_back({heights[i], start});
    }

    // what if there are elements that aren't smaller in height
    int n = heights.size();
    while (!stack.empty()) {
      int height = stack.back().first;
      int index = stack.back().second;

      // get the area
      maxArea = max(maxArea, height * (n - index));
      stack.pop_back();
    }

    return maxArea;
  }
};

int main() {
  vector<int> heights = {7, 1, 7, 2, 2, 4};
  Solution sol;
  cout << sol.largestRectangleArea(heights);
}
