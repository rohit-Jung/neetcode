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
  // conditions on where tree isn't same
  // both left and right should be same for both trees
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p->val != q->val)
      return false;
    if (!p || !q)
      return false;
    if (!q && !p)
      return true;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
