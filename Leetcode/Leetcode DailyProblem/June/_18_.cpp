#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size();
        int ans = 0;
        int maxele = 0;
        vector<pair<int, int>> p;

        for (int i = 0; i < n; i++)
        {
            p.push_back({difficulty[i], profit[i]});
        }
        sort(p.begin(), p.end());
        sort(worker.begin(), worker.end());
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j < n && p[j].first <= worker[i])
            {
                maxele = max(maxele, p[j].second);
                j++;
            }
            ans += maxele;
        }
        return ans;
    }
};

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size();
        int ans = 0;
        int maxele = 0;
        vector<pair<int, int>> p;

        // Create pairs of difficulty and profit and sort them by difficulty
        for (int i = 0; i < n; i++)
        {
            p.push_back({difficulty[i], profit[i]});
        }
        sort(p.begin(), p.end());

        // Sort the worker vector to match jobs with their abilities
        sort(worker.begin(), worker.end());

        int j = 0;
        for (int i = 0; i < worker.size(); i++)
        {
            while (j < n && p[j].first <= worker[i])
            {
                maxele = max(maxele, p[j].second);
                j++;
            }
            ans += maxele;
        }
        return ans;
    }
};

int main()
{

    return 0;
}