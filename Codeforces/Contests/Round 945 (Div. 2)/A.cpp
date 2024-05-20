#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        priority_queue<int> pq;
        if (a > 0)
        {
            pq.push(a);
        }
        if (b > 0)
        {
            pq.push(b);
        }
        if (c > 0)
        {
            pq.push(c);
        }
        int res = 0;
        while (pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
              pq.pop();
            x--, y--;
            res++;
            if (x > 0)
            {
                pq.push(x);
            }
            if (y > 0)
            {
                pq.push(y);
            }
        }
        if (pq.size() && pq.top() % 2)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << res << "\n";
        }
    }

    return 0;
}