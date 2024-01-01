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
void preorder(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
TreeNode *findmaxright(TreeNode *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findmaxright(root->right);
}

TreeNode *helper(TreeNode *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    if (root->right == NULL)
    {
        return root->left;
    }
    TreeNode *rightNode = root->right;
    TreeNode *maxright = findmaxright(root->left);
    maxright->right = rightNode;
    return root->left;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
    {
        return NULL;
    }
    if (root->val == key)
    {
        return helper(root);
    }
    TreeNode *dumy = root;
    while (root != NULL)
    {
        if (root->val > key)
        {
            if (root->left != NULL && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dumy;
}

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

    root = deleteNode(root, 2);
    preorder(root);

    return 0;
}