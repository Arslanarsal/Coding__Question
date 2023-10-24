#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node* reverseLinkedList(Node *head)
{
    if(head == NULL || head->next == NULL) return head;
        Node* h2 = reverseLinkedList(head->next);
        head->next->next = head;
        head->next=NULL;
        return h2;
}


Node *reverseDLL(Node *head)
{
    Node *pre = NULL;
    while (head)
    {
        head->prev = head->next;
        head->next = pre;
        pre = head;
        head = head->prev;
    }
    return pre;
}

void print(Node *node)
{
    while (node)
    {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *node = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node->next = node2;

    node2->next = node3;
    node2->prev = node;

    node3->next = node4;
    node3->prev = node2;

    node4->prev = node3;

    print(node);
    node = reverseDLL(node);
    print(node);

    return 0;
}