#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity : O(N)
    Space complexity : O(N)

    Where N is the number of elements in the array.
*/

int requiredCandies(vector<int> &students)
{

    int n = students.size();
    int candies[n + 1];
    for (int i = 0; i <= n; i++)
    {
        candies[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (students[i] > students[i - 1])
        {
            candies[i] += candies[i - 1];
        }
    }

    // Second pass, give candies to the left.
    for (int i = n - 2; i >= 0; i--)
    {

        /*
            This time, we need to consider max{candies[i], candies[i+1]+1}.
            Since we don't know whether the ascending or descending trend is larger.
        */
        if (students[i] > students[i + 1] && candies[i] < candies[i + 1] + 1)
        {
            candies[i] = candies[i + 1] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += candies[i];
    }
    return ans;
}

int main()
{
    vector<int> student = {1, 5, 3, 4, 6};
    cout << requiredCandies(student);

    return 0;
}