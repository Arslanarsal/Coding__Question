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
    void solve(TreeNode *root, unordered_set<int> &st, vector<TreeNode *> &ans)
    {
        if (!root)
        {
            return;
        }
        solve(root->left, st, ans);
        solve(root->right, st, ans);

        if (root->left && st.find(root->left->val) != st.end())
        {
            root->left = nullptr;
        }
        if (root->right && st.find(root->right->val) != st.end())
        {
            root->right = nullptr;
        }

        if (st.find(root->val) != st.end())
        {
            if (root->left)
            {
                ans.push_back(root->left);
            }
            if (root->right)
            {
                ans.push_back(root->right);
            }
        }
        return;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        solve(root, st, ans);
        if (st.find(root->val) == st.end())
        {
            ans.push_back(root);
        }
        return ans;
    }
};

int main()
{

    return 0;
}