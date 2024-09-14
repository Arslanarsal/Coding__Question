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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k);
        ListNode *temp = head;
        int num = 0;
        while (temp)
        {
            num++;
            temp = temp->next;
        }
        int block = num / k;
        int rem = num % k;
        int i = 0;
        ListNode *last, first;
        while (head)
        {
            int j = 0;
            ans[i] = head;
            i++;
            last = head;
            while (last && j < block)
            {
                head = last;
                last = last->next;
                j++;
            }
            if (last && rem)
            {
                head = last;
                last = last->next;
                rem--;
            }
            head->next = NULL;
            head = last;
        }
        return ans;
    }
};

int main()
{

    return 0;
}