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
        next = NULL;
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

/*
    Time Complexity: O(N * logK)
    Space Complexity: O(K)

    Where 'N' is the total number of Nodes.
    And 'K' is the number of lists.
*/

// Compare class for priority queue.
class compare
{
public:
    bool operator()(const Node *first, const Node *second)
    {
        return (first->data > second->data);
    }
};

Node *mergeKLists(vector<Node *> &listArray)
{
    int k = listArray.size();

    if (k == 0)
    {
        return NULL;
    }

    priority_queue<Node *, vector<Node *>, compare> helperPQ;

    // Push into the queue.
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            helperPQ.push(listArray[i]);
        }
    }

    Node *head = NULL, *tail = NULL;

    // Add nodes while queue is non empty.
    while (helperPQ.size() > 0)
    {
        Node *minNode = helperPQ.top();
        helperPQ.pop();

        if (minNode->next != NULL)
        {
            helperPQ.push(minNode->next);
            minNode->next = NULL;
        }

        if (head == NULL)
        {
            head = minNode;
            tail = minNode;
        }
        else
        {
            tail->next = minNode;
            tail = tail->next;
        }
    }

    return head;
}

int main()
{

    return 0;
}
