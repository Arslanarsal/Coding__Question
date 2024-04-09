#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node *mergeRwoList(Node *l1, Node *l2)
{
    Node *dumynode = new Node(-1);
    Node *res = dumynode;
    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            res->child = l1;
            res = l1;
            l1 = l1->child;
        }
        else
        {
            res->child = l2;
            res = l2;
            l2 = l2->child;
        }
        res->next = nullptr;
    }
    if (l1)
    {
        res->child = l1;
    }
    else
    {
        res->child = l2;
    }
    if (dumynode->child)
    {
        dumynode->child->next = nullptr;
    }

    return dumynode->child;
}

Node *flattenLinkedList(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    Node *mergehead = flattenLinkedList(head->next);

    return mergeRwoList(head, mergehead);
}

int main()
{

    return 0;
}