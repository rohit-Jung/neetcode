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
    // storing indexes in the deque easier
    deque<int> dq;
    vector<int> sol;

    int l = 0;
    for (int r = 0; r < w.size(); r++) {
      // remove the least ones
      while (!dq.empty() && w[dq.back()] < w[r]) {
        dq.pop_back();
      }

      dq.emplace_back(r);

      // remove from the front if we have crossed the index
      if (l > dq.front()) {
        dq.pop_front();
      }

      // we want to see if we have crossed k window
      int windowLen = (r - l + 1);
      if (windowLen + 1 > k) {
        // we always have the max on front
        sol.emplace_back(w[dq.front()]);
        l++;
      }
    }

    return sol;
  }
};

int main() {
  // vector<int> w = {1, 3, -1, -3, 5, 4, 6, 7};
  vector<int> w = {8, 7, 6, 9};
  int k = 2;

  Solution sol;
  vector<int> ans = sol.maxSlidingWindow(w, k);
  for (int el : ans) {
    cout << el << ",";
  }
  return 0;
}
