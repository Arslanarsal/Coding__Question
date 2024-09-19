#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int conver(string s)
    {
        int ans = s[0] - '0';
        ans = ((ans * 10) + (s[1] - '0')) * 60;

        int temp = s[3] - '0';
        temp = ((temp * 10) + (s[4] - '0'));
        return ans + temp;
    }

public:
    int findMinDifference(vector<string> &timePoints)
    {
        int n = timePoints.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = conver(timePoints[i]);
        }
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, arr[i] - arr[i - 1]);
        }
        int temp = arr[0];
        temp += 1440 - arr[n - 1];
        ans = min(ans, temp);
        return ans;
    }
};

int main()
{

    return 0;
}