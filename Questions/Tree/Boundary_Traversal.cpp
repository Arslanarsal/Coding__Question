#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the number of nodes in the Binary Tree.
*/

/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// Functions to traverse on each part
void leftBoundary(TreeNode *root, vector<int> &ans);
void rightBoundary(TreeNode *root, vector<int> &ans);
void leafNodes(TreeNode *root, vector<int> &ans);

vector<int> traverseBoundary(TreeNode *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // Traverse left boundary
    leftBoundary(root->left, ans);

    // Traverse for leaf nodes
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);

    // Traverse right boundary
    rightBoundary(root->right, ans);

    return ans;
}

void leftBoundary(TreeNode *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);

    if (root->left != NULL)
    {
        leftBoundary(root->left, ans);
    }
    else
    {
        leftBoundary(root->right, ans);
    }
}

void rightBoundary(TreeNode *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right != NULL)
    {
        rightBoundary(root->right, ans);
    }
    else
    {
        rightBoundary(root->left, ans);
    }

    ans.push_back(root->data);
}

void leafNodes(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
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
    /*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
    */
    root->left = root2;
    root->right = root3;

    root2->left = root4;
    root2->right = root5;

    root3->left = root6;
    root3->right = root7;

    vector<int> v;
    v = traverseBoundary(root);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}