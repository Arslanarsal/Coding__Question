#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
#include <unordered_set>

class Solution
{
public:
    bool reportSpam(std::vector<std::string> &message, std::vector<std::string> &bannedWords)
    {
        unordered_set<string> bannedSet(bannedWords.begin(), bannedWords.end());
        int count = 0;

        for (const auto &word : message)
        {
            if (bannedSet.find(word) != bannedSet.end())
            {
                count++;

                if (count >= 2)
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}