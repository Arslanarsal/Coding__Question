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
var findBottomLeftValue = function (root) {
  let q = [];
  q.push(root);

  let res = root;
  while (q.length !== 0) {
    let temp = [];
    res = q[0];
    for (let i = 0; i < q.length; i++) {
      if (q[i].left !== null) {
        temp.push(q[i].left);
      }
      if (q[i].right !== null) {
        temp.push(q[i].right);
      }
    }
    q = temp;
  }
  return res.val;
};
