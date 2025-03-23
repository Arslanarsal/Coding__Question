#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
class Solution
=======
class Spreadsheet
>>>>>>> a77668d6f94a6ae13b50b5acfcf751fa03ac7f98
{
    vector<vector<int>> arr;

public:
<<<<<<< HEAD
    struct Node
    {
        unordered_map<char, Node *> child;
        int cnt;
        Node()
        {
            cnt = 0;
        }
    };

    class trie
    {
    public:
        Node *root = nullptr;
        unordered_map<int, int> mp;
        set<int> st;
        trie()
        {
            root = new Node();
        }
        void insert(string &s, int &k)
        {
            int n = s.size();
            Node *temp = root;
            for (int i = 0; i < n; i++)
            {
                char ch = s[i] - 'a';
                if (!(temp->child.count(ch)))
                    temp->child[ch] = new Node();

                temp = temp->child[ch];
                temp->cnt++;
                if (temp->cnt >= k)
                {
                    mp[i + 1]++;
                    if (mp[i + 1] == 1)
                        st.insert(i + 1);
                }
            }
        }

        int delet(string &s, int &k)
        {
            int n = s.size();
            Node *temp = root;
            vector<int> arr;
            for (int i = 0; i < n; i++)
            {
                char ch = s[i] - 'a';
                temp = temp->child[ch];
                if (temp->child[ch]->cnt >= k && mp.count(i + 1) && (mp[i + 1] - 1) == 0)
                {
                    arr.push_back(i + 1);
                    st.erase(i + 1);
                }
            }
            int ans = 0;
            if (st.size())
                ans = *st.rbegin();

            for (auto &&i : arr)
            {
                st.insert(i);
            }
            return ans;
        }
    };

    vector<int> longestCommonPrefix(vector<string> &words, int k)
    {
        trie *temp = new trie();
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            temp->insert(words[i], k);
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[i] = temp->delet(words[i], k);
=======
    Spreadsheet(int rows)
    {
        arr.resize(rows + 1, vector<int>(26));
    }

    void setCell(string cell, int value)
    {
        int row = cell[0] - 'A';
        int col = 0;
        for (int i = 1; i < cell.size(); i++)
        {
            int digit = cell[i] - '0';
            col = col * 10;
            col += digit;
        }
        arr[row][col] = value;
    }

    void resetCell(string cell)
    {
        int row = cell[0] - 'A';
        int col = 0;
        for (int i = 1; i < cell.size(); i++)
        {
            int digit = cell[i] - '0';
            col = col * 10;
            col += digit;
        }
        arr[row][col] = 0;
    }

    int getValue(string formula)
    {
        if (formula[3] >= 'A' && formula[3] <= 'Z')
        {
            int row = formula[3] - 'A';
            int col = 0;
            for (int i = 4; formula[i] != '+'; i++)
            {
                int digit = formula[i] - '0';
                col = col * 10;
                col += digit;
            }
>>>>>>> a77668d6f94a6ae13b50b5acfcf751fa03ac7f98
        }
    }
};

int32_t main()
{
<<<<<<< HEAD
    Solution aol;
    vector<string> nums = {"jump", "run", "run", "jump", "run"};
    int k = 2;
    vector<int> str = aol.longestCommonPrefix(nums, k);
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
=======
>>>>>>> a77668d6f94a6ae13b50b5acfcf751fa03ac7f98

    return 0;
}