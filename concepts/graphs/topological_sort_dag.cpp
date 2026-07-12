#include <bits/stdc++.h>
using namespace std;

/**
  topological sort
    if u --> v, then v comes later than u 
    only possible in DAG 

 **/
class Solution {
private:
  // topological Sort DFS
  void topoSortDFS(stack<int> &st, vector<vector<int>> &adj,
                   vector<bool> &visited, int node) {
    visited[node] = true;

    // visit each neigbour
    for (auto &v : adj[node]) {
      if (!visited[v]) {
        topoSortDFS(st, adj, visited, v);
      }
    }

    st.push(node);
  }

  // topological sort BFS: Kahn's algo
  vector<int> topoSortBFS(vector<vector<int>> &adj, vector<int> &indegree,
                          int n) {
    queue<int> q;
    vector<int> sorted;

    // fill the que with indegree 0
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        sorted.push_back(i);
        q.push(i);
      }
    }

    while (!q.empty()) {
      int f = q.front();
      q.pop();

      for (auto &v : adj[f]) {
        indegree[v]--;

        // if indegree becomes zero
        if (indegree[v] == 0) {
          sorted.push_back(v);
          q.push(v);
        }
      }
    }

    // all nodes covered
    if (sorted.size() == n)
      return sorted;

    // cycle was found
    return {};
  }

public:
  vector<int> topoSort(int V, vector<vector<int>> &edges) {
    // code here
    vector<bool> visited(V, false);

    vector<vector<int>> adj(V);
    for (auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }
    stack<int> st;

    for (int i = 0; i < V; i++) {
      // if it's not visted and its a cycle then its a cycle
      if (!visited[i])
        topoSortDFS(st, adj, visited, i);
    }

    // get elems from stack
    vector<int> sol;
    while (!st.empty()) {
      sol.push_back(st.top());
      st.pop();
    }

    return sol;
  }

  vector<int> topoBFS(int V, vector<vector<int>> &edges) {
    // code here
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    for (auto &edge : edges) {
      int a = edge[0];
      int b = edge[1];

      // a --> b
      adj[a].push_back(b);

      // b has the ->
      indegree[b]++;
    }

    return topoSortBFS(adj, indegree, V);
  }
};
