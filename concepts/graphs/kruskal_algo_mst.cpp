#include <bits/stdc++.h>
using namespace std;

/**
Kruskal uses DSU to find if its same component of graph while
traversing through the vector with u, v and w

firstly it sorts the vec using the weights and then it starts
processing from the smallest ones that is in front
**/
class Solution {
private:
  int find(int n, vector<int> &parent) {
    if (parent[n] == n)
      return n;

    // path compression
    return parent[n] = find(parent[n], parent);
  }

  bool dsu(int x, int y, vector<int> &parent, vector<int> &rank) {
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if (x_parent == y_parent)
      return true;

    // greater rank becomes parent; as always
    if (rank[x_parent] < rank[y_parent]) {
      parent[x_parent] = y_parent;
    } else if (rank[y_parent] < rank[x_parent]) {
      parent[y_parent] = x_parent;
    } else {
      parent[y_parent] = x_parent;
      rank[x_parent]++;
    }

    return false;
  }

  int kruskalAlgo(vector<vector<int>> &vec, int V) {
    vector<int> rank(V, 0);

    // make a parent vec
    vector<int> parent(V);
    for (int i = 0; i < V; i++)
      parent[i] = i;

    int sum = 0;

    // process them one by one  and add to sum
    for (vector<int> &temp : vec) {
      int u = temp[0];
      int v = temp[1];
      int d = temp[2];

      if (!dsu(u, v, parent, rank))
        sum += d;
    }

    return sum;
  }

public:
  int spanningTree(int V, vector<vector<int>> &edges) {

    // make a graph
    vector<vector<int>> vec;

    //  E edges copying - O(E)
    for (auto &edge : edges) {
      int a = edge[0];
      int b = edge[1];
      int w = edge[2];

      // undirected graph
      vec.push_back({a, b, w});
    }

    // sort it on the basis of weight
    auto comparator = [](const vector<int> &first, const vector<int> &second) {
      return first[2] < second[2];
    };

    // sorting O(E logE)
    sort(begin(vec), end(vec), comparator);
    // dsu: dsu on all Edges so O(E.V) 
    // since ElogE dominates TC is ElogE
    return kruskalAlgo(vec, V);
  }
};
