#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>> &queries)
    {
        int n = s.length();
        vector<int> charCount(26, 0);

        for (int i = 0; i < n / 2; i++)
        {
            charCount[s[i] - 'a']++;
        }

        vector<bool> answer;

        for (auto &query : queries)
        {
            int a = query[0], b = query[1], c = query[2], d = query[3];

            for (int i = a; i <= b; i++)
            {
                charCount[s[i] - 'a']--;
            }
            for (int i = c; i <= d; i++)
            {
                charCount[s[i] - 'a']++;
            }

            int oddCount = 0;
            for (int count : charCount)
            {
                if (count % 2 != 0)
                {
                    oddCount++;
                }
                if (oddCount > 1)
                {
                    break;
                }
            }

            answer.push_back(oddCount <= 1);

            for (int i = a; i <= b; i++)
            {
                charCount[s[i] - 'a']++;
            }
            for (int i = c; i <= d; i++)
            {
                charCount[s[i] - 'a']--;
            }
        }

        return answer;
    }
};

int main()
{

    return 0;
}