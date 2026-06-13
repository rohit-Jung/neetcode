#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // get the frequency of elements
    unordered_map<int, int> initial_freq;
    for (int el : nums) {
      initial_freq[el]++;
    }

    // use the bucket sort for top k
    // we use bucket sort but improved
    vector<vector<int>> bucket(nums.size() + 1);
    for (auto &[key, count] : initial_freq) {
      bucket[count].push_back(key);
    }

    vector<int> sol;
    int n = bucket.size() - 1;
    for (int i = n; i > 0; i--) {
      for (int num : bucket[i]) {
        sol.emplace_back(num);

        if (sol.size() >= k) {
          return sol;
        }
      }
    }

    return sol;
  }
};
