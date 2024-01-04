#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums)
{
    map<int, int> freq;
    for (auto &&j : nums)
    {
        freq[j]++;
    }
    int ans = 0;
    for (auto &&it : freq)
    {

        int num = it.second;

        if (num == 1)
        {
            return -1;
        }
        else if (num == 2)
        {
            ans++;
        }
        else
        {
            int q = num / 3;
        

            ans += q;
            if (num > (3 * q))
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {2, 3, 3, 2, 2, 4, 2, 3, 4};
    cout << minOperations(v);
    return 0;
}