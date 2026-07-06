#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<string>> sol;

  bool isPalindrome(string &s) {
    // check empty then not
    if (s.empty())
      return false;

    // if size is 1 then it's palindrome
    if (s.size() == 1)
      return true;

    // else two pointer
    int i = 0;
    int j = s.size() - 1;

    while (i <= j) {
      if (s[i] != s[j])
        return false;

      i++;
      j--;
    }

    return true;
  }

  // base case: idx passed string length,
  void solve(vector<string> &temp, int idx, string &s) {
    if (idx == s.length()) {
      // we are only procceding the palindrome calls so ,
      // temp should hold only palindrome
      sol.push_back(temp);
      return;
    }

    // backtracking
    for (int i = idx; i < s.size(); i++) {
      string curr = s.substr(idx, i - idx + 1);
      if (isPalindrome(curr)) {
        temp.push_back(curr);
        solve(temp, i + 1, s);
        temp.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    vector<string> temp;
    solve(temp, 0, s);
    return sol;
  }
};
