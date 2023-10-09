#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(N * Q)
        For enQueue(): O(1)
        For deQueue(): O(N)
        For peek(): O(N)
        For isEmpty(): O(1)

    Space Complexity : O(N)

    Where 'N' is the maximum number of elements that are in the stack at any time.
    Where 'Q' is the total number of queries which are performed.
*/

#include <stack>

class Queue
{
    stack<int> *st;

public:
    Queue()
    {
        st = new stack<int>();
    }

    // EnQueue item to the queue.
    void enQueue(int val)
    {
        // Push the value into the stack.
        st->push(val);
    }

    // Dequeue an item from the queue.
    int deQueue()
    {
        // If stack is empty, return -1.
        if (st->empty())
        {
            return -1;
        }

        // Pop the current top element.
        int x = st->top();
        st->pop();

        // Base case of the recursion.
        if (st->empty())
        {
            return x;
        }

        // Recursively pop the next element.
        int nxt = deQueue();
        // Push this element again to the stack.
        st->push(x);
        return nxt;
    }

    // Returns the Front element of the queue.
    int peek()
    {
        if (st->empty())
        {
            return -1;
        }

        int x = st->top();
        st->pop();
        if (st->empty())
        {
            st->push(x);
            return x;
        }

        int nxt = peek();
        st->push(x);
        return nxt;
    }

    // Whether the queue is empty or not.
    bool isEmpty()
    {
        return (st->empty());
    }
};
int main()
{

    return 0;
}