
#include <bits/stdc++.h>

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
/*
    Time complexity: O(logN)
    Space complexity: O(logN)

    Where 'N' is the number of nodes of the tree
*/

// int findCeil(TreeNode *node, int x)
// {
//     // Initializing ceil value
//     int ceil = -1;

//     // Traverse till the node is not null
//     while (node != NULL)
//     {

//         // If node value equals key then return it
//         if (x == node->val)
//         {
//             return node->val;
//         }

//         // Traverse right sub-tree
//         if (x > node->val)
//         {

//             node = node->right;
//         }

//         // Traverse left sub-tree
//         else
//         {
//             ceil = node->val;
//             node = node->left;
//         }
//     }

//     // Return the ceil value
//     return ceil;
// }

int findfloor(TreeNode *node, int x)
{
    // Initializing ceil value
    int ceil = INT_MAX;

    // Traverse till the node is not null
    while (node != NULL)
    {

        // If node value equals key then return it
        if (x == node->val)
        {
            return node->val;
        }

        // Traverse right sub-tree
        if (x < node->val)
        {
            ceil = node->val;
            node = node->right;
        }

        // Traverse left sub-tree
        else
        {

            node = node->left;
        }
    }

    // Return the ceil value
    return ceil;
}
int findCeil(TreeNode *node, int x)
{
    // Initializing ceil value
    int ceil = -1;

    // Traverse till the node is not null
    while (node != NULL)
    {
        if (x == node->val)
        {
            return node->val;
        }

        // Traverse right sub-tree
        if (x > node->val)
        {
            ceil = node->val;
            node = node->right;
        }
        // Traverse left sub-tree
        else
        {

            node = node->left;
        }
    }
    // Return the ceil value
    return ceil;
}
// Write your code here.

int main()
{
    TreeNode *root = new TreeNode(4);

    TreeNode *root2 = new TreeNode(2);
    TreeNode *root6 = new TreeNode(6);

    TreeNode *root1 = new TreeNode(1);
    TreeNode *root3 = new TreeNode(3);

    TreeNode *root5 = new TreeNode(5);
    TreeNode *root7 = new TreeNode(7);
    /*
        4
       / \
      2   6
     / \ / \
    1  3 5  7
    */
    root->left = root2;
    root->right = root6;

    root2->left = root1;
    root2->right = root3;

    root6->left = root5;
    root6->right = root7;

    // cout << findCeil(root, 3);
    cout << findfloor(root, 3);

    return 0;
}