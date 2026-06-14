#include <bits/stdc++.h>
using namespace std;

// unordered_set -> O(n), set -> binary search tree so O(nlogn)
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    // if any number is start of seq it doesn't have the left neighbor
    unordered_set<int> num_set(nums.begin(), nums.end());
    int longest_seq_length = 0;

    for (auto el : nums) {
      int prev_elem = el - 1;

      // we have the origin of a sequence
      if (num_set.find(prev_elem) == num_set.end()) {
        int length = 1;
        int next_elem = el + 1;

        while (num_set.find(next_elem) != num_set.end()) {
          length += 1;
          next_elem += 1;
        }

        if (length > longest_seq_length)
          longest_seq_length = length;
      }
    }
    return longest_seq_length;
  }
};
