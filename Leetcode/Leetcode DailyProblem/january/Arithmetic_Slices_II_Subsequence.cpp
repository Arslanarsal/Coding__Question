#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int range = abs(nums[n - 1] - nums[0]);

    int s = 0;
    int ans = 0;
    int count = 0;
    for (int i = 0; i <= range; i++)
    {
        count = 1;

        for (int j = 0; j < n; j++)
        {
            s = j;
            for (int k = j+1; k < n; k++)
            {
                if (abs(nums[s] - nums[j]) == i)
                {
                    s = j;
                    count++;
                }
            }
        }
        cout << count << endl;
        if (i == 0 && count > 3)
        {
            ans += pow(2, count - 1);
        }
        else if (count == 3)
        {
            ans += 1;
        }
        else if (count > 3)
        {
            count = count - 3;
            count = count * 3;
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