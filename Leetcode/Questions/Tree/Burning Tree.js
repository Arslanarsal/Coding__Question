class Solution {
  minTime(root, num) {
    function findnode(root, num) {
      if (!root) {
        return null;
      }
      if (root.key === num) {
        return root;
      }

      let left = findnode(root.left, num);
      if (left) {
        return left;
      }
      let right = findnode(root.right, num);
      if (right) {
        return right;
      }
      return left || right;
    }

    function parent(root, mp) {
      let q = [];
      q.push(root);
      while (q.length) {
        const t = q.length;
        for (let i = 0; i < t; i++) {
          let node = q.shift();
          if (node.left) {
            mp.set(node.left, node);
            q.push(node.left);
          }
          if (node.right) {
            mp.set(node.right, node);
            q.push(node.right);
          }
        }
      }
    }

    let mp = new Map();
    parent(root, mp);
    let visit = new Map();
    let target = findnode(root, num);

    visit.set(target, true);
    let q = [];
    q.push(target);
    let j = 0;
    while (q.length) {
      j++;
      const t = q.length;
      for (let i = 0; i < t; i++) {
        let node = q.shift();
        if (node.left && !visit.get(node.left)) {
          visit.set(node.left, true);
          q.push(node.left);
        }
        if (node.right && !visit.get(node.right)) {
          visit.set(node.right, true);
          q.push(node.right);
        }
        if (mp.get(node) && !visit.get(mp.get(node))) {
          visit.set(mp.get(node), true);
          q.push(mp.get(node));
        }
      }
    }

    return j;
  }
}
