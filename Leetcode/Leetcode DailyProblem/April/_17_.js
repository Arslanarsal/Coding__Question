function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}



var smallestFromLeaf = function (root) {
    let ans = "";

    function dfs(root, cur) {
        if (!root) {
            return;
        }
        cur = String.fromCharCode(97 + root.val) + cur;
        if (!root.left && !root.right) {
            if (cur == "" || cur < ans) {
                ans = cur;
            }
            return;
        }
        dfs(root.left, cur);
        dfs(root.right, cur);

    }
    dfs(root , "");
    return ans;
};