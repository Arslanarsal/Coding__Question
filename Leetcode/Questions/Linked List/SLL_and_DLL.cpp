#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next, *prev;
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};


void print(ListNode *node)
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
    ListNode *node = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    node->next = node2;

    node2->next = node3;
    node2->prev = node;

    node3->next = node4;
    node3->prev = node2;

    node4->next = node5;
    node4->prev = node3;

    node5->prev = node4;

    // NULL<-1<->2<->3<->4<->5->NULL
    print(node);

    return 0;
}