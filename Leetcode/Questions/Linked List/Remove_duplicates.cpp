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

Node *removeDuplicates(Node *head)
{
    Node *cur = head;
    while (cur)
    {
        if (cur->next && cur->data == cur->next->data)
        {
            cur->next = cur->next->next;
            cur->next->prev = cur;
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
}

int main()
{

    return 0;
}