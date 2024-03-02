#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int power = 1;
        vector<int> ans;
        int num;
        cin >> num;
        while (num)
        {
            if (num % 10 > 0)
            {
                ans.push_back((num % 10) * power);
            }
            num /= 10;
            power *= 10;
        }
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}