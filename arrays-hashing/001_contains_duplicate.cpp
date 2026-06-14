#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // O(n) solution - as we travese through the list only once
  bool hasDuplicate(vector<int> &nums) {
    // maintain a set
    unordered_set<int> seen;

    // iterate through the vector
    for (auto el : nums) {
      // if it exist in set we have duplicate 
      if (seen.count(el))
        return true;

      // else just add 
      seen.insert(el);
    }

    return false;
  }
};
