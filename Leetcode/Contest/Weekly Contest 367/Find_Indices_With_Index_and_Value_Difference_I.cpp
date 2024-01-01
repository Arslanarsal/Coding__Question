#include <bits/stdc++.h>
using namespace std;

vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            if ((abs(i - j) >= indexDifference) && (abs(nums[i] - nums[j]) >= valueDifference))
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}

int main()
{

    vector<int> nums = {1, 2, 3};

    vector<int> ans = findIndices(nums, 2, 4);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}