#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  // approach1: simple recursive (hits tle)
  int recursive(vector<int> &nums, int i) {
    if (i >= nums.size())
      return 0;

    int steal = nums[i] + recursive(nums, i + 2);
    int skip = recursive(nums, i + 1);

    return max(steal, skip);
  }

	// approach2: memoization
	int memoize(vector<int> &nums, vector<int> &cache, int i){
		if (i >= nums.size()) 
			return 0;

		if (cache[i] != -1)
			return cache[i];

		int steal = nums[i] + memoize(nums, cache, i + 2); // skip adjacent
		int skip = memoize(nums, cache, i + 1);

		return cache[i] = max(steal, skip);
	}

	// approach3: bottomup
	int bottomUp(vector<int> &nums) {
		int n = nums.size();
    if (n == 1) return nums[0];
		if (n == 2) return max(nums[0], nums[1]);

    nums[1] = max(nums[0], nums[1]);

		for (int i = 2; i < n; i++){
			nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
		}

		return nums[n - 1];
	}


public:
  int rob(vector<int> &nums) { 
		vector<int> cache(nums.size(), -1);
		// return recursive(nums, 0); 
		return memoize(nums, cache, 0); 
	}
};
