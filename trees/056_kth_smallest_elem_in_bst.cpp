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

// what does returning refer to in recursive call
// this is a preorder traversal as it gives ascending order of a binary tree
// solve; think about k and how will you structure the dfs recursive call
class Solution {
  int counter = 0;
  int ans = -1;

private:
  bool dfs(TreeNode *root, int k) {
    if (!root)
      return false;

    if (dfs(root->left, k))
      return true;

    counter++;
    if (counter == k) {
      ans = root->val;
      return true;
    }

    if (dfs(root->right, k))
      return true;

    return false;
  }

public:
  int kthSmallest(TreeNode *root, int k) { return dfs(root, k) ? ans : -1; }
};
