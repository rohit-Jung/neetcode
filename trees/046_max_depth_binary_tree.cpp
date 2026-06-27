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
  // depth in a tree so DFS
  // can use custom stack or system stack(recursive)
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;

    // above will eventually return 0 so no need left and right check
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
  }

  // you can do it iteratively too ?
  int maxDepthIt(TreeNode *root) {
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    int maxHeight = 0;
    while (!st.empty()) {
      auto [node, depth] = st.top();
      st.pop();

      if (node) {
        maxHeight = max(maxHeight, depth);
        st.push({node->left, depth + 1});
        st.push({node->right, depth + 1});
      }
    }

    return maxHeight;
  }

  // TODO: you can use BFS Too
};
