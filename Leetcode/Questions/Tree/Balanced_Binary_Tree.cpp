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

int Balanced(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 1;
    }
    int l = Balanced(root->left);
    int r = Balanced(root->right);
    if (l == -1 || r == -1 || abs(l - r) > 1)
    {
        return -1;
    }
    return 1 + max(l, r);
}
int isBalanced(TreeNode *root)
{
    return Balanced(root)!=-1 ? true : false;
}

int main()
{
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *root2a = new TreeNode(2);
    TreeNode *root3 = new TreeNode(3);
    TreeNode *root3a = new TreeNode(3);
    TreeNode *root4 = new TreeNode(4);
    TreeNode *root4a = new TreeNode(4);

    root1->left = root2;
    root1->right = root2a;

    root2->left = root3;
    root2->right = root3a;

    root3->left = root4;
    root3->right = root4a;

    cout << isBalanced(root1);

    return 0;
}