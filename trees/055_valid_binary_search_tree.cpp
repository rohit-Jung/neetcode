#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// mistake; check for equals to case also
// solve; lower bound and upper bound should be tested meaning
// ask; for the current node if i go left what would be my lowerBound and
// upperBound
class Solution {
private:
  bool checkValid(TreeNode *root, int lowerBound, int upperBound) {
    if (!root)
      return true;

    if (root->val <= lowerBound || root->val >= upperBound) {
      return false;
    }

    return checkValid(root->left, lowerBound, root->val) &&
           checkValid(root->right, root->val, upperBound);
  }

public:
  bool isValidBST(TreeNode *root) { return checkValid(root, INT_MIN, INT_MAX); }
};
