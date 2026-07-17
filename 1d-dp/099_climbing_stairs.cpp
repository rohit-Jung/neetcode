#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

/**
  solve: break the steps until you have 1 or two steps : recursive

  memoize it : dp
  **/
class Solution {
private:
  // approach 1 recursive solution
  int recursive(int n) {
    if (n < 0) {
      return 0;
    }

    if (n == 0)
      return 1;

    int oneStep = recursive(n - 1);
    int twoStep = recursive(n - 2);

    return oneStep + twoStep;
  }

  // approach 2 memoize
  int memoized(int n, vector<int> &cache) {
    if (n < 0) {
      return 0;
    }

    if (n == 0)
      return 1;

    if (cache[n] != -1)
      return cache[n];

    int oneStep = memoized(n - 1, cache);
    int twoStep = memoized(n - 2, cache);

    return cache[n] = oneStep + twoStep;
  }

  // approach 3 using the bottom up approach
  int bottomUp(int n) {
    vector<int> dp(n + 1);

    // we have this information
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }

  // approach 4 dp space optimized similar to fibo
  int dpSpaceOptimized(int n) {
    int a = 1; // i - 2
    int b = 2; // i - 1
    int c = 3; // i

    // for a given n we only need the info of i -1 and i -2
    for (int i = 3; i <= n; i++) {
      c = a + b;

      int temp = b;
      b = c;
      a = b;
    }

    return c;
  }

  // approach 5: since it follows fibo we can use maths Binet's formula for n =
  // Fibo(n + 1)
  int binetFormula(int n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    return round((pow(phi, n + 1) - pow(psi, n + 1)) / sqrt(5));
  }

public:
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }

    // vector<int> cache(n + 1, -1);
    // return recursive(n);
    // return memoized(n, cache);
    // return bottomUp(n);
    // return dpSpaceOptimized(n);
    return binetFormula(n);
  }
};
