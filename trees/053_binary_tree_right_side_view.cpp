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

// solve; go through BFS the last elem on each level is the right side view
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> sol;
    if (!root)
      return sol;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      TreeNode *node = NULL;
      while (size--) {
        node = q.front();
        q.pop();

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      // push the last node to solution;
      sol.push_back(node->val);
    }

    return sol;
  }
};
