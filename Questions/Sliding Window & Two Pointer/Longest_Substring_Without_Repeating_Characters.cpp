#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity : O(N)
    Space Complexity : O(K)

    where N is the length of input string and
    K is the number of unique characters in the string
*/

int uniqueSubstrings(string input)
{
    int n = input.length();

    unordered_map<char, int> Umap;

    int ans = 0, i = 0, j = 0;

    while (i < n && j < n)
    {
        // Try to extend the range [i,j]
        if (Umap.find(input[j]) == Umap.end())
        {
            Umap[input[j]] = 1;
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            Umap.erase(input[i]);
            i++;
        }
    }

    return ans;
}

int main()
{
    cout << uniqueSubstrings("aab");

    return 0;
}