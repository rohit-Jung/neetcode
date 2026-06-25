#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  // we know len(p) <= h

  // bruteforce would be make k = [1..max(piles)] and iterate through it
  // such that if koko eat all how many hours is it gonna take

  // can we eat at rate of k in less than or equal to h
  int minEatingSpeed(vector<int> &piles, int h) {
    int ans = 0;
    int maxPile = *max_element(piles.begin(), piles.end());

    // mistake; you do not need a vector

    int lo = 1;
    int hi = maxPile;

    while (lo <= hi) {
      // this can be written in may ways
      int mid = lo - (lo - hi) / 2;
      int eatinTime = 0;

      for (int i = 0; i < piles.size(); i++) {
        // mistake; you need a ceil here and chose the kRange
        eatinTime += ceil((double)piles[i] / mid);
      }

      // check conditions
      if (eatinTime <= h) {
        // mistake; you update the min only if time <= h, also you need to
        // compare with mid ?
        ans = mid;

        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> piles = {1, 4, 3, 2};
  int h = 9;
  int ans = sol.minEatingSpeed(piles, 9);

  cout << ans;
}
