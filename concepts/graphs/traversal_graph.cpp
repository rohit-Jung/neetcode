#include <bits/stdc++.h>
#include <vector>
using namespace std;

/**
  traversal:

  using BFS:
    level wise/ ripple so you use a queue (fairness)
    O(v + e) as you visit every vertex and edge once , O(v) the queue size

  using DFS:
    depth first: ->-> stack or system stack(recursion)
    same T.C. S.C
 **/
class Solution {
private:
  void performDFS(vector<vector<int>> &adj, vector<bool> &visited,
                  vector<int> &result, int start) {
    // if it's visited then return
    if (visited[start])
      return;

    result.push_back(start);
    visited[start] = true;

    // go through neighbours of u
    for (int &v : adj[start]) {
      performDFS(adj, visited, result, v);
    }

    // for matrix it would be
    // for (int v = 0; v < n; v++) {
    //   if (matrix[u][v] == 1 && !visited[v]) {
    //     dfs(v);
    //   }
    // }
  }

  // use a queue
  void performBFS(vector<vector<int>> &adj, int source, vector<bool> &vis,
                  vector<int> &result) {
    queue<int> q;

    q.push(source);
    vis[source] = true;
    result.push_back(source);

    while (!q.empty()) {
      int f = q.front();
      q.pop();

      // traverse the connected nodes
      for (auto &v : adj[f]) {
        // only if not visited
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
          result.push_back(v);
        }
      }
    }
  }

public:
  // adj list representation only
  vector<int> dfs(vector<vector<int>> &adj) {
    // Code here
    vector<bool> visited(adj.size(), false);
    vector<int> result;

    // start with first node
    performDFS(adj, visited, result, 0);
    return result;
  }

  // adj list bfs
  vector<int> bfs(vector<vector<int>> &adj) {
    // number of rows is the visited size ?
    vector<bool> visited(adj.size(), false);
    vector<int> result;

    // start from first node
    performBFS(adj, 0, visited, result);
    return result;
  }
};
