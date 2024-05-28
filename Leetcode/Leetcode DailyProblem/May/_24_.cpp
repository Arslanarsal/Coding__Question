#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<string> &words, vector<int> &freq, vector<int> &score, int i)
    {
        if (i >= words.size())
        {
            return 0;
        }
        int tempscr = 0;
        int j = 0;
        vector<int> tempfreq = freq;
        int n = words[i].size();
        while (j < n)
        {
            char ch = words[i][j] - 'a';
            if (tempfreq[ch] > 0)
            {
                tempfreq[ch]--;
                tempscr += score[ch];
            }
            else
            {
                break;
            }
            j++;
        }
        int take = 0;
        if (j == n)
        {
            take = solve(words, tempfreq, score, i + 1) + tempscr;
        }
        int nottake = solve(words, freq, score, i + 1);
        return max(take, nottake);
    }

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        vector<int> freq(26, 0);
        for (auto &&i : letters)
        {
            freq[i - 'a']++;
        }

        return solve(words, freq, score, 0);
    }
};

int main()
{

    return 0;
}