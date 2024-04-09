function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

var rotateRight = function (head, k) {
  if (!head || k === 0) {
    return head;
  }

  let n = 1;
  let temp = head;

  // Count the number of nodes in the list
  while (temp.next) {
    temp = temp.next;
    n++;
  }

  // Adjust rotation index if it's greater than the length of the list
  k %= n;

  // If k becomes zero after adjusting, no rotation is needed
  if (k === 0) {
    return head;
  }

  // Reset temp to the head
  temp = head;

  // Find the (n - k - 1)th node
  for (let i = 1; i < n - k; i++) {
    temp = temp.next;
  }

  // Set newhead to the (n - k)th node
  let newhead = temp.next;

  // Break the link from the list
  temp.next = null;

  // Set temp to the end of the rotated list
  temp = newhead;

  // Traverse to the end of the rotated list
  while (temp && temp.next) {
    temp = temp.next;
  }

  // Connect the end of the rotated list to the original head
  temp.next = head;

  return newhead;
};
