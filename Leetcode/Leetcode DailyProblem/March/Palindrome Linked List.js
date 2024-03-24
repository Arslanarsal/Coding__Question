/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function (head) {
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
  while (pre !== null) {
    if (head.val !== pre.val) {
      return false;
    }
    head = head.next;
    pre = pre.next;
  }
  return true;
};
