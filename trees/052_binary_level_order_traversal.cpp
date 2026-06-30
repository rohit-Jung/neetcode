#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// simple BFS
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> sol;
    if (!root)
      return sol;

    // VISITED array is not necessary as it's a binary tree no cycles are there
    // unordered_map<TreeNode *, bool> visited;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> nodes;
      while (size--) {
        TreeNode *node = q.front();
        q.pop();
        nodes.push_back(node->val);

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      sol.push_back(nodes);
      nodes.clear();
    }

    return sol;
  }
};
