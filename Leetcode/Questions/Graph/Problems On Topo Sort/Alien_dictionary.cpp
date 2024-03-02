#include <bits/stdc++.h>
using namespace std;

string getAlienLanguage(vector<string> &dictionary, int k)
{

    vector<int> adj[k];
    int n = dictionary.size();
    vector<int> freq(k, 0);

    for (int i = 0; i < n - 1; i++)
    {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];
        int x = s1.size();
        int y = s2.size();
        int j = 0;
        while (j < x && j < y)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                freq[s2[j] - 'a']++;
                break;
            }
            j++;
        }
    }
    vector<int> p;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        if (!freq[i])
        {
            p.push_back(i);
        }
    }

    while (!p.empty())
    {
        int node = p[p.size() - 1];
        p.pop_back();

        ans.push_back(node);
        for (auto &&nei : adj[node])
        {
            freq[nei]--;
            if (!freq[nei])
            {
                p.push_back(nei);
            }
        }
    }
    string res = "";
    for (int i = 0; i < ans.size(); i++)
    {
        res += ((char)(ans[i] + 'a'));
    }
    return res;
}

int main()
{

    return 0;
}