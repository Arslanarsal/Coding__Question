#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        int q = 100000 + 10;
        int arr[q];
        memset(arr, -1, sizeof(arr));
        int n = matches.size();
        
        // Update array based on match outcomes
        for (int i = 0; i < n; i++)
        {
            int win = matches[i][0];
            int los = matches[i][1];
            if (arr[win] == -1)
            {
                arr[win] = 0;
            }
            arr[los] == -1 ? arr[los] = 1 : arr[los]++;
        }
        
        vector<int> one, two;
        
        // Populate vectors based on scores
        for (int i = 0; i < q; i++)
        {
            if (arr[i] == 0)
            {
                one.push_back(i);
            }
            else if (arr[i] == 1)
            {
                two.push_back(i);
            }
        }
        
        return {one, two};
    }
};
int main()
{

    return 0;
}