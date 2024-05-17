/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/* @param {TreeNode} root
 * @return {string}
 */
var serialize = function (root) {
  let ans = "";
  if (!root) {
    return ans;
  }
  let arr = [];
  arr.push(root);
  while (arr.length) {
    const t = arr.length;
    for (let i = 0; i < t; i++) {
      let node = arr.shift();
      if (node) {
        ans = ans + node.val.toString() + ",";
      } else {
        ans = ans + "#,";
      }
      if (node) {
        arr.push(node.left);
        arr.push(node.right);
      }
    }
  }
  return ans;
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function (data) {
  if (!data) {
    return null;
  }
  let arr = data.split(",");
  if (arr[0] === "#") {
    return null;
  }
  let root = new TreeNode(parseInt(arr[0]));
  let q = [];
  q.push(root);
  let i = 1;
  while (q.length && i < arr.length) {
    let node = q.shift();
    if (arr[i] !== "#") {
      node.left = new TreeNode(parseInt(arr[i]));
      q.push(node.left);
    }
    i++;
    if (arr[i] !== "#") {
      node.right = new TreeNode(parseInt(arr[i]));
      q.push(node.right);
    }
    i++;
  }
  return root;
};
