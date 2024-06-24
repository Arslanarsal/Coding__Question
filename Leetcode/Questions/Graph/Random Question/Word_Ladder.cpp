#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, string> mp;
        unordered_map<string, bool> visited;
        for (auto &&it : wordList)
        {
            mp[it] = it;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        if (!mp.count(endWord))
        {
            return 0;
        }
        visited[beginWord] = true;
        while (!q.empty())
        {
            auto it = q.front();
            string s = it.first;
            int l = it.second;
            q.pop();
            if (s == endWord)
            {
                return l;
            }
            int n = s.size();
            for (int i = 0; i < n; i++)
            {
                char orignal = s[i];
                for (char j = 'a'; j <= 'z'; j++)
                {
                    s[i] = j;
                    if (mp.count(s) && !visited[s])
                    {
                        q.push({mp[s], l + 1});
                        visited[s] = true;
                    }
                }
                s[i] = orignal;
            }
        }
        return 0;
    }
};

int main()
{

    return 0;
}