#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

/*  subsequence
 *  any contigious elements that follow the order
 *
 *  print all subsequence - power set or recursion, once all generated check for
 *  increasing O(2^n)
 *
 *  recurrence relation and memoization
 *   explain everthing in terms of (idx)
 *   explore all
 *   take max length of
 *   base case - when you run out of elements
 *
 *  prev index -> you should know what you took prev
 *  f(idx, prev) -> length of string starting from idx whose prev is prevIdx
 *
 *  approach 2: bottom up
 *  dp[i] = max(dp[i], 1 + dp[j])
 * */
class Solution {
private:
  int recursiveMemoized(int idx, int prev_idx, vector<int>& nums,
                        vector<vector<int>>& dp) {
    if(idx == nums.size()) return 0;
    if(dp[idx][prev_idx + 1] != -1)
      return dp[idx][prev_idx + 1];  // +1 because prev can be -1 ?

    int len = 0 + recursiveMemoized(idx + 1, prev_idx, nums, dp);  // not take

    if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {  // since its increasing
      len = max(len, 1 + recursiveMemoized(idx + 1, idx, nums, dp));
    }

    return dp[idx][prev_idx + 1] = len;
  }

  // T.C. O(n*n)  S.C = O(n);
  int bottomup(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1);
    int maxLTS = 1;  // max at least is 1

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < i; j++) {         // up to i
        if(nums[j] < nums[i]) {            // j < i for increasing
          dp[i]  = max(dp[i], 1 + dp[j]);  // 1 for itself
          maxLTS = max(maxLTS, dp[i]);     // max between them
        }
      }
    }

    return maxLTS;
  }

  // approach3: patience sorting
  // >= elem - bucket
  // new greatest - make a new bucket else add it in existing ones
  // length of sorted array would be the ans
  int patienceSorting(vector<int>& nums) {
    int n = nums.size();

    vector<int> sorted;
    for(int i = 0; i < n; i++) {
      auto lower = lower_bound(begin(sorted), end(sorted), nums[i]);
      // not found
      if(lower == sorted.end()) {
        sorted.push_back(nums[i]);
      } else {
        // replace
        *lower = nums[i];
      }
    }

    return sorted.size();
  }

public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    // 2d array as there are 2 elems
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return bottomup(nums);
    // return recursiveMemoized(0, -1, nums, dp);
  }
};
