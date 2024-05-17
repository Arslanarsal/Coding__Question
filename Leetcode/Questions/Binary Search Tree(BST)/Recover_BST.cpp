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
    TreeNode *pre = nullptr;
    TreeNode *first = nullptr;
    TreeNode *middle = nullptr;
    TreeNode *second = nullptr;
    void inorder(TreeNode *root)
    {
        if (root)
        {
            inorder(root->left);
            if (pre && pre->val > root->val)
            {
                if (!first)
                {
                    first = pre;
                    middle = root;
                }
                else
                {
                    second = root;
                }
            }

            pre = root;
            inorder(root->right);
        }
    }

public:
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        if (first && second)
        {
            swap(first->val, second->val);
        }
        else if (first && middle)
        {
            swap(first->val, middle->val);
        }
        return;
    }
};

int main()
{

    return 0;
}