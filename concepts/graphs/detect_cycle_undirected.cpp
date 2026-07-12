#include <bits/stdc++.h>
#include <vector>
using namespace std;

/**
  using BFS:
    you need parent too so, pair<int, int> in queue
    if it's already visited and it's not parent then it's a cycle

  using DFS:
    pass in parent in the function call
    if it's already visited and a prent then there is a cycle
**/

class Solution {
private:
  bool isCycleBFS(vector<vector<int>> &adjs, int node, int parent,
                  vector<bool> &visited) {

    queue<pair<int, int>> q;
    q.push({node, parent});
    visited[node] = true;

    while (!q.empty()) {
      auto [f, p] = q.front();
      q.pop();

      // traverse the neighbors
      for (auto &v : adjs[f]) {
        // if it's not visited and parent
        if (!visited[v]) {
          q.push({v, f});
          visited[v] = true;
          // its visited but parent is someone else
          // | parent should have been p so two parent kuch toh gadbad hai
        } else if (v != p) {
          return true;
        }
      }
    }

    return false;
  }

  bool isCycleDFS(vector<vector<int>> &adjs, int node, int parent,
                  vector<bool> &visited) {
    // mark visited
    visited[node] = true;

    // visit neighbors
    for (auto &v : adjs[node]) {
      // if it's a parent
      if (v == parent)
        continue;

      // it's visited
      if (visited[v]) {
        return true;
      }

      if (!visited[v] && isCycleDFS(adjs, v, node, visited)) {
        return true;
      }
    }

    return false;
  }

public:
  bool isCycle(int V, vector<vector<int>> &edges) {
    vector<bool> visited(V, false);
    vector<vector<int>> adjs(V);

    // undirected graph adj matrix
    for (auto &edge : edges) {
      int a = edge[0];
      int b = edge[1];

      // both directions
      adjs[a].push_back(b);
      adjs[b].push_back(a);
    }

    for (int i = 0; i < V; i++) {
      // if (!visited[i] && isCycleDFS(adjs, i, -1, visited)) {
      if (!visited[i] && isCycleBFS(adjs, i, -1, visited)) {
        return true;
      }
    }

    return false;
  }
};
