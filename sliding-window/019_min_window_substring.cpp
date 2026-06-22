#include <bits/stdc++.h>
#include <climits>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

// s = "ADOBECODEBANC" t = "ABC"
// output = BANC
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> count, window;
    int have = 0, need = t.length();

    int resLen = INT_MAX;
    vector<int> resIdxs = {-1, -1};

    for (int c : t)
      count[c]++;

    int l = 0;
    for (int r = 0; r < s.size(); r++) {
      char c = s[r];
      window[c]++;

      if (contains(count, c) && window[c] <= count[c])
        have++;

      while (have == need) {
        // update the result if min is found
        int currLen = r - l + 1;
        if (currLen < resLen) {
          resLen = currLen;
          resIdxs = {l, r};
        }

        // update the left pointer
        char ch = s[l];
        // update the have count
        if (contains(count, ch) && window[ch] == count[ch])
          have--;

        window[ch] -= 1;
        l++;
      }
    }

    if (resIdxs[0] != -1 && resIdxs[1] != -1) {
      return s.substr(resIdxs[0], resLen);
    }

    return "";
  }
};

int main() {
  string s = "aa", t = "aa";
  Solution sol;

  string ans = sol.minWindow(s, t);
  cout << ans;
  return 0;
}
