#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPermutationDifference(string s, string t)
    {
        int arr1[26] = {0};
        int arr2[26] = {0};
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            arr1[s[i] - 'a'] = i;
            arr2[t[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans += abs(arr1[i] - arr2[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}