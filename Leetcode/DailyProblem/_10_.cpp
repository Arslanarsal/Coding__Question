#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val = 0;
    Node *arr[26];
    Node()
    {
        val = 0;
        for (int i = 0; i < 26; i++)
        {
            arr[i] = nullptr;
        }
    }
    void insert(int v, Node *temp)
    {
        arr[v] = temp;
    }
    int get()
    {
        return val;
    }
};

class trie
{
    Node *head;

public:
    trie()
    {
        head = new Node();
    }

    void insert(string str)
    {
        Node *temp = head;
        int n = str.size();
        for (int i = 0; i < n; i++)
        {
            int val = str[i] - 'a';
            if (temp->arr[val] == nullptr)
            {
                Node *newNode = new Node();
                temp->insert(val, newNode);
            }

            temp = temp->arr[val];
            temp->val++;
        }
    }

    int getans(string str)
    {
        int ans = 0;
        int n = str.size();
        Node *temp = head;
        for (int i = 0; i < n; i++)
        {

            int val = str[i] - 'a';
            temp = temp->arr[val];
            ans += temp->get();
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        int n = words.size();
        vector<int> ans(n);
        trie temp;

        for (int i = 0; i < n; i++)
        {
            temp.insert(words[i]);
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = temp.getans(words[i]);
        }
        return ans;
    }
};

int main()
{
    vector<string> s = {"9", "93", "90", "949"};
    sort(s.begin(), s.end());
    for (auto &&i : s)
    {
        cout << i << " ";
    }

    return 0;
}