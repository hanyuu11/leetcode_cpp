#include <algorithm>
#include <iostream>
#include <numeric>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

TreeNode* createTree(const std::vector<std::optional<int>>& values) {
  if (values.empty() || !values[0].has_value()) {
    return nullptr;
  }

  TreeNode* root = new TreeNode(*values[0]);
  std::queue<TreeNode*> q;
  q.push(root);

  size_t index = 1;

  while (!q.empty() && index < values.size()) {
    TreeNode* cur = q.front();
    q.pop();

    // 左孩子
    if (index < values.size() && values[index].has_value()) {
      cur->left = new TreeNode(*values[index]);
      q.push(cur->left);
    }
    ++index;

    // 右孩子
    if (index < values.size() && values[index].has_value()) {
      cur->right = new TreeNode(*values[index]);
      q.push(cur->right);
    }
    ++index;
  }

  return root;
}

void freeTree(TreeNode* root) {
  if (root == nullptr) {
    return;
  }

  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

class Solution {
 public:
  int ans = 0;

  std::pair<int, int> dfs(TreeNode* root) {
    if (root == nullptr) {
      return {0, 0};
    }

    std::pair<int, int> left = dfs(root->left);
    std::pair<int, int> right = dfs(root->right);

    int sum = left.first + right.first + root->val;
    int count = left.second + right.second + 1;
    if (sum / count == root->val) {
      ++ans;
    }

    return {sum, count};
  }

  int averageOfSubtree(TreeNode* root) {
    dfs(root);
    return ans;
  }
};

int main() {
    std::vector<std::optional<int>> vals = {
        4, 8, 5, 0, 1, std::nullopt, 6
    };
    TreeNode* root = createTree(vals);
    Solution sl;
    int ans = sl.averageOfSubtree(root);
    std::cout << ans << "\n";
    freeTree(root);
}
