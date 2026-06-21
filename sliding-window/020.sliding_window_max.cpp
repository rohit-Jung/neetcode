#include <bits/stdc++.h>
#include <deque>
#include <vector>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

// [1, 3, -1, -3, 5, 4, 6, 7] k = 3
// [3, 3, 4, 6, 7]
// max SlidingWindow

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> w, int k) {
    // monotonic Deq
    deque<int> dq;

    int l = 0;
    vector<int> sol;
    for (int r = 0; r < w.size(); r++) {
      while (!dq.empty() && w[dq.back()] < w[r]) {
        dq.pop_back();
      }

      dq.emplace_back(r);

      // we need to pop from from if we move our left index
      // but we still have the left index in the deq
      // which is why we are storing the index rather than element
      if (l > dq[0]) {
        dq.pop_front();
      }

      if ((r + 1) >= k) {
        sol.emplace_back(w[dq.front()]);
        l++;
      }
    }

    return sol;
  }
};
