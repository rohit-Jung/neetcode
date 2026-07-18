#include <bits/stdc++.h>
#include <vector>
using namespace std;

/**
  approach: recursive min cost to reach the top
  you can take 0 or 1 index
  **/
class Solution {
private:
  // approach 1: recursive (hits tle)
  int solve(vector<int> &cost, int i) {
    if (i >= cost.size())
      return 0;

    int oneStep = cost[i] + solve(cost, i + 1);
    int twoStep = cost[i] + solve(cost, i + 2);

    return min(oneStep, twoStep);
  }

  // approach 2: memoized
  int solveMemoized(vector<int> &cost, int i, vector<int> &cache) {
    if (i >= cost.size())
      return 0;

    if (cache[i] != -1)
      return cache[i];

    int oneStep = cost[i] + solveMemoized(cost, i + 1, cache);
    int twoStep = cost[i] + solveMemoized(cost, i + 2, cache);

    return cache[i] = min(oneStep, twoStep);
  }

  // approach 3: bottom up
  int bottomUp(vector<int> &cost) {
    int n = cost.size();
    if (n == 2)
      return min(cost[0], cost[1]);

    for (int i = 2; i < n; i++) {
      cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
    }

    // we are modifying the real array
    // so the ans would be the min of last two
    return min(cost[n - 1], cost[n - 2]);
  }

public:
  int minCostClimbingStairs(vector<int> &cost) {
    vector<int> cache(cost.size(), -1);
    // return min(solve(cost, 0), solve(cost, 1)); // given question has 0 or 1
    // return min(solveMemoized(cost, 0, cache), solveMemoized(cost, 1, cache));
    return bottomUp(cost);
  }
};
