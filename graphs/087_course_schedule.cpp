#include <bits/stdc++.h>
using namespace std;

/**
  solve:
  make a graph out of the given prerequisites
  if it's cyclic graph it's impossible else maybe possible

  **Directed Graph Cycle Detection**
  BFS or DFS: Kahn's algorithm

  Topological Sort: u -> v <- x | x, u, v or u, x, v
  so we get topological order if we don't have cycle (D.A.G)

  indegree: how many arrow on edge
  indegree 0 first that in topological sort order
 **/
class Solution {
private:
  // TODO: solve this using DFS too
  bool topologicalSortCheckBFS(unordered_map<int, vector<int>> &adj,
                               int numCourses, vector<int> indegree) {

    queue<int> q;
    int count = 0;

    // fill que with indegree 0
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        count++;
        q.push(i);
      }
    }

    // do a bfs
    while (!q.empty()) {
      // get the first node index with indegree 0
      int f = q.front();
      q.pop();

      // traverse through neighbors
      for (auto &v : adj[f]) {
        // you have visited
        indegree[v]--;

        if (indegree[v] == 0) {
          count++;
          q.push(v);
        }
      }
    }

    // we have traversed all nodes
    if (count == numCourses)
      return true;

    return false;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> indegree(numCourses, 0);
    unordered_map<int, vector<int>> adj;

    // make the adj representation and fill in indegree
    for (auto &vec : prerequisites) {
      int a = vec[0];
      int b = vec[1];

      // b --> a
      adj[b].push_back(a);

      // indegree
      indegree[a]++;
    }

    return topologicalSortCheckBFS(adj, numCourses, indegree);
  }
};
