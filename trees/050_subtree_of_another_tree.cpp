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

// sol; check if it's the same tree on left and right if either is tree it's a
// base; check if both are null; one is null or if its Subtree
class Solution {
private:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true;
    if (!p || !q)
      return false;
    if (p->val != q->val)
      return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root && !subRoot)
      return true;
    if (!root || !subRoot)
      return false;

    if (isSameTree(root, subRoot)) {
      return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};
