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

// solve; perform any traversal and put a delimiter in that
// on deserialize, deserialize accordingly

// mistake; don't forget the root null case

// TODO: try doing this recursively using DFS
class Codec {
public:
  // Encodes a tree to a single string.
  // level order traversal
  string serialize(TreeNode *root) {
    string str = "";

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      if (node == NULL) {
        str += "#,";
        continue;
      }

      str += to_string(node->val) + ",";

      q.push(node->left);
      q.push(node->right);
    }

    return str;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    stringstream s(data);
    string str;
    getline(s, str, ',');

    if (str == "#")
      return NULL;

    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      getline(s, str, ',');
      if (str == "#")
        node->left = NULL;
      else {
        TreeNode *newNode = new TreeNode(stoi(str));
        node->left = newNode;
        q.push(newNode);
      }

      getline(s, str, ',');
      if (str == "#")
        node->right = NULL;
      else {
        TreeNode *newNode = new TreeNode(stoi(str));
        node->right = newNode;
        q.push(newNode);
      }
    }

    return root;
  }
};
