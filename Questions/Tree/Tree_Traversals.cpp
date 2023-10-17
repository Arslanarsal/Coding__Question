#include <bits/stdc++.h>
using namespace std;




// Following is Binary Tree Node structure:
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};



void Inorder(TreeNode *root, vector<int> &v)
{
    if (root)
    {
        Inorder(root->left, v);
        v.push_back(root->data);
        Inorder(root->right, v);
    }
}

void preorder(TreeNode *root, vector<int> &v)
{
    if (root)
    {
        v.push_back(root->data);
        preorder(root->left, v);
        preorder(root->right, v);
    }
}

void postorder(TreeNode *root, vector<int> &v)
{
    if (root)
    {
        postorder(root->left, v);
        postorder(root->right, v);
        v.push_back(root->data);
    }
}
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    vector<int> temp;

    Inorder(root, temp);
    ans.push_back(temp);

    temp.clear();
    preorder(root, temp);
    ans.push_back(temp);

    temp.clear();
    postorder(root, temp);
    ans.push_back(temp);
    return ans;
}

int main()
{

    return 0;
}