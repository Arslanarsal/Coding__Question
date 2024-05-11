var widthOfBinaryTree = function (root) {
    if (!root) return 0;

    let arr = [{ node: root, position: 0 }];
    let maxWidth = 1;

    while (arr.length) {
        let size = arr.length;
        let leftmost = arr[0].position;
        let rightmost = arr[size - 1].position;
        maxWidth = Math.max(maxWidth, rightmost - leftmost + 1);

        for (let i = 0; i < size; i++) {
            let { node, position } = arr.shift();

            if (node.left) {
                arr.push({ node: node.left, position: position - leftmost * 2 });
            }
            if (node.right) {
                arr.push({ node: node.right, position: position -leftmost * 2 + 1 });
            }
        }
    }

    return maxWidth;
};
