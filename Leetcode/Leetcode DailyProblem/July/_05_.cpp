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
    bool check(ListNode *head)
    {
        int curval = head->next->val;
        if (curval < head->val && curval < head->next->next->val)
        {
            return true;
        }
        if (curval > head->val && curval > head->next->next->val)
        {
            return true;
        }
        return false;
    }

public:
    int minval = INT_MAX;
    int pre = -1;
    int last = -1;
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *temp = head;
        while ( temp->next && temp->next->next)
        {
            if (check(temp))
            {
                last = 2;
                pre = 1;
                temp = temp->next;
                break;
            }
            temp = temp->next;
        }
        while (temp->next && temp->next->next)
        {
            if (check(temp))
            {
                minval = min(minval, last - pre);
                pre = last;
            }
            last++;
            temp = temp->next;
        }
        if (minval == INT_MAX)
        {
            return {-1, -1};
        }
        return {minval, pre - 1};
    }
};

int main()
{

    return 0;
}