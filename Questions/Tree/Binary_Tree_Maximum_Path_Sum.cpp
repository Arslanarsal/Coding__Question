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

int pathSum(TreeNode *root, int &sum)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return root->val;
    }
    int l = pathSum(root->left, sum);
    int r = pathSum(root->right, sum);
    int cur = max(root->val, max(l + root->val, r + root->val));
    int maxcur = max(cur, root->val + l + r);
    sum = max(sum, maxcur);
    if (cur < 0)
    {
        return 0;
    }
    return cur;
}

int maxPathSum(TreeNode *root)
{
    int sum = INT_MIN;
    pathSum(root, sum);
    return sum;
}
int main()
{
    TreeNode *root = new TreeNode(-10);

    TreeNode *root2 = new TreeNode(9);
    TreeNode *root2a = new TreeNode(20);

    TreeNode *root3 = new TreeNode(15);
    TreeNode *root3a = new TreeNode(7);

    // TreeNode *root4 = new TreeNode(4);
    // TreeNode *root4a = new TreeNode(4);

    root->left = root2;
    root->right = root2a;

    root2a->left = root3;
    root2a->right = root3a;

    // root3->left = root4;
    // root3->right = root4a;

    cout << maxPathSum(root);

    return 0;
}