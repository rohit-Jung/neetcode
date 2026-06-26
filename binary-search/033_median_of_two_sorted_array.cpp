#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  // solution must run on log(m + n)
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // a should be the shortest
    vector<int> &a = nums1.size() > nums2.size() ? nums2 : nums1;
    vector<int> &b = nums1.size() > nums2.size() ? nums1 : nums2;

    int total = a.size() + b.size();
    // +1 makes left partition hold extra elem so max(l1, l2) can be done
    // a: [1 3 | 8]
    // b: [2 | 4 5]
    int half = (total + 1) >> 1;

    int lo = 0;
    int hi = a.size();
    while (lo <= hi) {
      // left shift is integer division
      int mid1 = lo + ((hi - lo) >> 1);
      int mid2 = half - mid1;

      // get the elems for comparison
      int l1 = mid1 > 0 ? a[mid1 - 1] : INT_MIN;
      int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;

      int r1 = mid1 < a.size() ? a[mid1] : INT_MAX;
      int r2 = mid2 < b.size() ? b[mid2] : INT_MAX;

      // check the partition is correct
      // entire left <= entire right
      if (l1 <= r2 && l2 <= r1) {
        // odd even check
        if (total & 1)
          return max(l1, l2);

        return (max(l1, l2) + min(r1, r2)) / 2.0;
      }

      // make the box of 4 and try comparing, l1 and l2
      // l1 is greater so we have more elems on a(l1)? how do we decrease ?
      // just decrease the high
      if (l1 > r2) {
        hi = mid1 - 1;
      } else {
        lo = mid1 + 1;
      }
    }

    return 0.0;
  }
};
