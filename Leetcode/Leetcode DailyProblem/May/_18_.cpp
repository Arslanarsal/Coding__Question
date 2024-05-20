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
    int steps = 0;
    int coin(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = coin(root->left);
        int right = coin(root->right);
        steps += abs(left) + abs(right);
        return (root->val - 1) + left + right;
    }

public:
    int distributeCoins(TreeNode *root)
    {
        coin(root);
        return steps;
    }
};

int main()
{

    return 0;
}