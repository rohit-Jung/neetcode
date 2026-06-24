#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

// target 12 position = [10, 8, 0, 5, 6] speed = [2, 3, 1, 1, 3]
// output 3
class Solution {
public:
  int carFleet(int target, vector<int> position, vector<int> speed) {
    // pair of position and speed
    vector<pair<int, int>> comb;
    if (position.size() != speed.size())
      return 0;

    for (int i = 0; i < position.size(); i++) {
      comb.push_back({position[i], speed[i]});
    }

    // this is ascending sort
    sort(comb.begin(), comb.end());

    // if two cars reaches the target at same time means they became a car fleet
    // traverse from the back: it could collide and slow down
    vector<double> st;

    // go from the nearest car to target
    for (int i = comb.size() - 1; i >= 0; i--) {
      // be sure to keep the time double
      double time = double((target - comb[i].first)) / comb[i].second;
      st.push_back(time);

      // if we have two carfleets then remove the second last ?
      if (st.size() >= 2 && st.back() <= st[st.size() - 2]) {
        st.pop_back();
      }
    }

    return st.size();
  }
};

int main() {
  int target = 12;
  vector<int> position = {10, 8, 0, 5, 3};
  vector<int> speed = {2, 4, 1, 1, 3};

  Solution sol;
  cout << sol.carFleet(target, position, speed);
}
