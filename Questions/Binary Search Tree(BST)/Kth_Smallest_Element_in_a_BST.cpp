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

void solve(TreeNode *root, int &cnt, int &ans, int k)
{
    if (root == NULL)
        return;
    // left, root, right
    solve(root->left, cnt, ans, k);
    cnt++;
    if (cnt == k)
    {
        ans = root->val;
        return;
    }
    solve(root->right, cnt, ans, k);
}
int kthSmallest(TreeNode *root, int k)
{

    int cnt = 0;
    int ans;
    solve(root, cnt, ans, k);
    return ans;
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

    cout << kthSmallest(root, 3);
    // preorder(root);

    return 0;
}