#include <bits/stdc++.h>
#include <climits>
using namespace std;

/*
   use the Djikstra's algorithm to find the min time
   take out the maximum time that's in
   if it's inf, then ans is -1 then its max itself;

   mistake: if 1 to n then size is n+1
*/
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // build an adjaceny list since 1 to n
    vector<vector<pair<int, int>>> adjs(n + 1);
    for (auto &time : times) {
      int a = time[0];
      int b = time[1];
      int w = time[2];

      adjs[a].push_back({w, b});
    }

    //  dijkstra
    set<pair<int, int>> st;
    vector<int> result(n+1, INT_MAX);
    result[k] = 0;
    st.insert({0, k}); // time and node

    while (!st.empty()) {
      auto top = st.begin();

      int dist = top->first;
      int node = top->second;

      st.erase(top);

      // go through neighbors
      for (auto &[t, adjNode] : adjs[node]) {
        if (t + dist < result[adjNode]) {
          // if we have greater dist
          if (result[adjNode] != INT_MAX)
            st.erase({result[adjNode], adjNode});

          result[adjNode] = t + dist;
          st.insert({result[adjNode], adjNode});
        }
      }
    }

    // find the greatest distance
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
      if (result[i] == INT_MAX)
        return -1;
      ans = max(ans, result[i]);
    }

    return ans;
  }
};
