#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    int capacity;
    vector<int> stack;

public:
    Stack(int capacity) : capacity(capacity) {}

    void push(int num)
    {
        if (stack.size() < capacity)
        {
            stack.push_back(num);
        }
    }

    int pop()
    {
        if (!stack.empty())
        {
            int topElement = stack.back();
            stack.pop_back();
            return topElement;
        }
        return -1; // Return -1 if the stack is empty
    }

    int top()
    {
        if (!stack.empty())
        {
            return stack.back();
        }
        return -1; // Return -1 if the stack is empty
    }

    int isEmpty()
    {
        return stack.empty() ? 1 : 0;
    }

    int isFull()
    {
        return (stack.size() == capacity) ? 1 : 0;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    Stack stack(m);

    for (int i = 0; i < n; ++i)
    {
        int op, val;
        cin >> op;

        if (op == 1)
        {
            cin >> val;
            stack.push(val);
        }
        else if (op == 2)
        {
            cout << stack.pop() << endl;
        }
        else if (op == 3)
        {
            cout << stack.top() << endl;
        }
        else if (op == 4)
        {
            cout << stack.isEmpty() << endl;
        }
        else if (op == 5)
        {
            cout << stack.isFull() << endl;
        }
    }

    return 0;
}
