#include <bits/stdc++.h>
using namespace std;
struct Node
{
    bool data; // NOTE data is bool
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list
    long long unsigned int decimalValue(Node *head)
    {
        int mod = 1e9 + 7;
        long long ans = 0;
        while (head)
        {
            ans = ans * 2 % mod;
            if (head->data)
            {
                ans += 1;
            }
            head = head->next;
        }
        return ans;
    }
};

int main()
{

    return 0;
}