#include <bits/stdc++.h>
using namespace std;

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
{
    vector<pair<int, pair<int, int>>> meetings;
    for (int i = 0; i < N; ++i)
    {
        meetings.push_back({F[i], {S[i], i}});
    }
    sort(meetings.begin(), meetings.end());
    vector<int> ans;
    int last = -1;
    for (const auto &meeting : meetings)
    {
        int start = meeting.second.first;
        int index = meeting.second.second;
        if (start > last)
        {
            last = meeting.first;
            ans.push_back(index + 1);
        }
    }
    return ans;
}



int main()
{
    int N = 6;
    vector<int> S = {1, 3, 0, 5, 8, 5};
    vector<int> F = {2, 4, 6, 7, 9, 9};
    vector<int> ans = maxMeetings(N, S, F);
    for (auto &&i : ans)
    {
        cout << i << "  ";
    }

    return 0;
}