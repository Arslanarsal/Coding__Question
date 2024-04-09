#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *addOne(Node *head)
{
    Node *node = NULL;
    Node *temp = head;
    while (temp)
    {
        if (temp->data < 9)
        {
            node = temp;
        }
        temp = temp->next;
    }
    if (node)
    {
        node->data += 1;
        node = node->next;
        while (node)
        {
            node->data = 0;
            node = node->next;
        }
        return head;
    }
    Node *newhead = new Node(1, head);
    while (head)
    {
        head->data = 0;
        head = head->next;
    }
    return newhead;
}

int main()
{

    return 0;
}