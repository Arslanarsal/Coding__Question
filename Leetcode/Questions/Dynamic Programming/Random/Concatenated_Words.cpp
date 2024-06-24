#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
//     unordered_map<string, bool> dp;
//     bool isConatenate(string s, unordered_set<string> &st)
//     {
//         if (dp.count(s))
//         {
//             return dp[s];
//         }

//         int n = s.size();
//         for (int i = 0; i < n; i++)
//         {
//             if ((st.count(s.substr(0, i + 1)) && st.count(s.substr(i + 1))) || (st.count(s.substr(0, i + 1)) && isConatenate(s.substr(i + 1), st)))
//             {
//                 return dp[s] = true;
//             }
//         }
//         return dp[s] = false;
//     }

// public:
//     vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
//     {
//         unordered_set<string> st(words.begin(), words.end());

//         vector<string> ans;
//         int n = words.size();
//         for (int i = 0; i < n; i++)
//         {
//             if (isConatenate(words[i], st))
//             {
//                 ans.push_back(words[i]);
//             }
//         }
//         return ans;
//     }
// };

class TrieNode
{
public:
    TrieNode *chld[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            chld[i] = NULL;
        }
        isEnd = false;
    }
    void endHere()
    {
        isEnd = true;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    TrieNode *getRoot()
    {
        return root;
    }
    void constructTrie(string word)
    {
        TrieNode *temp = root;
        int len = word.length();
        for (int i = 0; i < len; i++)
        {
            if (!temp->chld[word[i] - 'a'])
                temp->chld[word[i] - 'a'] = new TrieNode();
            temp = temp->chld[word[i] - 'a'];
            if (i == len - 1)
                temp->endHere();
        }
    }
    void trieFromWords(vector<string> &words)
    {
        for (string &word : words)
        {
            constructTrie(word);
        }
    }
};



class Solution
{
public:
    bool f(string word, int endCnt, TrieNode *root)
    {
        if (word.empty())
            return endCnt > 1;
        TrieNode *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->chld[word[i] - 'a'])
                temp = temp->chld[word[i] - 'a'];
            else
                return 0;
            if (temp->isEnd)
            {
                if (f(word.substr(i + 1), endCnt + 1, root))
                    return 1;
            }
        }
        return 0;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        Trie *trie = new Trie();
        trie->trieFromWords(words);
        vector<string> ans;
        TrieNode *head = trie->getRoot();
        for (string &word : words)
        {
            if (f(word, 0, head))
                ans.push_back(word);
        }
        return ans;
    }
};

int main()
{

    return 0;
}