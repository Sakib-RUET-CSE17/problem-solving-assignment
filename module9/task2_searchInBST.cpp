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

TreeNode *searchBST(TreeNode *root, int val) {
  if (!root || root->val == val) {
    return root;
  }
  if (root->val > val) {
    return searchBST(root->left, val);
  }
  return searchBST(root->right, val);
}

// for printing the tree
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
  vector<int> tree{4, 2, 7, 1, 3};
  int val = 2;

  TreeNode *root = nullptr;
  constructTree(tree, 0, root);

  TreeNode *res = searchBST(root, val);

  bfs(res); // for printing the tree
  return 0;
}

/*
Complexity:
Time: O(log n), for searching in BST
Space: O(n), for storing the tree
*/