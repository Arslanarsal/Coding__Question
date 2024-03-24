var reorderList = function (head) {
  let temp = head;
  let n = 0;
  while (temp) {
    temp = temp.next;
    n++;
  }
  let n1 = Math.floor(n / 2);
  let n2 = 0;
  temp = head;
  while (n2 < n1) {
    temp = temp.next;
    n2++;
  }
  if (n % 2 === 1) {
    temp = temp.next;
  }
  let pre = null;
  let cur = temp;
  let next;
  while (cur !== null) {
    next = cur.next;
    cur.next = pre;
    pre = cur;
    cur = next;
  }

  let flag = true;
  let head2 = head;
  let check;
  while (pre) {
    if (flag) {
      temp = head2.next;
      head2.next = pre;
      head2 = temp;
      flag = false;
    } else {
      check = pre;
      temp = pre.next;
      
      if (temp) {
        pre.next = head2;
      }

      pre = temp;
      flag = true;
    }
  }
  if (n % 2 === 1) {
    head2.next = null;
    check.next = head2;
  }

  return head;
};
