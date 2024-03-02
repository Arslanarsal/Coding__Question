/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

let ans = 0;
function f(root) {
  if (!root) {
    return 0;
  }
  if (root.left == null && root.right == null) {
    return 1;
  }
  let left = f(root.left);
  let right = f(root.right);
  ans = Math.max(ans, left + right);
  return 1 + Math.max(left, right);
}
var diameterOfBinaryTree = function (root) {
  f(root);
  return ans;
};
