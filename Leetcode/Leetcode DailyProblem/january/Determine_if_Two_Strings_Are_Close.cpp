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

        vector<bool> s3(26, false);
        vector<bool> s4(26, false);
        for (int i = 0; i < n; i++)
        {
            s1[word1[i] - 'a']++;
            s2[word2[i] - 'a']++;

            s3[word1[i] - 'a'] = true;
            s4[word2[i] - 'a'] = true;
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2 && s3 == s4;
    }
};

int main()
{

    return 0;
}