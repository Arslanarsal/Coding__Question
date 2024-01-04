#include <vector>
#include <map>
#include <queue>
#include <iostream>
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

vector<int> getTopView(TreeNode *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<int, TreeNode *>> q;
    q.push({0, root});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int line = it.first;
        TreeNode *node = it.second;
        if (mp.find(line) == mp.end())
        {
            mp[line] = node->val;
        }
        if (node->left)
        {
            q.push({line - 1, node->left});
        }
        if (node->right)
        {
            q.push({line + 1, node->right});
        }
    }
    for (auto &&i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// Bottom view of Tree
vector<int> getbottomView(TreeNode *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<int, TreeNode *>> q;
    q.push({0, root});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int line = it.first;
        TreeNode *node = it.second;
        mp[line] = node->val;
        if (node->left)
        {
            q.push({line - 1, node->left});
        }
        if (node->right)
        {
            q.push({line + 1, node->right});
        }
    }
    for (auto &&i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(1);

    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(3);

    TreeNode *root4 = new TreeNode(4);
    TreeNode *root5 = new TreeNode(5);

    TreeNode *root6 = new TreeNode(6);
    TreeNode *root7 = new TreeNode(7);

    TreeNode *root8 = new TreeNode(8);
    /*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
   /
  8
    */
    root->left = root2;
    root->right = root3;

    root2->left = root4;
    root2->right = root5;

    root3->left = root6;
    root3->right = root7;

    root4->left = root8;

    vector<int> v;
    // v = getTopView(root);
    v = getbottomView(root);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}