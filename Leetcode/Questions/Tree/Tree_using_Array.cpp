#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the number of elements in the array 'arr'
*/
Node *createTree(vector<int> &arr)
{
    queue<Node *> q;
    int size = arr.size() - 1;
    int n = (size - 1) / 2;
    // Create the root node with the value from the first element of the array
    Node *root = new Node(arr[0]);
    q.push(root);

    int i = 0;

    // Construct the binary tree using the remaining elements of the array
    while (!q.empty() && i <= n)
    {
        Node *t = q.front();
        q.pop();

        // Create the left child node with the value from the corresponding index in the array
        if (2 * i + 1 <= size)
        {
            Node *left = new Node(arr[2 * i + 1]);
            t->left = left;
            q.push(left);
        }

        // Create the right child node with the value from the corresponding index in the array
        if (2 * i + 1 <= size)
        {
            Node *right = new Node(arr[2 * i + 2]);
            t->right = right;
            q.push(right);
        }
        i++;
    }
    return root;
}

void prefixorder(Node *root)
{
    if (root)
    {
        cout << root->data << "->";
        prefixorder(root->left);
        prefixorder(root->right);
    }
}

int main()
{
    vector<int> v = {54, 53, 55, 52, 50};
    Node *temp = createTree(v);
    prefixorder(temp);

    return 0;
}