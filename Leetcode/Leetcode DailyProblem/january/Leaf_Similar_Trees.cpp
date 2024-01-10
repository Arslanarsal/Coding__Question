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
    void leaf(TreeNode *root, vector<int> &ans)
    {
        if (!(root->left) && !(root->right))
        {
            ans.push_back(root->val);
            return;
        }
        if (root)
        {
            leaf(root->left, ans);
            leaf(root->right, ans);
        }
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        leaf(root1, v1);
        leaf(root2, v2);
        if (v1.size() != v2.size())
        {
            return false;
        }
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}