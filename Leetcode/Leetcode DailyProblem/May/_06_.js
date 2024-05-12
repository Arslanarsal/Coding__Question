/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

function reverse(head) {
    let pre = null;
    let cur = head;
    let next;
    while (cur) {
        next = cur.next;
        cur.next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

function solve(head) {
    let num = head.val;

    while (head && head.next) {
        if (head.next.val < num) {
            head.next = head.next.next;
        }
        else {
            head = head.next;
            num = head.val;
        }
    }
    return;
}

var removeNodes = function (head) {
    let newhead = reverse(head);
    solve(newhead);
    return reverse(newhead);
};