#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  int characterReplacement(string s, int k) {
    // create a map of freq, maxFreq, l, r
    unordered_map<char, int> freq;

    int longestWinLen = 0;
    int maxFreq = 0;

    // sliding window loop
    int l = 0;
    for (int r = 0; r < s.size(); r++) {
      // update the freq
      freq[s[r]] += 1;

      // we do not need to decrement the maxFreq
      // over estimating is ok
      if (freq[s[r]] > maxFreq)
        maxFreq = freq[s[r]];

      // move to left if we exceed k
      while ((r - l + 1) - maxFreq > k) {
        // we are limiting the window so freq decreases for that window
        freq[s[l]] -= 1;
        l++;
      }

      longestWinLen = max(longestWinLen, r - l + 1);
    }

    return longestWinLen;
  }

  // how is this better
  // int characterReplacement(string s, int k) {
  //   unordered_map<char, int> m;
  //   int n = s.size();
  //   if (n < 2)
  //     return n;
  //
  //   int i = 0, j = 0;
  //   int ans = 0;
  //
  //   bool valid = false;
  //   m[s[0]]++;
  //
  //   while (i <= j && j < n) {
  //     if (valid)
  //       m[s[j]]++;
  //
  //     valid = false;
  //     for (auto x : m) {
  //       if (j - i + 1 <= x.second + k) {
  //         // valid size
  //         ans = max(ans, j - i + 1);
  //         j++;
  //         valid = true;
  //         break;
  //       }
  //     }
  //     if (!valid) {
  //       m[s[i]]--;
  //       i++;
  //     }
  //   }
  //   return max(ans, j - i);
  // }
};
