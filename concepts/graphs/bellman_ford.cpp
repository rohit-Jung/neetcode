#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  // Could detect -ve cycle and works on -ve edges (directed) unlike dijsktra
  // TC. O(E * V), dijsktra is better
  vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    // traverse all edges for V-1
    for (int i = 0; i < V - 1; i++) {
      for (vector<int> &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int d = edge[2];

        // relaxation
        if (dist[u] != 1e8 && dist[u] + d < dist[v]) {
          dist[v] = dist[u] + d;
        }
      }
    }

    // detect cycle
    for (vector<int> &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int d = edge[2];

      // if relaxation occurs, there is a cycle
      if (dist[u] != 1e8 && dist[u] + d < dist[v]) {
        return {-1};
      }
    }

    return dist;
  }
};
