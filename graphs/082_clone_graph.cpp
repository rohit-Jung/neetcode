#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

/**
  solve; use the map or vec to keep track of real -> cloned nodes
  use that to find if it already has been cloned and use DFS or BFS to traverse
  and connect the nodes
  **/
class Solution {
private:
  // approach1: using bfs
  // clone it's neighbour and their neighbours recursive
  // if the node reappears we need to access it; so need a map
  void dfs(Node *node, Node *clonedNode, vector<Node *> &visited) {
    // add visited
    visited[node->val] = clonedNode;

    // visit the neigbors
    for (Node *n : node->neighbors) {
      // map doesn't  contain, clone, add neigh, traverse neigh
      if (!visited[n->val]) {
        Node *clonedN = new Node(n->val);
        clonedNode->neighbors.push_back(clonedN);

        // traverse
        dfs(n, clonedN, visited);
      } else {
        // just add the neighbor
        clonedNode->neighbors.push_back(visited[n->val]);
      }
    }
  }

  // approach2: using dfs ; mistake; you should connect clonedNode neighbors,
  // since this isn't recursive becareful
  void bfs(Node *node, Node *clonedNode, vector<Node *> &visited) {
    queue<Node *> q;

    q.push(node);
    visited[node->val] = clonedNode;

    while (!q.empty()) {
      Node *topN = q.front();
      q.pop();

      // get the clone Node
      Node *clonedCurr = visited[topN->val];

      for (Node *n : topN->neighbors) {
        // if current neighbor isn't visited
        if (!visited[n->val]) {
          Node *clonedN = new Node(n->val);
          clonedCurr->neighbors.push_back(clonedN);

          // mark it visited
          visited[n->val] = clonedN;
          // equi to calling dfs in dfs()
          q.push(n);
        } else {
          clonedCurr->neighbors.push_back(visited[n->val]);
        }
      }
    }
  }

public:
  Node *cloneGraph(Node *node) {
    // base check
    if (!node)
      return nullptr;

    // given so ; 1 <= Node.val <= 100; mp [val] -> ClonedNode*
    vector<Node *> mp(101, nullptr);

    // clone the given node
    Node *clonedNode = new Node(node->val);

    // visit and reconstruct the neighbors
    bfs(node, clonedNode, mp);

    return clonedNode;
  }
};
