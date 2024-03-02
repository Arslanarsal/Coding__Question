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
    int ans = 0;
    int f(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        int left = f(root->left);
        int right = f(root->right);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        f(root);
        return ans;
    }
};

int main()
{

    return 0;
}