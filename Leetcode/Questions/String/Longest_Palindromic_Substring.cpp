#include <bits/stdc++.h>
using namespace std;
// bool check(string &s, int i, int j)
// {
//     while (i < j)
//     {
//         if (s[i] != s[j])
//         {
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }
// string longestPalindrome(string s)
// {
//     vector<string> v;
//     int n = s.size();
//     for (int i = 0; i < n; i++)
//     {
//         string temp = "";
//         for (int j = i; j < n; j++)
//         {
//             temp += s[j];
//             v.push_back(temp);
//         }
//     }
//     int s1 = -1;
//     string substring;
//     n = v.size();
//     for (int i = 0; i < n; i++)
//     {
//         int si = v[i].size();
//         if (check(v[i], 0, si-1))
//         {
//             if (si > s1)
//             {
//                 substring = v[i];
//                 s1 = si;
//             }
//         }
//     }
//     return substring;
// }

int solve(int i, int j, string &s)
{
    int l = i, r = j, n = s.size();
    while (l >= 0 && r < n && s[l] == s[r])
    {
        l--;
        r++;
    }
    return i - l;
}

string longestPalindrome(string s)
{
    int n = s.size(), oddSize = 0, evenSize = 0, evenCentre, oddCentre;

    for (int i = 0; i < n; i++)
    {
        int l = solve(i, i, s);
        if (l > oddSize)
        {
            oddCentre = i;
            oddSize = l;
        }
        if (i == n - 1)
            break;
        l = solve(i, i + 1, s);
        if (l > evenSize)
        {
            evenCentre = i;
            evenSize = l;
        }
    }

    string odd = s.substr(oddCentre - oddSize + 1, oddSize * 2 - 1);
    string even = evenSize ? s.substr(evenCentre - evenSize + 1, evenSize * 2) : "";

    return even.size() > odd.size() ? even : odd;
}
int main()
{
    string a = "cbbd";
    cout << longestPalindrome(a);

    return 0;
}