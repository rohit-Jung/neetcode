#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // word frequency
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> solution;
    map<vector<int>, vector<string>> freq;

    for (auto el : strs) {
      // store the count of letters in word?
      vector<int> count(26, 0);
      for (auto c : el) {
        // be care ful of indexing
        count[c - 'a']++;
      }

      // if it exist append the word
      freq[count].push_back(el);
    }

    for (auto [key, val] : freq) {
      solution.push_back(val);
    }

    return solution;
  }
};
