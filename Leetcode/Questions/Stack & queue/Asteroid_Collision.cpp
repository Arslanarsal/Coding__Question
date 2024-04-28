#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        vector<int> st;
        for (auto &&i : asteroids)
        {
            while (!st.empty() && i < 0 && st[st.size() - 1] > 0)
            {
                int sum = i + st[st.size() - 1];
                if (sum < 0)
                {
                    st.pop_back();
                }
                else if (sum > 0)
                {
                    i = 0;
                }
                else
                {
                    st.pop_back();
                    i = 0;
                }
            }
            if (i != 0)
            {
                st.push_back(i);
            }
        }

        return st;
    }
};

int main()
{
    Solution sol;
    vector<int> st = {-2, -1, 1, 2};
    sol.asteroidCollision(st);

    return 0;
}