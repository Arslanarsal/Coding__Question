function ListNode(val) {
  this.val = val;
  this.next = null;
}

var getIntersectionNode = function (headA, headB) {
  let n1 = 0,
    n2 = 0;
  let temp1 = headA,
    temp2 = headB;
  while (temp1 || temp2) {
    if (temp1) {
      n1++;
      temp1 = temp1.next;
    }
    if (temp2) {
      n2++;
      temp2 = temp2.next;
    }
  }
  (temp1 = headA), (temp2 = headB);
  let diff = Math.max(n1, n2) - Math.min(n1, n2);
  if (n1 > n2) {
    while (diff) {
      temp1 = temp1.next;
      diff--;
    }
  } else {
    while (diff) {
      temp2 = temp2.next;
      diff--;
    }
  }
  while (temp1) {
    if (temp1.val == temp2.val) {
      return temp1;
    }
    temp1 = temp1.next;
    temp2 = temp2.next;
  }
  return null;
};
