#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalNumbers(vector<int> &digits)
    {
        set<string> st;
        int n = digits.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if ((k != i) && (k != j) && !(digits[k] & 1))
                        {
                            string temp = to_string(digits[i]);
                            temp += to_string(digits[j]);
                            temp += to_string(digits[k]);
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        return st.size();
    }
};

int32_t main()
{
    Solution sol;
    vector<int> digits = {0, 2, 2};
    cout << sol.totalNumbers(digits);

    return 0;
}