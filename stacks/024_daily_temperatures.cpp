#include <bits/stdc++.h>
#include <vector>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

// result[i] is the number of days after the ith day before a warmer temperature
// appears on a future day. Input: temperatures = [30,38,30,36,35,40,28] Output:
// [1,4,1,2,1,0,0]
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    // monotonic non increasing stack
    // you would need to store index too so a pair
    stack<pair<int, int>> st;

    // fix the size cause we are gonna play with indexes
    vector<int> sol(temperatures.size(), 0);

    // [30 , 38, 30 ]
    for (int i = 0; i < temperatures.size(); i++) {
      // if you if you find the temp. that is big
      while (!st.empty() && temperatures[i] > st.top().first) {
        int tmp = st.top().first;
        int idx = st.top().second;
        st.pop();

        // get the length and insert it in it's respective index
        int length = i - idx;
        sol[idx] = length;
      }

      st.push({temperatures[i], i});
    }

    return sol;
  }
};
