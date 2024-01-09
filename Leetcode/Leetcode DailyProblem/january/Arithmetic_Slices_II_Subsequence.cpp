#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();
    int count = 0;
    unordered_map<int, int> mp[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            auto it = mp[j].find(diff);

            count = it == mp[j].end() ? 0 : it->second;
            mp[i][diff] += count + 1;
            ans += count;
        }
    }
    return ans;
}

        
        
    
                
                
          
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    cout << numberOfArithmeticSlices(v);

    return 0;
}