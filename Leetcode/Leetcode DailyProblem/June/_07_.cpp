#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *temp = head->next;
        while (temp)
        {
            cur->val += + 0LL + temp->val;
            if (!temp->val && temp->next)
            {
                cur->next = temp;
                cur = temp;
            }
            else if (!temp->val)
            {
                cur->next = nullptr;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}