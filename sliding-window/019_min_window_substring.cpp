#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

// s = "ADOBECODEBANC" t = "ABC"
// output = BANC
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<int, int> window, count;
    int resSize = INT_MAX;
    vector<int> resIdx = {-1, -1};

    int need = t.length(), have = 0;

    // fill in the count
    for (int i = 0; i < t.length(); i++) {
      count[t[i]]++;
    }

    int l = 0;
    for (int r = 0; r < s.length(); r++) {
      int c = s[r];
      window[c]++;

      // do we have what we need
      if (contains(count, c) && window[c] == count[c]) {
        have++;
      }

      // cout << have << "\t" << need << endl;
      // update the left pointer
      while (have == need) {
        // cout << "length" << (r - l + 1) << endl;
        if ((r - l + 1) < resSize) {
          resSize = r - l + 1;
          resIdx = {l, r};
        }

        int c = s[l];

        // also decrease the have
        if (contains(count, c) && window[c] == count[c]) {
          have--;
        }

        window[c]--;
        l++;
      }
    }

    // cout << resIdx[0] << "\t" << resIdx[1] << endl;
    if (resIdx[0] < resIdx[1])
      return s.substr(resIdx[0], resIdx[1]);
    else
      return "";
  }
};

int main() {
  string s = "ADOBECODEBANC", t = "ABC";
  Solution sol;

  string ans = sol.minWindow(s, t);
  if (ans == "BANC") {
    cout << "PASS" << endl;
  } else {
    cout << "FAIL" << endl;
  }
  return 0;
}
