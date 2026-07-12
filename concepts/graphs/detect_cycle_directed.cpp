#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

/**
  using DFS:
    topological sort (you need a stack ? first push neigh & push the node)
    using inRecursion array: v is parent and it's inRecursion is true then cycle

  using BFS(Kahn's algo):
    topological sort is only possible in DAG
    so if the sort isn't possible it's a Directed Cyclic Graph

  nodeCount == elemSize ? no: yes
  **/
class Solution {
private:
  // using inRecursion array
  bool detectCycleDFS(vector<bool> &inRecursion, vector<bool> &visited,
                      vector<vector<int>> &adjs, int node) {

    // mark visited and in inRecursion
    visited[node] = true;
    inRecursion[node] = true;

    for (auto &v : adjs[node]) {
      // if it's not visited, explore it and if there is a cycle it's true
      if (!visited[v] && detectCycleDFS(inRecursion, visited, adjs, v)) {
        return true;

        // if it's in inRecursion and visited then it's a cycle
      } else if (inRecursion[v]) {
        return true;
      }
    }

    inRecursion[node] = false;
    return false;
  }

  bool detectCycleBFS(vector<int> &indegree, vector<vector<int>> &adjs, int n) {
    int count = 0;

    queue<int> q;

    //  fill in the queue
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        q.push(i);
        count++;
      }
    }

    // go through the queue
    while (!q.empty()) {
      int f = q.front();
      q.pop();

      // visit the neigh
      for (auto &v : adjs[f]) {
        indegree[v]--;

        if (indegree[v] == 0) {
          q.push(v);
          count++;
        }
      }
    }

    // if we visited all nodes
    if (count == n)
      return false;

    return true;
  }

public:
  bool isCyclicDFS(int V, vector<vector<int>> &edges) {
    // code here
    vector<bool> visited(V, false);
    vector<bool> inRecursion(V, false);

    // make adjaceny list representation
    vector<vector<int>> adj(V);
    for (auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }

    for (int i = 0; i < V; i++) {
      // if it's not visted and its a cycle then its a cycle
      if (!visited[i] && detectCycleDFS(inRecursion, visited, adj, i))
        return true;
    }

    return false;
  }

  bool isCyclic(int V, vector<vector<int>> &edges) {

    // make adjaceny list representation
    vector<vector<int>> adjs(V);
    vector<int> indegree(V, 0);

    for (auto &edge : edges) {
      int a = edge[0];
      int b = edge[1];

      // a --> b
      adjs[a].push_back(b);
      indegree[b]++;
    }

    return detectCycleBFS(indegree, adjs, V);
  }
};
