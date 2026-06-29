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

// solve; tree becomes balanced if abs(left - right) <= 1;
class Solution {
public:
  int height(TreeNode *root) {
    if (!root)
      return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    // 1 for the edge
    return max(lh, rh) + 1;
  }

  // find the heights and check the abs difference
  // then check if left and right both are balanced
  bool isBalanced(TreeNode *root) {
    if (!root)
      return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1)
      return false;

    return isBalanced(root->left) && isBalanced(root->right);
  }
};
