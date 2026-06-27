#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // slow and fast pointer
  // how ? its 1 .. n and also find duplicay
  int findDuplicate(vector<int> &nums) {

    int slow = nums[0];
    int fast = nums[0];

    // detect cycle
    // you should atleast move once so do while
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    // move slow to first
    slow = nums[0];

    // move both by 1
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};
