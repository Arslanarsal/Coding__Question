#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            Node *newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = newnode->next;
        }
        temp = head;
        while (temp)
        {
            if (temp->random)
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        temp = head;
        Node *copyhead = temp->next;
        Node *dumynode = copyhead;
        while (temp)
        {
            temp->next = dumynode->next;
            temp = temp->next;
            if (temp)
            {
                dumynode->next = temp->next;
                dumynode = dumynode->next;
            }
        }
        return copyhead;
    }
};

int main()
{

    return 0;
}