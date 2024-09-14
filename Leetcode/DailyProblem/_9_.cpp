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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        int round = 0;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0, j = 0;
        while (head)
        {
            while (head && j < n - round)
            {
                ans[i][j] = head->val;
                head = head->next;
                j++;
            }
            j--;
            i++;
            while (head && i < m - round)
            {
                ans[i][j] = head->val;
                head = head->next;
                i++;
            }
            i--;
            j--;
            while (head && j >= round)
            {
                ans[i][j] = head->val;
                head = head->next;
                j--;
            }
            j++;
            i--;
            while (head && i > round)
            {
                ans[i][j] = head->val;
                head = head->next;
                i--;
            }
            i++;
            j++;
            round++;
        }
        return ans;
    }
};

int main()
{
    // Solution sol;
    // vector<int> v = {6, 4, 3, 2, 7, 6, 2};

    return 0;
}