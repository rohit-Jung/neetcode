#include <bits/stdc++.h>
using namespace std;

/**
  intution: make the graph travese through them
  increase the count per traversal
 **/
class Solution {
private:
  void dfs(unordered_map<int, vector<int>> &adjs, vector<bool> &visited,
           int node) {
    visited[node] = true;

    // traverse through the neigh
    for (auto &v : adjs[node]) {
      if (!visited[v]) {
        dfs(adjs, visited, v);
      }
    }
  }

public:
  int countComponents(int n, vector<vector<int>> &edges) {

    // make undirected graph repr
    unordered_map<int, vector<int>> adjs;
    for (auto &edge : edges) {
      int a = edge[0];
      int b = edge[1];

      adjs[a].push_back(b);
      adjs[b].push_back(a);
    }

    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(adjs, visited, i);
        ans += 1;
      }
    }

    return ans;
  }
};
