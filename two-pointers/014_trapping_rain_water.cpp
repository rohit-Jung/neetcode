#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();

    int l = 0;
    int r = n - 1;

    // keep the track of what was max to
    // see how much block of water above me can be
    int maxL = height[l], maxR = height[r];

    int waterStored = 0;
    cout << maxL << maxR << endl;

    while (l < r) {
      // at any given point we want to move such that we reach the highest point
      // cause we want to be assured that the left or right has enough height
      // that we shouldn't care
      // printf("maxL: %d, maxR: %d, height[l]: %d, height[r]: %d\n", maxL,
      // maxR,
      //        height[l], height[r]);

      if (maxL < maxR) {
        // since we have already taken max of l and r increment it first
        l++;

        // how much can i hold, what's the max behind me that wouldn't allow to
        // overflow
        int diff = maxL - height[l];
        if (diff > 0)
          waterStored += diff;

        maxL = max(maxL, height[l]);
      } else {
        r--;
        int diff = maxR - height[r];
        if (diff > 0)
          waterStored += diff;

        maxR = max(maxR, height[r]);
      }
    }

    return waterStored;
  }
};

int main() {
  vector<int> heights = {4, 2, 3};
  Solution sol{};

  int ans = sol.trap(heights);
  cout << ans;
}
