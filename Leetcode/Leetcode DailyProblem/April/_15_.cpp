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
    void addOneRo(TreeNode *root, int val, int depth)
    {
        if (!root)
        {
            return;
        }

        if (!depth)
        {
            TreeNode *leftnode = new TreeNode(val);
            TreeNode *rightnode = new TreeNode(val);
            leftnode->left = root->left;
            rightnode->right = root->right;
            root->left = leftnode;
            root->right = rightnode;
            return;
        }
        addOneRo(root->left, val, depth - 1);
        addOneRo(root->right, val, depth - 1);
        return;
    }

public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        addOneRo(root->left, val, depth - 2);
        return root;
    }
};