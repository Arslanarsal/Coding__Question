#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;


    //     int arr[26] = {0};
    //     for (int i = 0; i < s[i]; i++)
    //     {
    //         arr[s[i] - 97]++;
    //     }
    //     for (int i = 0; i < t[i]; i++)
    //     {
    //         arr[t[i] - 97]--;
    //     }

    //     for (int i = 0; i < 26; i++)
    //     {
    //         if (arr[i] != 0)
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    }
};

int main()
{
    string s1 = "anagrsam";
    string s2 = "nagaram";
    Solution sol;

    cout << sol.isAnagram(s1, s2);
    return 0;
}