/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @return {TreeNode}
 */
var bstFromPreorder = function (preorder) {
  let index = { value: 0 }; // Wrap 'i' inside an object

  function solve(preorder, bound, index) {
    if (index.value === preorder.length || preorder[index.value] > bound) {
      return null;
    }
    let root = new TreeNode(preorder[index.value++], null, null);
    root.left = solve(preorder, root.val, index); // Pass 'index' to recursive calls
    root.right = solve(preorder, bound, index); // Pass 'index' to recursive calls
    return root;
  }

  return solve(preorder, Number.MAX_SAFE_INTEGER, index); // Pass 'index' initially
};

// #include <bits/stdc++.h>
// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution
// {
//     TreeNode *solve(vector<int> &a, int i, int bound)
//     {
//         if (i == a.size() || a[i] > bound)
//         {
//             return nullptr;
//         }
//         TreeNode *root = new TreeNode(a[i++]);
//         root->left = solve(a, i, root->val);
//         root->right = solve(a, i, bound);
//         return root;
//     }

// public:
//     TreeNode *bstFromPreorder(vector<int> &preorder)
//     {
//         return solve(preorder, 0, INT_MAX);
//     }
// };

// int main()
// {

//     return 0;
// }
