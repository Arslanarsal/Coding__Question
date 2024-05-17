#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;

        q.push({beginWord});
        vector<string> onlevel;
        onlevel.push_back(beginWord);
        vector<vector<string>> ans;
        int level = 0;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            if (vec.size() > level)
            {
                level++;
                for (auto &&ch : onlevel)
                {
                    st.erase(ch);
                }
            }
            string word = vec.back();
            if (word == endWord)
            {
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {
                char orignal = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                        onlevel.push_back(word);
                    }
                }
                word[i] = orignal;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}