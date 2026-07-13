#include <bits/stdc++.h>
#include <vector>
using namespace std;

/**
  solve: perform a DSU
  if you find two edge belonging to same set
  that's the ans vector
  **/
class Solution {
private:
  int find(int x, vector<int> &parent) {
    if (parent[x] == x)
      return x;
    // path compression
    return parent[x] = find(parent[x], parent);
  }

  // perform a dsu
  bool dsu(int x, int y, vector<int> &parent, vector<int> &rank) {
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    // belongs to same set
    if (x_parent == y_parent)
      return true;

    // check the rank
    if (rank[x_parent] > rank[y_parent]) {
      parent[y_parent] = x_parent;
    } else if (rank[y_parent] > rank[x_parent]) {
      parent[x_parent] = y_parent;
    } else {
      parent[x_parent] = y_parent;
      rank[y_parent]++;
    }

    return false;
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> parent(n + 1);
    vector<int> rank(n + 1);

    for (int i = 1; i <= edges.size(); i++) {
      parent[i] = i;
    }

    for (auto &edge : edges) {
      int a = edge[0];
      int b = edge[1];

      // perform dsu
      if (dsu(a, b, parent, rank)) {
        return {a, b};
      }
    }

    return {};
  }
};
