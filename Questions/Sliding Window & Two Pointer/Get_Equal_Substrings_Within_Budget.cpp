#include <bits/stdc++.h>
using namespace std;
int equalSubstring(string s, string t, int maxCost)
{
    int head, tail = 0, ans = 0, cost = 0;
    for (head = 0; head < s.size(); head++)
    {
        cost += abs(s[head] - t[head]);
        cout << cost << endl;
        while (cost > maxCost)
        {
            cost = cost - abs(s[tail] - t[tail]);
            tail++;
        }
        ans = max(ans, head - tail + 1);
    }
    return ans;
}
int main()
{
    string s = "abcd";
    string t = "acde";
    cout << equalSubstring(s, t, 0);

    return 0;
}