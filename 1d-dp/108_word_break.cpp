#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  // approach 1 recursion and memoization
  bool solve(int i, string& s, unordered_set<string>& wordDict,
             vector<int>& dp) {

    if(i == s.size()) { return true; };
    if(dp[i] != -1) return dp[i];

    // it has
    if(wordDict.count(s)) { return dp[i] = 1; }

    for(int l = 1; l <= s.size(); l++) {
      string temp = s.substr(i, l);
      if(wordDict.count(temp) && solve(i + l, s, wordDict, dp)) {
        return dp[i] = 1;
      }
    }

    return dp[i] = 0;
  }

  // approach2: bottom up
  int bottomup(string& s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[s.size()] = true;

    for(int i = s.size() - 1; i >= 0; i--) {
      for(string& w : wordDict) {
        if(i + w.size() <= s.size() && s.substr(i, w.size()) == w) {
          dp[i] = dp[i + w.size()];
          if(dp[i]) { break; }
        }
      }
    }

    return dp[0];
  }

public:
  bool wordBreak(string s, vector<string>& wordDict) {
    // for O(1) access
    unordered_set<string> dict(begin(wordDict), end(wordDict));
    vector<int> dp(s.size(), -1);

    return solve(0, s, dict, dp);
  }
};
