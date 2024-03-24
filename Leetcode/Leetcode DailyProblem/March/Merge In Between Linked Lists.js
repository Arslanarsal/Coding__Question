/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {number} a
 * @param {number} b
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeInBetween = function (list1, a, b, list2) {
    let temp = list1;
    let n = 1;
    while (n < a) {
        temp = temp.next;
    }
    let temp2 = temp.next;
    temp.next = list2;
    while (temp.next !== null) {
        temp = temp.next;
    }
    while (n < b +2) {
        temp2 = temp2.next;
    }
    temp.next = temp2;
    return list1;
};