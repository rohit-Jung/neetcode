#include <algorithm>
#include <climits>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  // approach 1: prefix suffix traversal
  int maxProduct1(vector<int>& nums) {
    int n = nums.size();

    int prefix  = 1;
    int suffix  = 1;
    int maxProd = INT_MIN;

    for(int i = 0; i < n; i++) {
      if(prefix == 0) prefix = 1;  // 0 edge case
      if(suffix == 0) suffix = 1;

      prefix = prefix * nums[i];          // product from left
      suffix = suffix * nums[n - 1 - i];  // product from right

      maxProd = max(maxProd, max(prefix, suffix));
    }

    return maxProd;
  }

  // approach 2: using dp like (space optimized DP)
  int maxProduct(vector<int>& nums) {
    int n = nums.size();

    int mn = nums[0];  // to swap incase
    int mx = nums[0];
    int an = nums[0];

    for(int i = 1; i < n; i++) {
      int curr = nums[i];

      if(curr < 0) swap(mx, mn);
      mx = max(curr, mx * curr);
      mn = min(curr, mn * curr);
      an = max(an, mx);
    }

    return an;
  }
};
