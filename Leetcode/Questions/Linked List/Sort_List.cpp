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

    ListNode *findmiddle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (!left)
        {
            return right;
        }
        else if (!right)
        {
            return left;
        }
        ListNode *head = NULL;
        if (left->val < right->val)
        {
            head = left;
            left = left->next;
        }
        else
        {
            head = right;
            right = right->next;
        }
        ListNode *temp = head;
        while (left && right)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if (left)
        {
            temp->next = left;
        }
        else if (right)
        {
            temp->next = right;
        }
        return head;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *middle = findmiddle(head);
        ListNode *left = head;
        ListNode *right = middle->next;
        middle->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};

int main()
{

    return 0;
}