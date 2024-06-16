#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
//     string freqToString(const unordered_map<char, int> &freq)
//     {
//         string s;
//         for (auto &p : freq)
//         {
//             s += p.first + to_string(p.second);
//         }
//         return s;
//     }

//     int solve(int i, vector<string> &stickers, unordered_map<char, int> &freq, unordered_map<string, int> &dp)
//     {
//         if (i < 0)
//             return 1e9;

//         if (!freq.size())
//             return 0;

//         string s = freqToString(freq);
//         if (dp.count(s))
//             return dp[s];

//         bool flage = false;
//         unordered_map<char, int> temp = freq;
//         for (int j = 0; j < stickers[i].size(); j++)
//         {
//             char c = stickers[i][j];
//             if (temp.count(c))
//             {
//                 temp[c]--;
//                 flage = true;
//                 if (temp[c] == 0)
//                 {
//                     temp.erase(c);
//                 }
//             }
//         }
//         int take = INT_MAX;
//         if (flage)
//         {
//             take = 1 + solve(i, stickers, temp, dp);
//         }
//         int nottake = solve(i - 1, stickers, freq, dp);
//         return dp[s] = min(take, nottake);
//     }

// public:
//     int minStickers(vector<string> &stickers, string target)
//     {
//         unordered_map<char, int> mp;
//         for (auto c : target)
//         {
//             mp[c]++;
//         }
//         int n = stickers.size();
//         unordered_map<string, int> dp;
//         int ans = solve(n - 1, stickers, mp, dp);
//         return ans == 1e9 ? -1 : ans;
//     }
// };

#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

class Solution
{
    string freqToString(const unordered_map<char, int> &freq)
    {
        string s;
        for (auto &p : freq)
        {
            s += p.first + to_string(p.second);
        }
        return s;
    }

    int solve(int i, vector<string> &stickers, unordered_map<char, int> &freq, unordered_map<string, int> &dp)
    {
        if (!freq.size())
            return 0;

        string s = freqToString(freq);
        if (dp.count(s))
            return dp[s];

        int minStickers = INT_MAX;
        for (int k = 0; k <= i; k++)
        {
            unordered_map<char, int> temp = freq;
            bool used = false;
            for (char c : stickers[k])
            {
                if (temp.count(c))
                {
                    used = true;
                    temp[c]--;
                    if (temp[c] == 0)
                        temp.erase(c);
                }
            }
            if (used)
            {
                int result = solve(i, stickers, temp, dp);
                if (result != INT_MAX)
                    minStickers = min(minStickers, 1 + result);
            }
        }
        dp[s] = minStickers;
        return minStickers;
    }

public:
    int minStickers(vector<string> &stickers, string target)
    {
        unordered_map<char, int> mp;
        for (auto c : target)
        {
            mp[c]++;
        }
        int n = stickers.size();
        unordered_map<string, int> dp;
        int ans = solve(n - 1, stickers, mp, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};


int main()
{

    return 0;
}