#include <bits/stdc++.h>
using namespace std;

// binary exponentiation
class Solution {
  using ll = long long;

private:
  double solve(double x, ll n) {  // long to increase the range
    if(n == 0) return 1;          // power 0 is 1
    if(n < 0) return solve(1 / x, -n);

    if(n & 1)  // it's odd
      return x * solve(x * x, (n - 1) >> 1);
    else
      return solve(x * x, n >> 1);
  }

  double iterative(double x, ll n) {
    bool neg = (n < 0);
    if(neg) n = -n;

    double ans = 1.0;

    while(n > 0) {
      if(n & 1)  // if n is odd
        ans *= x;

      x *= x;
      n >>= 1;
    }

    return neg ? 1.0 / ans : ans;
  }

public:
  double myPow(double x, int n) {
    return solve(x, (ll)n);
  }
};
