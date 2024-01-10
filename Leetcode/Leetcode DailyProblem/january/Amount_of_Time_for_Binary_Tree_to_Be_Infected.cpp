#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution
// {
//     bool parent(TreeNode *root, int &start, stack<TreeNode *> &st, queue<TreeNode *> &q)
//     {
//         if (root && root->val == start)
//         {
//             q.push(root);
//             return true;
//         }

//         if (root)
//         {
//             st.push(root);
//             if (!(parent(root->left, start, st, q)) && !(parent(root->right, start, st, q)))
//             {
//                 st.pop();
//                 return false;
//             }
//             else
//             {
//                 return true;
//             }
//         }
//         return false;
//     }

// public:
//     int amountOfTime(TreeNode *root, int start)
//     {
//         stack<TreeNode *> st;
//         queue<TreeNode *> q;
//         parent(root, start, st, q);

//         unordered_map<int, bool> mp;
//         mp.insert({start, true});
//         q.push(NULL);
//         int ans = 0;

//         while (!q.empty())
//         {
//             TreeNode *infected = q.front();
//             q.pop();
//             while (infected)
//             {
//                 if (infected->left && mp.find(infected->left->val) == mp.end())
//                 {
//                     q.push(infected->left);
//                     mp.insert({infected->left->val, true});
//                 }
//                 if (infected->right && mp.find(infected->right->val) == mp.end())
//                 {
//                     q.push(infected->right);
//                     mp.insert({infected->right->val, true});
//                 }
//                 if (!st.empty() && mp.find(st.top()->val) == mp.end() && ((st.top()->left && st.top()->left == infected) || (st.top()->right && st.top()->right == infected)))
//                 {
//                     q.push(st.top());
//                     mp.insert({st.top()->val, true});
//                     st.pop();
//                 }
//                 infected = q.front();
//                 q.pop();
//             }
//             if (!q.empty())
//             {
//                 ans++;
//                 q.push(NULL);
//             }
//         }
//         return ans;
//     }
// };

// Second approch

class Solution
{
    int ans = 0;
    int traverse(int start, TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftdepth = traverse(start, root->left);
        int rightdepth = traverse(start, root->right);

        int depth = 0;
        if (root->val == start)
        {
            ans = max(leftdepth, rightdepth);
            depth = -1;
        }
        else if (leftdepth >= 0 && rightdepth >= 0)
        {
            depth = max(leftdepth, rightdepth) + 1;
        }
        else
        {
            int dist = abs(leftdepth) + abs(rightdepth);
            ans = max(ans, dist);
            depth = min(leftdepth, rightdepth) - 1;
        }
        return depth;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        traverse(start, root);
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(3);

    TreeNode *root4 = new TreeNode(4);
    TreeNode *root5 = new TreeNode(5);

    TreeNode *root6 = new TreeNode(6);
    TreeNode *root7 = new TreeNode(7);
    /*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
    */
    root->left = root2;
    // root->right = root3;

    root2->left = root3;
    // root2->right = root5;

    root3->left = root4;
    // root3->right = root7;

    root4->left = root5;

    Solution sol;

    vector<int> v;
    cout << endl
         << sol.amountOfTime(root, 2);

    return 0;
}