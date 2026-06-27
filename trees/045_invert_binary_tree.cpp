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

class Solution {
public:
  // similar to swap a number / char
  // but you should recursively call
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return NULL;

    if (root->left)
      invertTree(root->left);
    if (root->right)
      invertTree(root->right);

    // swap nodes
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    return root;
  }
};
