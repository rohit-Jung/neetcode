#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> rank;
  int performFind(int x, vector<int> &parent) {
    // same node parent  base cond
    if (parent[x] == x)
      return x;

    // path compression `parent[x]` and find other parent
    return parent[x] = performFind(parent[x], parent);
  }

  void performUnion(int x, int y, vector<int> &parent) {
    // find parents
    int x_parent = performFind(x, parent);
    int y_parent = performFind(y, parent);

    // if same parent then same set so don't do anything
    if (x_parent == y_parent) {
      return;
    }

    // rank
    if (rank[x_parent] > rank[y_parent]) {
      parent[y_parent] = x_parent;
    } else if (rank[y_parent] > rank[x_parent]) {
      // y_parent becomes parent as it has greater rank
      parent[x_parent] = y_parent;
    } else {
      parent[x_parent] = y_parent;
      // y became parent so increase it's rank
      rank[y_parent] += 1;
    }
  }
};
