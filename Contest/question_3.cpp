#include <iostream>
#include <string>
using namespace std;
int minCostToEqualStrings(string &s1, string &s2, int x)
{
    int n = s1.size();
    int cost = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s1[i] != s2[i])
        {
            if (i + 1 < n && s1[i] == '0' && s1[i + 1] == '1')
            {
                s1[i] = '1';
                s1[i + 1] = '0';
                cost += x;
            }
            else
            {
                return -1;
            }
        }
    }

    return cost;
}

int main()
{
    string s1 = "1100011000";
    string s2 = "0101001010";
    int x = 2;
    int result1 =minCostToEqualStrings(s1, s2, x);
    cout << "Example 1 - Minimum cost: " << result1 << endl; // Output: 4

    // string s3 = "10110";
    // string s4 = "00011";
    // int x2 = 4;
    // int result2 = minOperations(s3, s4, x2);
    // cout << "Example 2 - Minimum cost: " << result2 << endl; // Output: -1

    return 0;
}
