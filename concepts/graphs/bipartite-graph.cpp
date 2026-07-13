#include <bits/stdc++.h>
using namespace std;

/**
  isBipartite:
  it is a bipartite graph if we can color any two adjacent nodes with different
  colors

  observation: if it's a cycle with odd length, bipartite isn't possible
  for other graph its possible

  solve: DFS - go through graph, check neighbor equal -false, else get other
  color and check the children/neigh again with that color, check if it's false

  BFS - same checks just use the queue;
  **/
class Solution {
private:
  bool dfs(unordered_map<int, vector<int>> &adjs, vector<int> &colored,
           int curr, int currColor) {
    // color it
    colored[curr] = currColor;

    // traverse through neigh
    for (auto &v : adjs[curr]) {
      // if color is the same as adj
      if (colored[v] == colored[curr])
        return false;

      // if not colored
      if (colored[v] == -1) {
        int colorV = 1 - colored[curr]; // color is 0 and 1
        if (!dfs(adjs, colored, v, colorV)) {
          return false;
        }
      }
    }

    return true;
  }

  bool bfs(unordered_map<int, vector<int>> &adjs, vector<int> &colored,
           int curr, int currColor) {
    // make q
    queue<int> q;

    // color current
    q.push(curr);
    colored[curr] = currColor;

    while (!q.empty()) {
      int f = q.front();
      q.pop();

      for (auto &v : adjs[f]) {
        // same as adjacent color
        if (colored[v] == colored[f])
          return false;

        // if it's not colored
        if (colored[v] == -1) {
          colored[v] = 1 - colored[f]; // 0 or 1
          q.push(v);
        }
      }
    }

    return true;
  }

public:
  bool isBipartite(int V, vector<vector<int>> &edges) {
    // Code here

    // make adjs list
    unordered_map<int, vector<int>> adjs;
    for (auto &edge : edges) {
      int a = edge[0];
      int b = edge[1];

      // undirected graph
      adjs[a].push_back(b);
      adjs[b].push_back(a);
    }

    // traverse through graph if not colored
    vector<int> colored(V, -1);

    // color 0- 1

    for (int i = 0; i < V; i++) {
      if (colored[i] == -1 && !dfs(adjs, colored, i, 0)) {
        return false;
      }
    }

    return true;
  }
};
