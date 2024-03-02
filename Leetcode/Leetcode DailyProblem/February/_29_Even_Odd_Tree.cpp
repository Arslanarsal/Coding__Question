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
public:
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        bool flage = true;
        while (!q.empty())
        {
            int pre = -1;
            while (q.front() != NULL)
            {
                auto it = q.front();
                q.pop();
                if (flage && ((!(it->val & 1)) || (pre != -1 && pre >= it->val)))
                {
                    return false;
                }
                else if (!flage && ((it->val & 1) || (pre != -1 && pre <= it->val)))
                {
                    return false;
                }
                pre = it->val;

                if (it->left)
                {
                    q.push(it->left);
                }
                if (it->right)
                {
                    q.push(it->right);
                }
            }
            flage = !flage;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}