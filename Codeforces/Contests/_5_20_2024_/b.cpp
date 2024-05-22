#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // Disable synchronization with C I/O for faster input/output
    cin.tie(0);                  // Untie cin and cout

    int n;
    cin >> n;
    while (n--)
    {
        int siz;
        cin >> siz;
        string str;
        cin >> str;

        // Step 1: Collect distinct characters and sort them
        set<char> distinct(str.begin(), str.end());       // Directly initialize the set with the string
        vector<char> s(distinct.begin(), distinct.end()); // Convert the set to a vector

        // Step 2: Create the mapping for characters
        unordered_map<char, char> mp;
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            mp[s[i]] = s[j];
            mp[s[j]] = s[i];
            i++;
            j--;
        }

        // Step 3: Transform the input string using the mapping
        string ans;
        ans.reserve(siz); // Reserve space for the result string to avoid reallocations
        for (char ch : str)
        {
            ans += mp[ch];
        }

        // Step 4: Output the result
        cout << ans << "\n";
    }

    return 0;
}
