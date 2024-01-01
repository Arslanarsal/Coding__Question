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

int diameter(TreeNode *root, int &ans)
{
    if (!root)
    {
        return 0;
    }

    int l = diameter(root->left, ans);
    int r = diameter(root->right, ans);
    ans = max(ans, l + r);
    return 1 + max(l, r);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int ans = 0;
    diameter(root, ans);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *root2a = new TreeNode(2);
    TreeNode *root3 = new TreeNode(3);
    TreeNode *root3a = new TreeNode(3);
    TreeNode *root4 = new TreeNode(4);
    TreeNode *root4a = new TreeNode(4);

    root->left = root2;
    // root->right = root2a;

    // root2->left = root3;
    // root2->right = root3a;

    // root3->left = root4;
    // root3->right = root4a;
    cout << diameterOfBinaryTree(root);

    return 0;
}