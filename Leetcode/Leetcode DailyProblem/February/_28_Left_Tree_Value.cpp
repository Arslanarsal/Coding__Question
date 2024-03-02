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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        TreeNode *ans = root;
        while (!q.empty())
        {
            ans = q.front();
            while (q.front() != NULL)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        return ans->val;
    }
};

int main()
{

    return 0;
}