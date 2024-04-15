// struct TreeNode
// {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution
// {
//   void sumNumbers(TreeNode *root, int temp, int &ans)
//   {
//     if (!root->left && root->right)
//     {
//       temp = (temp * 10) + root->val;
//       ans += temp;
//       return;
//     }
//     temp = (temp * 10) + root->val;
//     sumNumbers(root->left, temp, ans);
//     sumNumbers(root->right, temp, ans);
//     return;
//   }

// public:
//   int sumNumbers(TreeNode *root)
//   {
//     int ans = 0;
//     sumNumbers(root, 0, ans);
//     return ans;
//   }
// };

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

var sumNumbers = function (root, temp, ans) {
  if (!root) {
    return;
  }
  if (!root.left && !root.right) {
    temp = temp * 10 + root.val;
    ans = ans + temp;
    return;
  }
  temp = temp * 10 + root.val;
  sumNumbers(root.left, temp, ans);
  sumNumbers(root.right, temp, ans);
  return;
};

var sumNumbers = function (root) {
    let ans =0;
    sumNumbers(root , 0, ans);
    return ans;
};
