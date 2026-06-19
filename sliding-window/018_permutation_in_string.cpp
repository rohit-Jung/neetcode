#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  // check if s2 contains permutation of s1
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;

    vector<int> s1Count(26, 0), s2Count(26, 0);

    // update the maps for characters you have
    for (int i = 0; i < s1.size(); i++) {
      s1Count[s1[i] - 'a'] += 1;
      s2Count[s2[i] - 'a'] += 1;
    }

    int matches = 0;
    // update the matches
    for (int i = 0; i < 26; i++) {
      if (s1Count[i] == s2Count[i])
        matches++;
    }

    // sliding window
    int l = 0;
    // window size of s1 - s2
    for (int r = s1.size(); r < s2.size(); r++) {
      if (matches == 26)
        return true;

      // increase the count as we are sliding over s2
      int idx = s2[r] - 'a';
      s2Count[idx]++;

      if (s1Count[idx] == s2Count[idx]) {
        matches++;
      } else if (s1Count[idx] + 1 == s2Count[idx]) {
        // we are destorying a match here so (by moving forward as r moves)
        matches--;
      }

      // left is moving means we are chopping off
      idx = s2[l] - 'a';
      s2Count[idx]--;

      if (s1Count[idx] == s2Count[idx]) {
        matches++;
      } else if (s1Count[idx] - 1 == s2Count[idx]) {
        // we are destorying a match here so (by moving forward as r moves)
        matches--;
      }

      l++;
    }

    return matches == 26;
  }
};
