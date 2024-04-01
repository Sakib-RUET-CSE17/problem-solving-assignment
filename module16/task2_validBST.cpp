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

void inorder(TreeNode *root, vector<int> &nums) {
  if (!root) {
    return;
  }
  inorder(root->left, nums);
  nums.push_back(root->val);
  inorder(root->right, nums);
}

bool isValidBST(TreeNode *root) {
  vector<int> nums;
  inorder(root, nums);
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i - 1] >= nums[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> tree{2,1,3};

  TreeNode *root = nullptr;
  constructTree(tree, 0, root);

  if (isValidBST(root)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}

/*
Complexity:
Time: O(n), where n is the number of nodes in the tree
Space: O(n)
*/