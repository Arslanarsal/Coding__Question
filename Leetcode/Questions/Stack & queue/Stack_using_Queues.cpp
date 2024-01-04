#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(Q*N)
    For each push operation O(N); O(1) for all other operations.

    Space complexity: O(max(N1, N2))

    where Q is the number of queries, N denotes the maximum number of elements in the queue and
    ‘N1' and ‘N2’ denote the size of queues ‘q1’ and ‘q2’.
*/

#include <queue>

class Stack
{
public:
    queue<int> *q1, *q2;

    // Constructor.
    Stack()
    {
        q1 = new queue<int>();
        q2 = new queue<int>();
    }

    // Return the size of the queue 'q1'.
    int getSize()
    {
        return q1->size();
    }

    bool isEmpty()
    {
        return getSize() == 0;
    }

    void push(int data)
    {
        // Enqueue new element to q2.
        q2->push(data);

        // Enqueue all the elements of q1 into q2.
        while (q1->size() > 0)
        {
            q2->push(q1->front());
            q1->pop();
        }

        // Swap q1 and q2.
        queue<int> *temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop()
    {
        // If empty, return -1.
        if (isEmpty())
        {
            return -1;
        }
        // Simply dequeue from the queue q1.
        int ans = q1->front();
        q1->pop();
        return ans;
    }

    int top()
    {
        if (isEmpty())
        {
            return -1;
        }

        int ans = q1->front();

        return ans;
    }
};

int main()
{

    return 0;
}