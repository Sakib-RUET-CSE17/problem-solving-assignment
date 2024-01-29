#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void constructTree(vector<int> &tree, int rootIndex, TreeNode *(&root)) {
  if (rootIndex >= tree.size() || !tree[rootIndex]) {
    return;
  }

  root = new TreeNode(tree[rootIndex]);

  int left = 2 * rootIndex + 1;
  constructTree(tree, left, root->left);

  int right = left + 1;
  constructTree(tree, right, root->right);
}

int maxDepth(TreeNode *root) {
  if (!root) {
    return 0;
  }
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
  vector<int> tree{3, 9, 20, NULL, NULL, 15, 7};

  TreeNode *root = nullptr;
  constructTree(tree, 0, root);

  cout << maxDepth(root) << endl;
  return 0;
}

/*
Complexity:
Time: O(n), where n is the number of nodes in the tree
Space: O(n), for storing the tree
*/