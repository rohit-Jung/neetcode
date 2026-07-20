#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
private:
  int t[1002][1002];
  int isValidPalindrome(int i, int j, string& s) {
    if(i >= j) return 1;
    if(t[i][j] != -1) return t[i][j];
    if(s[i] == s[j]) return t[i][j] = isValidPalindrome(i + 1, j - 1, s);
    return 0;
  }

  string bottomUp(string& s) {
    int n = s.length();

    vector<vector<bool>> t(n, vector<bool>(n, false));

    int maxL = 0;
    int idx  = 0;

    for(int i = 0; i < n; i++) {
      t[i][i] = true;
      maxL    = 1;
    }

    for(int L = 2; L <= n; L++) {
      for(int i = 0; i < n - L + 1; i++) {
        int j = i + L - 1;

        if(s[i] == s[j] && L == 2) {  // first case L = 2
          t[i][j] = true;
          maxL    = 2;
          idx     = i;
        } else if(s[i] == s[j] && t[i + 1][j - 1]) {
          t[i][j] = true;
          if(j - i + 1 > maxL) {
            maxL = j - i + 1;
            idx  = i;
          }
        } else {
          t[i][j] = false;
        }
      }
    }

    return s.substr(idx, maxL);
  }

public:
  string longestPalindromeRecursive(string s) {
    int n = s.size();
    memset(t, -1, sizeof(t));

    int maxLen = INT_MIN;
    int sp     = 0;

    for(int i = 0; i < n; i++) {
      for(int j = i; j < n; j++) {
        if(isValidPalindrome(i, j, s)) {
          if(j - i + 1 > maxLen) {
            maxLen = j - i + 1;
            sp     = i;
          }
        }
      }
    }

    return s.substr(sp, maxLen);
  }

  string longestPalindrome(string s) {
    return bottomUp(s);
  }
};
