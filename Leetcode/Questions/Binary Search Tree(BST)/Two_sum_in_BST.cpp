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

class BSTIterator
{
    bool s = true;
    stack<TreeNode *> st;
    void pushleft(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            if (s)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
    }

public:
    BSTIterator(TreeNode *root, bool p)
    {
        s = p;
        pushleft(root);
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        if (s)
        {
            pushleft(node->right);
        }
        else
        {
            pushleft(node->left);
        }
        return node->val;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
        {
            return false;
        }

        BSTIterator l(root, true);
        BSTIterator r(root, false);
        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
            {
                return true;
            }
            else if (i + j < k)
            {
                i = l.next();
            }
            else
            {
                j = r.next();
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}