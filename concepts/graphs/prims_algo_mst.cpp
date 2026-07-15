#include <bits/stdc++.h>
using namespace std;

/**
  MST: given the G(V + E) make a tree(no cycle) which has V vertex and V - 1
  Edges (min weight)
  **/
class Solution {
  typedef pair<int, int> P;

private:
  int PrimsAlgo(vector<vector<P>> &adj, int V) {
    // visited, pq, parent if asked
    priority_queue<P, vector<P>, greater<P>> min_heap; // min_heap
    min_heap.push({0, 0});                             // origin

    vector<bool> inMst(V, false);
    int sum = 0;

    while (!min_heap.empty()) {
      auto top = min_heap.top();

      int dist = top.first;
      int node = top.second;

      min_heap.pop();

      // if it's in MST
      if (inMst[node])
        continue;

      inMst[node] = true; // added to mst
      sum += dist;

      // neighbor traversal
      for (auto &[neigh_wt, neigh] : adj[node]) {
        if (!inMst[neigh])
          min_heap.push({neigh_wt, neigh});
      }
    }

    return sum;
  }

public:
  int spanningTree(int V, vector<vector<int>> &edges) {
    vector<vector<P>> adj(V);

    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int d = edge[2];

      adj[u].push_back({d, v});
      adj[v].push_back({d, u});
    }

    return PrimsAlgo(adj, V);
  }
};
