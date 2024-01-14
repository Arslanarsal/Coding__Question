#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int n = word1.size();
        if (n != word2.size())
        {
            return false;
        }

        vector<int> s1(26, 0);
        vector<int> s2(26, 0);
        for (int i = 0; i < n; i++)
        {
            s1[word1[i] - 'a']++;
            s2[word2[i] - 'a']++;
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < 26; i++)
        {
            if (s1[i] != s2[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}