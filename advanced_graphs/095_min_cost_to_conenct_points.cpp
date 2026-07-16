#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
  // TODO: do it using Kruskal's and matrix
  // dist, node
  typedef pair<int, int> P;

  int PrimsAlgo(vector<vector<P>> &adjs, int V) {
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<bool> visited(V, false);

    int sum = 0;

    // the origin
    pq.push({0, 0}); // { weight, vertex }

    while (!pq.empty()) {
      auto [dist, node] = pq.top();
      pq.pop();

      if (visited[node])
        continue;

      // mark it visited and calculate the sum
      visited[node] = true;
      sum += dist;

      for (auto &[neigh_wt, neigh] : adjs[node]) {
        if (!visited[neigh])
          pq.push({neigh_wt, neigh});
      }
    }

    return sum;
  }

public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    // build an adjacency list graph with distance as cost
    int V = points.size();

    vector<vector<P>> adjs(points.size());
    for (int i = 0; i < V; i++) {
      for (int j = i + 1; j < V; j++) {
        int x1 = points[i][0];
        int y1 = points[i][1];

        int x2 = points[j][0];
        int y2 = points[j][1];

        int dist = abs(x2 - x1) + abs(y2 - y1);
        adjs[i].push_back({dist, j});
        adjs[j].push_back({dist, i});
      }
    }

    return PrimsAlgo(adjs, V);
  }
};
