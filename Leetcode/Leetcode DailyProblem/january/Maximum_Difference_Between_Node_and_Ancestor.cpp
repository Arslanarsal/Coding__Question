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
    int f(TreeNode *root, int minvalue, int maxvalue)
    {
        if (!root)
        {
            return abs(minvalue - maxvalue);
        }
        minvalue = min(minvalue, root->val);
        maxvalue = min(maxvalue, root->val);
        int left = f(root->left, minvalue, maxvalue);
        int right = f(root->right, minvalue, maxvalue);
        return max(left, right);
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        return f(root, root->val, root->val);
    }
};

int main()
{

    return 0;
}