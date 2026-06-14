#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    // postfix and prefix as you cannot use division

    vector<int> solution(nums.size(), 0);
    // prefix sum
    int prefix_sum = 1;
    // [1,2,4,6] -> [1, 1, 2, 8]
    for (int i = 0; i < nums.size(); i++) {
      solution[i] = prefix_sum;
      prefix_sum *= nums[i];
    }

    // postfix and solution
    // [1, 1, 2, 8] [1, 2, 4, 6] -> [ ,48,8]
    int postfix_sum = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      solution[i] = postfix_sum * solution[i];
      postfix_sum *= nums[i];
    }
    
    return solution;
  }
};
