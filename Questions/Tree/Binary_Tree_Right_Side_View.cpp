#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        ans.push_back(q.front()->val);

        while (q.front() != NULL)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->right)
            {
                q.push(node->right);
            }
            if (node->left)
            {
                q.push(node->left);
            }
        }
        q.pop();
        if (!q.empty())
        {
            q.push(NULL);
        }
    }
    return ans;
}

// vector<int> leftSideView(TreeNode *root)
// {
//     vector<int> ans;
//     if (!root)
//     {
//         return ans;
//     }
//     queue<TreeNode *> q;
//     q.push(root);
//     q.push(NULL);
//     while (!q.empty())
//     {
//         ans.push_back(q.front()->val);

//         while (q.front() != NULL)
//         {
//             TreeNode *node = q.front();
//             q.pop();

//             if (node->left)
//             {
//                 q.push(node->left);
//             }
//             if (node->right)
//             {
//                 q.push(node->right);
//             }
//         }
//         q.pop();
//         if (!q.empty())
//         {
//             q.push(NULL);
//         }
//     }
//     return ans;
// }


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
    root->right = root3;

    root2->left = root4;
    root2->right = root5;

    root3->left = root6;
    root3->right = root7;

    vector<int> v;
    // v = rightSideView(root);
    // v = leftSideView(root);
     leftSideView(root);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}