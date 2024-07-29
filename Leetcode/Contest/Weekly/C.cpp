#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        unordered_map<int, int> mpp;

        for (int it : nums2)
        {
            mpp[it * k]++;
        }
        long long result = 0;
        for (int it : nums1)
        {
            for (int i = 1; i <= sqrt(it); i++)
            {
                if (it % i == 0)
                {
                    int comp = it / i;
                    if (mpp.count(i))
                    {
                        result += mpp[i];
                    }
                    if (comp != i && mpp.count(comp))
                    {
                        result += mpp[comp];
                    }
                }
            }
        }

        return result;
    }
};

int main()
{

    return 0;
}