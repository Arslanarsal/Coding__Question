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
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *temp = head;
        int k = false;
        if (head->val > 4)
        {
            k = true;
        }

        while (head)
        {
            bool flag = false;
            if (head->next && head->next->val > 4)
            {
                flag = true;
            }
            int num = ((2 * head->val) % 10) + flag;
            head->val = num;
            head = head->next;
        }
        if (k)
        {
            return ListNode * newhead = new ListNode(1, head);
        }
        return head;
    }
};

int main()
{

    return 0;
}