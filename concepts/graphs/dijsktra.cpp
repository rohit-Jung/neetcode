#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  // older entries with larger distances are not removed and may be processed
  // later. why not queue and pq ? because on queue many updates may happen as
  // min isn't guaranteed
  // T.C: V * (logV + E logV)
  vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // Code here
    // adjs list
    vector<vector<pair<int, int>>> adjs(V);
    for (auto &edge : edges) {
      int a = edge[0];
      int b = edge[1];
      int t = edge[2];

      // undirected graph
      adjs[a].push_back({t, b});
      adjs[b].push_back({t, a});
    }

    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        min_heap;

    vector<int> result(V, INT_MAX);

    // set of source
    result[src] = 0;
    min_heap.push({0, src});

    // result vector to store distances
    while (!min_heap.empty()) { // V times
      auto [wt, n] = min_heap.top();
      min_heap.pop(); // logV

      // skip outdated entries
      if (wt > result[n])
        continue;

      // traverse through neighbors
      for (auto &[dist, node] : adjs[n]) { // E times
        // compare and push
        if (dist + wt < result[node]) { 
          result[node] = dist + wt;
          min_heap.push({result[node], node}); // log V
        }
      }
    }

    return result;
  }

  // done using Set, allows us to erase outdated pairs
  // set also orders by (distance, node) so begin() gives node with smallest
  // tentative dist
  vector<int> dijkstraSet(int V, vector<vector<int>> &edges, int src) {
    // Code here
    // adjs list
    vector<vector<pair<int, int>>> adjs(V);
    for (auto &edge : edges) {
      int a = edge[0];
      int b = edge[1];
      int t = edge[2];

      // undirected graph
      adjs[a].push_back({t, b});
      adjs[b].push_back({t, a});
    }

    // min heap
    set<pair<int, int>> st;
    vector<int> result(V, INT_MAX);

    // set the source
    result[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
      auto top = st.begin();

      int dist = top->first;
      int node = top->second;
      st.erase(top);

      for (auto &[wt, adjNode] : adjs[node]) {
        int resDist = result[adjNode];
        if (wt + dist < resDist) {
          // if it's not inf then erase
          if (result[adjNode] != INT_MAX)
            st.erase({result[adjNode], adjNode});

          result[adjNode] = wt + dist;
          st.insert({result[adjNode], adjNode});
        }
      }
    }

    return result;
  }
};
