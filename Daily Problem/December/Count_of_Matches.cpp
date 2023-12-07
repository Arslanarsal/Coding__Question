#include <bits/stdc++.h>
using namespace std;


    int numberOfMatches(int n)
    {
        int ans = 0;
        while (n > 1)
        {
            if (n % 2)
            {
                ans += (n / 2);
                n = (n / 2) + 1;
            }
            else
            {
                ans += (n / 2);
                n = (n / 2);
            }
        }
        return ans;
    }


int main()
{
    cout<<numberOfMatches(13);

    return 0;
}