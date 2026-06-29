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

// solve; rescursively find the left and right height of tree and update the
// result accordingly and return the best to above calls
class Solution {
private:
  // mistake; pass by reference the result to get updated on result calls
  int solve(TreeNode *root, int &result) {
    if (!root)
      return 0;
    int left = solve(root->left, result);
    int right = solve(root->right, result);
    // update the result, with prev and left+right
    result = max(result, left + right);
    // 1 is for the upper edge;
    return 1 + max(left, right);
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;
    int result = INT_MIN;
    solve(root, result);
    return result;
  }
};
