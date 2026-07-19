#include <bits/stdc++.h>
using namespace std;

/* approach
 * if 0th is taken you cannot take last (0, n-2) as it's circular
 * else you take (1, n-1)
 *
 * now its the same case as house robber i
 */
class Solution {
private:
  // using memoization
  int solve(vector<int> &nums, vector<int> &cache, int i, int n) {
    if (i > n) { // can be = n
      return 0;
    }

    if (cache[i] != -1)
      return cache[i];

    int take = nums[i] + solve(nums, cache, i + 2, n);
    int skip = solve(nums, cache, i + 1, n);

    return cache[i] = max(take, skip);
  }

  // bottomup approach
  int bottomup(vector<int> &nums) {
    int n = nums.size();
    vector<int> t(n + 1, 0);

    if (n == 1)
      return nums[0];

    t[0] = 0;

    // go from first house
    for (int i = 1; i <= n - 1; i++) {
      int take = t[i - 1];
      int skip = nums[i - 1] + ((i - 2 >= 0) ? t[i - 2] : 0);
      t[i] = max(take, skip);
    }

    int result1 = t[n - 1]; // ans at last
    t.assign(n + 1, 0);     // reset

    t[0] = 0;
    t[1] = 0; // skipped the first house

    for (int i = 2; i <= n; i++) {
      int take = t[i - 1];
      int skip = nums[i - 1] + ((i - 2 >= 0) ? t[i - 2] : 0);
      t[i] = max(take, skip);
    }

    int result2 = t[n]; // ans is at last

    return max(result1, result2);
  };

public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> cache(n, -1);

    // nums of 0
    if (n == 1)
      return nums[0];

    int take0thIndex = solve(nums, cache, 0, n - 2); // don't take last
    cache.assign(n, -1);                             // reset the cache
    int take1stIndex = solve(nums, cache, 1, n - 1);

    return max(take0thIndex, take1stIndex);
  }
};
