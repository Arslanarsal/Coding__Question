#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void get_max_score(int n, vector<int> &a)
{
    int original_score = n - unordered_set<int>(a.begin(), a.end()).size();
    int best_l = -1, best_r = -1, best_score = original_score;

    for (int l = 0; l < n; ++l)
    {
        unordered_map<int, int> freq;
        for (int x : a)
            freq[x]++;
        int unique_count = freq.size();

        for (int r = l; r < n; ++r)
        {
            if (--freq[a[r]] == 0)
                unique_count--;
            int remaining_length = n - (r - l + 1);
            int new_score = remaining_length - unique_count;

            if (new_score > best_score || (new_score == best_score && remaining_length < n - (best_r - best_l + 1)))
            {
                best_score = new_score;
                best_l = l;
                best_r = r;
            }
        }
    }

    if (best_l == -1)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << best_l + 1 << " " << best_r + 1 << "\n";
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        get_max_score(n, a);
    }

    return 0;
}