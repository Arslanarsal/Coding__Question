#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{

public:
    int max_value = INT_MAX;
    int min_value = INT_MIN;
    int ans = 0;
    Solution(int minn, int mixx, int val)
    {
        max_value = mixx;
        min_value = minn;
        ans = val;
    }

    Solution postorder(Node *root)
    {
        if (!root)
        {
            return Solution(INT_MAX, INT_MIN, 0);
        }
        auto left = postorder(root->left);
        auto right = postorder(root->right);
        if (left.max_value < root->data && right.min_value > root->data)
        {
            return Solution(min(root->data, left.min_value), max(root->data, right.max_value), left.ans + right.ans + 1);
        }
        return Solution(INT_MIN, INT_MAX, max(left.ans, right.ans));
    }

    int largestBst(Node *root)
    {
        return postorder(root).ans;
    }
};

int main()
{

    return 0;
}