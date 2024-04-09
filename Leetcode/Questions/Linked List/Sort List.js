function findmiddle(head) {
  let slow = head;
  let fast = head.next;
  while (fast && fast.next) {
    fast = fast.next.next;
    slow = slow.next;
  }
  return slow;
}

function merge(left, right) {
  if (!left) {
    return right;
  } else if (!right) {
    return left;
  }

  let head;
  if (left.val < right.val) {
    head = left;
    left = left.next;
  } else {
    head = right;
    right = right.next;
  }
  let temp = head;

  while (right && left) {
    if (left.val < right.val) {
      temp.next = left;
      left = left.next;
    } else {
      temp.next = right;
      right = right.next;
    }
    temp = temp.next;
  }

  if (right) {
    temp.next = right;
  } else if (left) {
    temp.next = left;
  }
  return head;
}

var sortList = function (head) {
  if (!head || !head.next) {
    return head;
  }
  let middle = findmiddle(head);
  let left = head;
  let right = middle.next;
  middle.next = null;
  left = sortList(left);
  right = sortList(right);
  return merge(left, right);
};
