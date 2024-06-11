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
    int findMaximumXOR(vector<int> &nums)
    {
        Trie trie;
        for (auto &&i : nums)
        {
            trie.insert(i);
        }
        int ans = 0;
        for (auto &&i : nums)
        {
            ans = max(ans, trie.getMax(i));
        }
        return ans;
    }
};

int main()
{

    return 0;
}