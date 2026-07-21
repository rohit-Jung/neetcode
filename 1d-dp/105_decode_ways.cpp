#include <bits/stdc++.h>
#include <vector>
using namespace std;

// mappings are from A to Z; 1 to 26
class Solution {
private:
  int solve(int i, string& s, vector<int>& dp) {
    // base cases
    if(i == s.size()) return 1;  // valid state
    if(s[i] == '0') return 0;

    if(dp[i] != -1) return dp[i];

    int ways = 0;
    ways += solve(i + 1, s, dp);

    // for two digit number
    if(i + 1 < s.size()) {
      //   int num = (s[i] - '0') * 10 + s[i + 1] - '0';
      //   if(num >= 10 && num <= 26) { ways += solve(i + 2, s, dp); }
      if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
        ways += solve(i + 2, s, dp);
      }
    }

    return dp[i] = ways;
  }

  int bottomUp(string& s) {
    int n = s.size();

    vector<int> dp(n + 1, 0);  // checking n + 2 at end

    dp[n] = 1;  // this is the base case as recursion

    for(int i = n - 1; i >= 0; i--) {
      if(s[i] == '0')
        dp[i] = 0;
      else {
        dp[i] = dp[i + 1];  // sovle(i+1)
        if(i + 1 < n) {
          if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
            dp[i] += dp[i + 2];  // solve(i+2)
          }
        }
      }
    }

    return dp[0];  // s[0..n] decode ways
  }

  // TODO: understand this
  int bottomUpSecond(string& s) {
    int n = s.size();

    if(n == 1) return s[0] == '0' ? 0 : 1;
    if(s[0] == '0') return 0;

    int last1 = 1;
    int last2 = 1;

    for(int i = 0; i < n; i++) {
      int count = s[i] != '0' ? last1 : 0;
      if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i - 2] <= '6')) {
        count += last2;
      }

      last2 = last1;
      last1 = count;
    }

    return last1;
  }

public:
  int numDecodings(string s) {
    vector<int> dp(s.size(), -1);
    return solve(0, s, dp);
  }
};
