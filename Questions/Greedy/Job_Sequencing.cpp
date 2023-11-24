#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[2] > job2[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    int n1 = 0;
    int n2 = 0;
    vector<int> ans(n, 0);
    sort(jobs.begin(), jobs.end(), compare);
    for (int i = 0; i < jobs.size(); i++)
    {
        for (int j = jobs[i][1] - 1; j >= 0; j--)
        {
            if (ans[j] == 0)
            {
                ans[j] = 1;
                n1++;
                n2 += jobs[i][2];
                break;
            }
        }
    }
    vector<int> ans1;
    ans1.push_back(n1);
    ans1.push_back(n2);
    return ans1;
}

int main()
{

    vector<vector<int>> jobs = {{1, 2, 30},
                                {2, 2, 40},
                                {3, 1, 10},
                                {4, 1, 10}};

    vector<int> ans = jobScheduling(jobs);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
