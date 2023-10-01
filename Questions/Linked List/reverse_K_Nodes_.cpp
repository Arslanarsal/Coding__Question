#include <bits/stdc++.h>
using namespace std;

// Creat a Node
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Add Node at the end of the Linked List
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// Reverse K Node in linked List
node *ReverseKNode(node *&head, int k, bool fl = true)
{
    node *preptr = NULL;
    node *currptr = head;
    node *Nextptr;

    int count = 0;
    if (fl)
    {
        while (currptr != NULL && count < k)
        {
            Nextptr = currptr->next;
            currptr->next = preptr;

            preptr = currptr;
            currptr = Nextptr;
            count++;
        }
        if (Nextptr != NULL)
        {
            head->next = ReverseKNode(Nextptr, k, false);
        }
        return preptr;
    }
    while (currptr != NULL && count < k)
    {
        Nextptr = currptr->next;

        preptr = currptr;
        currptr = Nextptr;
        count++;
    }
    if (Nextptr != NULL)
    {
        preptr->next = ReverseKNode(Nextptr, k, true);
    }
    return head;
}

// Display all Linked List
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
    return;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);

    display(head);
    head = ReverseKNode(head, 3);
    display(head);

    return 0;
}