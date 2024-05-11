class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Solution {
    /**
    * @param Node root

    * @returns number[][]
    */
    solve(root, temp, ans) {
        if (!root) {
            return;
        }
        temp.push(root.data);
        if (!root.left && !root.right) {
            ans.push([...temp]);
        }
        else {
            this.solve(root.left, temp, ans);
            this.solve(root.right, temp, ans);
        }
        temp.pop();

    }

    Paths(root) {
        let ans = [];
        this.solve(root, [], ans);
        return ans;

    }
}

// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;

//     Node(int x)
//     {
//         data = x;
//         left = right = NULL;
//     }
// };

// class Solution
// {
//     void solve(Node *root, vector<vector<int>> &ans, vector<int> &temp)
//     {
//         if (!root)
//         {
//             return;
//         }
//         temp.push_back(root->data);
//         if (!root->left && !root->right)
//         {

//             ans.push_back(temp);
//         }
//         else
//         {
//             solve(root->left, ans, temp);
//             solve(root->right, ans, temp);
//         }
//         temp.pop_back();
//     }

// public:
//     vector<vector<int>> Paths(Node *root)
//     {
//         vector<vector<int>> ans;
//         vector<int> temp;
//         solve(root, ans, temp);
//         return ans;
//     }
// };

// int main()
// {

//     return 0;
// }