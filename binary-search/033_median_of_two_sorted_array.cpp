#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  // solution must run on log(m + n)
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int total = nums1.size() + nums2.size();
    int half = total / 2;

    const vector<int> &a = nums1.size() <= nums2.size() ? nums1 : nums2;
    const vector<int> &b = nums1.size() <= nums2.size() ? nums2 : nums1;

    int l = 0, r = a.size();

    // binary search in shorter array log(shorter)
    while (true) {
      int mid1 = l + (r - l) / 2;

      // how many to pickup from array 2
      int mid2 = half - mid1;

      // since you are taking mid on other side so [mid1 - 1] for left
      int aLeft = mid1 > 0 ? a[mid1 - 1] : INT_MIN;
      int aRight = (mid1 < (int)a.size()) ? a[mid1] : INT_MAX;

      int bLeft = mid2 > 0 ? b[mid2 - 1] : INT_MIN;
      int bRight = (mid2 < (int)b.size()) ? b[mid2] : INT_MAX;

      // check if the partition is right
      // entire left <= entire right
      if (aLeft <= bRight && bLeft <= aRight) {
        // two cases: odd and even
        if (total % 2) {
          return min(aRight, bRight);
        }

        return ((max(aLeft, bLeft) + min(aRight, bRight)) / 2.0);
      }

      // make the box of 4 and try comparing, aleft and bright
      // you would notice you need to go back | reduce the search space
      // take less in a as there are more since the condition is invalid
      if (aLeft > bRight) {
        // understand this
        r = mid1 - 1; // why -1 ? you are taking mid1 also
      } else {
        l = mid1 + 1;
      }
    }

    return 0.0;
  }
};

int main() {
  Solution sol{};
  vector<int> nums1 = {1, 2}, nums2 = {3};

  cout << sol.findMedianSortedArrays(nums1, nums2);
}
