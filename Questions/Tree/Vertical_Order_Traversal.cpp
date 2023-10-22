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

void verticalTraversal(TreeNode *root, int idx, map<int, map<int, vector<int>>> &mp, int id)
{
    if (!root)
    {
        return;
    }
    mp[idx][id].push_back(root->val);
    if (root->left)
    {
        verticalTraversal(root->left, idx - 1, mp, id + 1);
    }
    if (root->right)
    {
        verticalTraversal(root->right, idx + 1, mp, id + 1);
    }
}

// vector<vector<int>> verticalTraversal(TreeNode *root)
// {
//     map<int, map<int, vector<int>>> mp;
//     verticalTraversal(root, 0, mp, 0);
//     vector<vector<int>> ans;

//     for (auto it = mp.begin(); it != mp.end(); it++)
//     {

//         map<int, vector<int>> inner_map = it->second;
//         vector<int> temp;
//         for (auto inner_it = inner_map.begin(); inner_it != inner_map.end(); inner_it++)
//         {
//             vector<int> inner_vec = inner_it->second;
//             sort(inner_vec.begin(), inner_vec.end());

//             for (auto &&i : inner_vec)
//             {
//                 temp.push_back(i);
//             }
//         }
//         ans.push_back(temp);
//     }

//     return ans;
// }


//---------->>>>>>>>>In One Vector
vector<int> verticalTraversal(TreeNode *root)
{
    map<int, map<int, vector<int>>> mp;
    verticalTraversal(root, 0, mp, 0);
    vector<int> ans;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {

        map<int, vector<int>> inner_map = it->second;
        for (auto inner_it = inner_map.begin(); inner_it != inner_map.end(); inner_it++)
        {
            vector<int> inner_vec = inner_it->second;
            sort(inner_vec.begin(), inner_vec.end());

            for (auto &&i : inner_vec)
            {
                ans.push_back(i);
            }
        }
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

    vector<vector<int>> v;
    vector<int> v1;
    // v = verticalTraversal(root);
    v1 = verticalTraversal(root);
    // for (auto &&i : v)
    // {
    //     for (auto &&j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    for (auto &&i : v1)
    {

        cout << i << " ";
    }

    return 0;
}