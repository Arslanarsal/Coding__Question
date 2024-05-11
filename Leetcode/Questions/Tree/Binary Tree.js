

var lowestCommonAncestor = function (root, p, q) {
    if (!root) {
        return null;
    }
    if (root === p || root === q) {
        return root;
    }
    let left = lowestCommonAncestor(root.left, p, q);
    let right = lowestCommonAncestor(root.right, p, q);
    if (left && right) {
        return root;
    }
    if (!left && !right) {
        return null;
    }
    return (left || right);
};