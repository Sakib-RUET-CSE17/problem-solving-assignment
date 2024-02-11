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

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
  if (!root1) {
    return root2;
  }
  if (!root2) {
    return root1;
  }
  root1->val += root2->val;
  root1->left = mergeTrees(root1->left, root2->left);
  root1->right = mergeTrees(root1->right, root2->right);
  return root1;
}

void bfs(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  queue<TreeNode *> stk;
  stk.push(root);

  while (!stk.empty()) {
    root = stk.front();
    stk.pop();
    cout << root->val << " ";

    if (root->left) {
      stk.push(root->left);
    }
    if (root->right) {
      stk.push(root->right);
    }
  }
  cout << endl;
}

int main() {
  vector<int> tree1{1, 3, 2, 5};
  vector<int> tree2{2, 1, 3, NULL, 4, NULL, 7};

  TreeNode *root1 = nullptr;
  TreeNode *root2 = nullptr;
  constructTree(tree1, 0, root1);
  constructTree(tree2, 0, root2);

  TreeNode *merged = mergeTrees(root1, root2);

  bfs(merged); // print tree
  return 0;
}

/*
Complexity:
Time: O(m). Here, m represents the minimum number of nodes from the two given
trees.
Space: O(m). The depth of the recursion tree can go upto m in the case of
a skewed tree. In average case, depth will be O(logm).
*/