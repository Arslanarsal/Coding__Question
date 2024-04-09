function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function getKthNode(temp, k) {
  k -= 1;
  while (temp && k > 0) {
    k--;
    temp = temp.next;
  }
  return temp;
}

function reverseLinkedList(temp) {
  let pre = null;
  let cur = temp;
  let nex;
  while (cur) {
    nex = cur.next;
    cur.next = pre;
    pre = cur;
    cur = nex;
  }
  return pre;
}

function getKthNode(temp, k) {
  k -= 1;
  while (temp !== null && k > 0) {
    k--;
    temp = temp.next;
  }
  return temp;
}

var reverseKGroup = function (head, k) {
  let temp = head;
  let prenode = null;
  while (temp) {
    let kthnode = getKthNode(temp, k);
    if (kthnode === null) {
      if (prenode) {
        prenode.next = temp;
      }
      break;
    }
    let nextNode = kthnode.next;
    kthnode.next = null;
    reverseLinkedList(temp);
    if (temp === head) {
      head = kthnode;
    } else {
      prenode.next = kthnode;
    }

    prenode = temp;
    temp = nextNode;
  }
  return head;
};
