#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    vector<int> temp;
    if (!root)
    {
        return ans;
    }
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        temp.clear();
        while (q.front() != NULL)
        {
            temp.push_back(q.front()->val);
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right) // Corrected the condition to check for the right child
            {
                q.push(q.front()->right);
            }

            q.pop();
        }
        ans.push_back(temp);
        q.pop();
        if (!q.empty())
        {
            q.push(NULL);
        }
    }
    return ans;
}

/*
    Time complexity: O(n)
    Space complexity: O(w)

    Where ‘n’ is the number of nodes and 'w' is the maximum width of the binary tree.
*/


vector<int> levelOrder(TreeNode<int> *root)
{

    vector<int> path;

    queue<TreeNode<int> *> q;
    // Push the root into the queue.
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *cur = q.front();
        q.pop();

        // Add current node to the path.
        path.push_back(cur->data);

        // If left child exists, push it into the queue.
        if (cur->left)
            q.push(cur->left);

        // If right child exists, push it in the queue.
        if (cur->right)
            q.push(cur->right);
    }

    return path;
}

int main()
{

    return 0;
}