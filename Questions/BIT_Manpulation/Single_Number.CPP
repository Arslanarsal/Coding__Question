#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}
int main()
{
    vector<int> v = {2,8,2,5,5,8,3,3,5};
    cout << singleNumber(v);

    return 0;
}