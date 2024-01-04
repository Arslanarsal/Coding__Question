#include <bits/stdc++.h>
using namespace std;

bool hasTrailingZeros(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!(nums[i] & 1))
        {
            ans++;
        }
        if (ans > 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> v ={1,3,5,7,9};
    cout<<hasTrailingZeros(v);

    return 0;
}