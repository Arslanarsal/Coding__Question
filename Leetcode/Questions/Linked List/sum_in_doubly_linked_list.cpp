#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

vector<pair<int, int>> findPairs(Node *head, int k)
{
    unordered_set<int> st;
    vector<pair<int, int>> ans;
    while (head)
    {
        int value = head->data;
        if (st.find(k - value) != st.end())
        {
            ans.push_back({k - value, value});
        }
        if (head->data > k)
        {
            break;
        }

        st.insert(head->data);
        head = head->next;
    }
    return ans;
}

int main()
{

    return 0;
}