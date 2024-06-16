#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {

        queue<Node *> q;
        unordered_map<int, Node *> mp;
        unordered_set<int> vist;

        q.push(node);
        vist.insert(node->val);
        Node *clone = new Node(node->val);
        mp[clone->val] = clone;
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            int n = temp->neighbors.size();
            Node *copy = mp[temp->val];
            for (int i = 0; i < n; i++)
            {
                Node *nei = temp->neighbors[i];
                int val = nei->val;
                if (!mp.count(val))
                {
                    Node *c = new Node(val);
                    mp[val] = c;
                }
                copy->neighbors.push_back(mp[val]);
                if (!vist.count(val))
                {
                    vist.insert(val);
                    q.push(nei);
                }
            }
        }
        return clone;
    }
};

int main()
{

    return 0;
}