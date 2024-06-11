#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];

    bool containKey(int bit)
    {
        return links[bit] != NULL;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!temp->containKey(bit))
            {
                temp->put(bit, new Node());
            }
            temp = temp->get(bit);
        }
    }
    int getMax(int num)
    {
        int ans = 0;
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (temp->containKey(1 - bit))
            {
                ans = ans | (1 << i);
                temp = temp->get(1 - bit);
            }
            else
            {
                temp = temp->get(bit);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        Trie trie;
        int n = queries.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oq;
        for (int i = 0; i < n; i++)
        {
            oq.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(oq.begin(), oq.end());
        vector<int> ans(n, -1);
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            int end = oq[i].first;
            while (j < nums.size() && nums[j] <= end)
            {
                trie.insert(nums[j]);
                j++;
            }

            if (j > 0)
            {
                int t = trie.getMax(oq[i].second.first);
                ans[oq[i].second.second] = t;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}