#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(N * Log(N))
    Space complexity: O(N)

    Where N is the size of given array.
*/

vector<int> replaceWithRank(vector<int> &arr, int n)
{
    // Make copy of array and sort it in non-decreasing order.
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());

    // Consist mapping of each element with its rank.
    unordered_map<int, int> hashMap;

    int rank = 1;

    // Find Rank of each element.
    for (int i = 0; i < n; i++)
    {
        if (!hashMap.count(temp[i]))
        {
            hashMap[temp[i]] = rank;
            rank++;
        }
    }

    // Replace each element with its corresponding rank.
    for (int i = 0; i < n; i++)
    {
        arr[i] = hashMap[arr[i]];
    }

    return arr;
}
int main()
{
    vector<int> v = {1, 2, 6, 9, 2};
    v = replaceWithRank(v, 5);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}