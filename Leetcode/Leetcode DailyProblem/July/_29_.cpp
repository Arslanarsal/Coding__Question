#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int teams = 0;
        int n = rating.size();
        for (int j = 1; j < n - 1; j++)
        {
            int leftsmall = 0;
            int rightgreater = 0;

            int leftgreater = 0;
            int rightsmall = 0;

            for (int i = 0; i < j; i++)
            {
                if (rating[i] < rating[j])
                {
                    leftsmall++;
                }
                else if (rating[i] > rating[j])
                {
                    leftgreater++;
                }
            }

            for (int i = j + 1; i < n; i++)
            {
                if (rating[i] < rating[j])
                {
                    rightsmall++;
                }
                else if (rating[i] > rating[j])
                {
                    rightgreater++;
                }
            }

            teams += ((leftsmall * rightgreater) + (leftgreater * rightsmall));
        }
        return teams;
    }
};

int main()
{

    return 0;
}