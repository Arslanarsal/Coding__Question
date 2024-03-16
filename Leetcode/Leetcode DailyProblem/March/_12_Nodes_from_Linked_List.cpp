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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        vector<int> nums;
        ListNode *temp = head;
        while (temp)
        {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        unordered_map<int, int> mp;
        mp[0] = 0;
        int pre = 0;
        int j = INT_MAX;
        int i = 0;
        int x = 0;
        for (int k = 0; k < nums.size(); k++)
        {
            pre += nums[k];
            if (mp.count(pre))
            {
                if (x < k - mp[pre])
                {
                    x = k - mp[pre];
                    j = mp[pre];
                    i = k + 1;
                }
            }
            else
            {
                mp[pre] = k + 1;
            }
        }
        i++;
        if (j == INT_MAX)
        {
            return head;
        }

        temp = head;
        int k = 1;
        while (k < j)
        {
            temp = temp->next;
            k++;
        }

        ListNode *nex = temp;
        while (k < i)
        {
            nex = nex->next;
            k++;
        }

        if (j == 0)
        {
            return nex;
        }
        temp->next = nex;
        return head;
    }
};

int main()
{
    vector<int> nums = {1, 2, -3, 3, 1};
    // vector<int> nums = {1,2,3,-3,4};
    // vector<int> nums = {1, 2, 3, -3, -2};
    unordered_map<int, int> mp;
    mp[0] = 0;
    int pre = 0;
    int j = INT_MAX;
    int i = 0;
    int x = 0;
    for (int k = 0; k < nums.size(); k++)
    {
        pre += nums[k];
        if (mp.count(pre))
        {
            if (x < k - mp[pre])
            {
                x = k - mp[pre];
                j = mp[pre];
                i = k + 1;
            }
        }
        else
        {
            mp[pre] = k + 1;
        }
    }
    i++;
    cout << j << " " << i;
    return 0;
}