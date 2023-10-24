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

ListNode *reverseLinkedList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


bool isPalindrome(ListNode *head)
{
    int n = 0, n1 = 0;
    ListNode *temp = head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (n1 >= (n / 2))
        {
            break;
        }
        n1++;
        temp = temp->next;
    }
    temp = reverseLinkedList(temp);
    while (temp != NULL)
    {
        if (temp->data != head->data)
        {
            return false;
        }
        temp = temp->next;
        head = head->next;
    }
    return true;
}

int main()
{
    ListNode *node = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    // ListNode *node5 = new ListNode(1);

    node->next = node2;

    node2->next = node3;
    node2->prev = node;

    node3->next = node4;
    node3->prev = node2;

    // node4->next = node5;
    node4->prev = node3;

    // NULL<-1<->2<->3<->4->NULL
    cout << isPalindrome(node)<<endl;
    print(node);

    return 0;
}