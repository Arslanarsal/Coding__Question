#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);
        stack<pair<int, int>> sleft, sright;
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while (!sleft.empty() && sleft.top().first > arr[i])
            {
                cnt += sleft.top().second;
                sleft.pop();
            }
            sleft.push({arr[i], cnt});
            left[i] = cnt;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int cnt = 1;
            while (!sright.empty() && sright.top().first >= arr[i])
            {
                cnt += sright.top().second;
                sright.pop();
            }
            sright.push({arr[i], cnt});
            right[i] = cnt;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + (arr[i] * (long long)((left[i] * right[i]))));
        }
        return ans;
    }
    int sumSubarrayMaxs(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);
        stack<pair<int, int>> sleft, sright;
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while (!sleft.empty() && sleft.top().first < arr[i])
            {
                cnt += sleft.top().second;
                sleft.pop();
            }
            sleft.push({arr[i], cnt});
            left[i] = cnt;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int cnt = 1;
            while (!sright.empty() && sright.top().first <= arr[i])
            {
                cnt += sright.top().second;
                sright.pop();
            }
            sright.push({arr[i], cnt});
            right[i] = cnt;
        }
        int mod = 1e9 + 7;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + (arr[i] * (long long)((left[i] * right[i]))));
        }
        return ans;
    }

public:
    long long subArrayRanges(vector<int> &nums)
    {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};

int main()
{

    return 0;
}