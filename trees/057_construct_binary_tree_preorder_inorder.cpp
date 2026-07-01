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

// concept; inorder traversal gives us the root and preorder tells what left and
// what right child would be
// recursively; put left and right child; keep eliminating from the inorder
// mistake; be very careful about the indexing on vectors
class Solution {
  // map for indices storing
  // you can also use the for loop but that would be O(n2)
  unordered_map<int, int> mp;

private:
  TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &idx,
                  int start, int end) {
    if (start > end)
      return NULL;

    int rootVal = preorder[idx];
    idx++;
    TreeNode *root = new TreeNode(rootVal);

    int i = mp[rootVal];

    root->left = solve(preorder, inorder, idx, start, i - 1);
    root->right = solve(preorder, inorder, idx, i + 1, end);

    return root;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int idx = 0;
    for (int i = 0; i < inorder.size(); i++) {
      mp[inorder[i]] = i;
    }

    return solve(preorder, inorder, idx, 0, inorder.size() - 1);
  }
};
