function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

var addTwoNumbers = function (l1, l2) {
  let carray = 0;
  let dumy = new ListNode(0);
  let current = dumy;
  while (l1 || l2) {
    let value1 = l1 ? l1.val : 0;
    let value2 = l2 ? l2.val : 0;

    let sum = value1 + value2 + carray;

    current.next = new ListNode(Math.floor(sum % 10));
    current = current.next;
    carray = Math.floor(sum / 10);
    l1 = l1 ? l1.next : null;
    l2 = l2 ? l2.next : null;
  }
  if (carray) {
    current.next = new ListNode(carray);
  }
  return dumy.next;
};
