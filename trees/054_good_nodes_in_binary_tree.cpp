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

// goodNodes: nodes that doesn't have greater values in betwit root and it
// do a dfs and go through
class Solution {
private:
  int dfs(TreeNode *root, int maxValue) {
    if (!root)
      return 0;

    int goodNodeCount = 0;

    goodNodeCount = root->val >= maxValue ? 1 : 0;
    maxValue = max(maxValue, root->val);

    goodNodeCount += dfs(root->left, maxValue);
    goodNodeCount += dfs(root->right, maxValue);

    return goodNodeCount;
  }

public:
  int goodNodes(TreeNode *root) { return dfs(root, INT_MIN); }
};
