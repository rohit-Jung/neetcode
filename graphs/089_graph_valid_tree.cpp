#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

/**
  valid tree:
    no loop - undirected and all connected ?
    so traverse and check cycle, also check if traversedNodes == numberOfNodes
    must have n -1 edges

  T.C: O(V + E) - building graph + dfs
  S.C: O(V + E) -
**/
class Solution {
private:
  // dfs returns true if it has a cycle
  bool hasCycle(unordered_map<int, vector<int>> &adjs, vector<bool> &visited,
                int node, int parent, int &count) {

    visited[node] = true;
    count++;

    for (auto &v : adjs[node]) {
      // if it's parent then don't go back
      if (v == parent)
        continue;

      // if it's not parent and visited then it's a cycle
      if (visited[v])
        return true;

      // else traverse
      if (hasCycle(adjs, visited, v, node, count)) {
        return true;
      }
    }

    return false;
  }

public:
  bool validTree(int n, vector<vector<int>> &edges) {
    // make a undirected graph first
    unordered_map<int, vector<int>> adj;

    // a tree must have n-1 edges
    if (edges.size() != n - 1)
      return false;

    for (auto &v : edges) {
      int a = v[0];
      int b = v[1];

      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    int count = 0;
    vector<bool> visited(n, false);

    if (hasCycle(adj, visited, 0, -1, count)) {
      return false;
    }

    // did we traverse all ?
    return count == n;
  }
};
