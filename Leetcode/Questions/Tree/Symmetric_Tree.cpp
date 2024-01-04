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

bool isSymmetric(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    if ((!root1 && root2)  ||(root1 && !root2 ) ||(root1->val != root2->val) )
    {
        return false;
    }
   
   
    if (isSymmetric(root1->left, root2->right))
    {
        if (isSymmetric(root1->right, root2->left))
        {
            return true;
        }
    }
    return false;
}
bool isSymmetric(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    return isSymmetric(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);

    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(2);

    TreeNode *root4 = new TreeNode(3);
    TreeNode *root5 = new TreeNode(4);

    TreeNode *root6 = new TreeNode(4);
    TreeNode *root7 = new TreeNode(3);
    /*
        1
       / \
      2   2
     / \ / \
    4  3 3  4
    */
    root->left = root2;
    root->right = root3;

    root2->left = root4;
    root2->right = root5;

    root3->left = root6;
    root3->right = root7;

    cout << isSymmetric(root);

    return 0;
}