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
  // check for both leftA and rightA
  // base; if root is NULL; if One of it is defined if both are defined
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // base case; if not root or if either of nodes is equal to root
    if (!root || root == p || root == q)
      return root;

    TreeNode *leftA = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightA = lowestCommonAncestor(root->right, p, q);

    // Three Cases
    if (leftA && rightA)
      return root;

    if (leftA)
      return leftA;

    return rightA;
  }
};
