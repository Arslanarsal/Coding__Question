/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} target
 * @param {number} k
 * @return {number[]}
 */
var distanceK = function (root, target, k) {
  function parent(root, mp) {
    let q = [];
    q.push(root);
    while (q.length) {
      const t = q.length;
      for (let i = 0; i < t; i++) {
        let node = q.shift();
        if (node.left) {
          mp.set(node.left, node);
          q.push(node.left);
        }
        if (node.right) {
          mp.set(node.right, node);
          q.push(node.right);
        }
      }
    }
  }

  let mp = new Map();
  parent(root, mp);
  let visit = new Map();

  visit.set(target, true);
  let q = [];
  q.push(target);
  let j = 0;
  while (q.length) {
    if (j++ === k) {
      break;
    }

    const t = q.length;
    for (let i = 0; i < t; i++) {
      let node = q.shift();
      if (node.left && !visit.get(node.left)) {
        visit.set(node.left, true);
        q.push(node.left);
      }
      if (node.right && !visit.get(node.right)) {
        visit.set(node.right, true);
        q.push(node.right);
      }
      if (mp.get(node) && !visit.get(mp.get(node))) {
        visit.set(mp.get(node), true);
        q.push(mp.get(node));
      }
    }
  }

  let ans = [];
  while (q.length) {
    ans.push(q.shift().val);
  }
  return ans;
};

// #include <bits/stdc++.h>
// using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution
// {
//     void parent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
//     {
//         queue<TreeNode *> q;
//         q.push(root);
//         while (!q.empty())
//         {
//             int t = q.size();
//             for (int i = 0; i < t; i++)
//             {
//                 TreeNode *node = q.front();
//                 q.pop();
//                 if (node->left)
//                 {
//                     parent[node->left] = node;
//                     q.push(node->left);
//                 }
//                 if (node->right)
//                 {
//                     parent[node->right] = node;
//                     q.push(node->right);
//                 }
//             }
//         }
//         return;
//     }

// public:
//     vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
//     {
//         unordered_map<TreeNode *, bool> visit;
//         unordered_map<TreeNode *, TreeNode *> pare;
//         parent(root, pare);

//         queue<TreeNode *> q;
//         q.push(target);
//         visit[target] = true;
//         int j = 0;
//         while (!q.empty())
//         {
//             if (j++ == k)
//             {
//                 break;
//             }

//             int t = q.size();
//             for (int i = 0; i < t; i++)
//             {
//                 TreeNode *node = q.front();
//                 q.pop();
//                 if (node->left && !visit[node->left])
//                 {
//                     visit[node->left] = true;
//                     q.push(node->left);
//                 }
//                 if (node->right && !visit[node->right])
//                 {
//                     visit[node->right] = true;
//                     q.push(node->right);
//                 }
//                 if (pare[node] && !visit[pare[node]])
//                 {
//                     visit[pare[node]] = true;
//                     q.push(pare[node]);
//                 }
//             }
//         }
//         vector<int> ans;
//         while (!q.empty())
//         {
//             ans.push_back(q.front()->val);
//             q.pop();
//         }
//         return ans;
//     }
// };

// int main()
// {

//     return 0;
// }
