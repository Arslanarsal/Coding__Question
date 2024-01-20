#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        int S = s.size();
        int A = a.size();
        int B = b.size();
        vector<int> ai;
        vector<int> bi;
        int i = 0;

        while (i < S - A + 1 || i < S - B + 1)
        {
            if (i < S - A + 1 && s.substr(i, A) == a)
            {
                ai.push_back(i);
            }
            if (i < S - B + 1 && s.substr(i, B) == b)
            {
                bi.push_back(i);
            }
            i++;
        }
        int n1 = ai.size();
        int n2 = bi.size();
        vector<int> ans;
        i = 0;
        int j = 0;
        while (i < n1 && j < n2)
        {
            if (abs(ai[i] - bi[j]) <= k)
            {
                ans.push_back(ai[i]);
                i++;
                j++;
            }
            else if (ai[i] < bi[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    string s = "ocmm", a = "m", b = "oc";
    Solution sol;
    vector<int> ans;
    ans = sol.beautifulIndices(s, a, b, 3);
    // sol.beautifulIndices(s, a, b, 15);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}