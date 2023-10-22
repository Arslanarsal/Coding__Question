#include <iostream>
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
int minValue(TreeNode *root)
{
    if (!root)
    {
        return 1e9 + 1;
    }

    int left;
    int right;
    if (root->left)
    {
        left = minValue(root->left);
    }
    if (root->right)
    {
        right = minValue(root->right);
    }
    return min(root->val, min(left, right));
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

    cout << minValue(root);

    return 0;
}