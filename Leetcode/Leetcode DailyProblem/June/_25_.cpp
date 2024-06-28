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

class Solution
{
    void bstToGst(TreeNode *root, int &sum)
    {
        if (!root) // Correct base case
        {
            return;
        }

        // Traverse the right subtree first
        if (root->right)
        {
            bstToGst(root->right, sum);
        }

        // Update the current node's value and the running sum
        root->val += sum;
        sum = root->val;

        // Traverse the left subtree
        if (root->left)
        {
            bstToGst(root->left, sum);
        }
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        bstToGst(root, sum);
        return root;
    }
};

int main()
{

    return 0;
}