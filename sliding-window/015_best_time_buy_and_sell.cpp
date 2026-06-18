#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int b = 0;
    int s = b + 1;

    int maxProfit = 0;

    while (s < prices.size()) {
      // we only care about profit
      if (prices[b] < prices[s]) {
        int profit = prices[s] - prices[b];
        maxProfit = max(maxProfit, profit);
      } else {
        // if we are in profit don't change the buy
        b = s;
      }

      s++;
    }

    return maxProfit;
  }
};

int main() { cout << "hello world"; }
