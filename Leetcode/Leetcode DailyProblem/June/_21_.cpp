#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int ans = 0;
        int n = customers.size();
        int temp = 0;
        int maxele = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (!grumpy[i])
            {
                ans += customers[i];
            }
            else
            {
                temp += customers[i];
            }
            if (i - j >= minutes)
            {
                if (grumpy[j])
                {
                    temp -= customers[j];
                }
                j++;
            }
            maxele = max(maxele, temp);
        }
        return ans + maxele;
    }
};
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        int total_satisfied = 0; // Total satisfied customers without using the technique
        int temp = 0;            // Temporary increase in satisfaction for current window
        int max_increase = 0;    // Maximum increase in satisfaction found
        int j = 0;               // Start of the sliding window

        for (int i = 0; i < n; i++)
        {
            if (!grumpy[i])
            {
                total_satisfied += customers[i];
            }
            else
            {
                temp += customers[i];
            }

            if (i - j + 1 > minutes)
            { // When window size exceeds the given minutes
                if (grumpy[j])
                {
                    temp -= customers[j];
                }
                j++;
            }

            max_increase = max(max_increase, temp);
        }

        return total_satisfied + max_increase;
    }
};

int main()
{

    return 0;
}