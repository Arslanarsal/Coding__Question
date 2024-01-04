#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        vector<int> count(26, 0);
        int n = words.size();
        for (auto &&w : words)
        {
            for (auto &&i : w)
            {
                count[i - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i] % n != 0)
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