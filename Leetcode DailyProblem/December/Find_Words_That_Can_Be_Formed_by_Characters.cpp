#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        unordered_map<char, int> mpchar;
        for (auto &&i : chars)
        {
            mpchar[i]++;
        }
        int ans = 0;

        for (auto &&word : words)
        {
            unordered_map<char, int> temp;

            for (auto &&it : word)
            {
                temp[it]++;
            }
            int flag = true;

            for (auto &&it : temp)
            {
                if (mpchar[it.first] < it.second)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans += word.size();
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}