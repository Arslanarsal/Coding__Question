var isEvenOddTree = function (root) {
  let q = [];
  q.push(root);
  let flage = true;
  while (q.length > 0) {
    let temp = [];
    let pre = -1;
    for (let i = 0; i < q.length; i++) {
      let it = q[i];
      if (flage && (!(it.val & 1) || (pre != -1 && pre >= it.val))) {
        return false;
      }
      else if (!flage && ((it.val & 1) || (pre != -1 && pre <= it.val))) {
        return false;
      }
      pre = it.val;
      if (it.left) {
        temp.push(it.left);
      }
      if (it.right) {
        temp.push(it.right);
      }
    }
    flage = !flage;
    q = temp;
  }
  return true;
};
