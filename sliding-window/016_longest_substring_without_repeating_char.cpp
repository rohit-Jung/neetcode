#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  // sliding window
  int lengthOfLongestSubstring(string s) {
    // set
    unordered_set<char> charSet;

    // l would move only when duplicate is seen
    int l = 0;
    int maxLen = 0;

    int n = s.size();
    for (int r = 0; r < n; r++) {
      // remove char and move the window until duplicates
      while (contains(charSet, s[r])) {
        charSet.erase(s[l]);
        l++;
      }

      // +1 as 1 character may also form the subseq
      maxLen = max(maxLen, r - l + 1);
      // add it to set
      charSet.insert(s[r]);
    }

    return maxLen;
  }
};
