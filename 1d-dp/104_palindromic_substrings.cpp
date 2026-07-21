#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
  // top down approach
  int t[1001][10001];
  int isValidPalindrome(int i, int j, string& s) {
    if(i >= j) return 1;
    if(t[i][j] != -1) return t[i][j];
    if(s[i] == s[j]) { return t[i][j] = isValidPalindrome(i + 1, j - 1, s); }
    return 0;
  }

  // bottom up approach
  int bottomUp(string& s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++) {  // one length strings are palindrome
      dp[i][i] = true;
    }

    int count = 0;

    // check after 2 length
    for(int L = 2; L <= n; L++) {
      for(int i = 0; i < n - L + 1; i++) {  // i + L - 1 < n - for j to be valid
        int j = i + L - 1;                  // for 2 length j would be 1 for 0;

        if(s[i] == s[j] && L == 2) {   // the inner substring doesn't exist for L == 2 so
          count++;
          dp[i][j] = true;
        } else if(s[i] == s[j] && dp[i + 1][j - 1]) {
          count++;
          dp[i][j] = true;
        } else {
          dp[i][j] = false;
        }
      }
    }

    return count;
  }

public:
  int countSubstrings(string s) {
    int n = s.size();
    memset(t, -1, sizeof(t));

    int count = 0;

    for(int i = 0; i < n; i++) {
      for(int j = i; j < n; j++) {
        if(isValidPalindrome(i, j, s)) { count++; }
      }
    }
    return count;
  }
};
