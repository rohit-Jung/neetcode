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

// solve; so each node would give me it's path sum by finding it's left one and
// right one; consider three cases where both are positive sum, both are
// negative or only one of them is negative, which one to pick on when
// careful; that you need not send the umbrella path
class Solution {
private:
  int solve(TreeNode *root, int &maxVal) {
    if (!root)
      return 0;

    int leftSum = solve(root->left, maxVal);
    int rightSum = solve(root->right, maxVal);

    // three cases
    int bothPositive = leftSum + rightSum + root->val;
    int bothNegative = root->val;
    int onlyOnePositive = max(leftSum, rightSum);

    // update the maxVal
    maxVal = max({maxVal, bothPositive, bothNegative, onlyOnePositive});
    // you cannot return both Positive as it creates umbrella path
    return max(bothNegative, onlyOnePositive);
  }

  // this is exact same solution but abit complex implementation
  int dfs(TreeNode *root, int &maxVal) {
    if (!root)
      return 0;

    int leftSum = max(0, dfs(root->left, maxVal));
    int rightSum = max(0, dfs(root->left, maxVal));

    // update the maxVal
    maxVal = max(maxVal, leftSum + rightSum + root->val);
    return max(leftSum, rightSum) + root->val;
  }

public:
  int maxPathSum(TreeNode *root) {
    int maxVal = INT_MIN;
    dfs(root, maxVal);
    return maxVal;
  }
};
