#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int ans = 0;
    int max = INT_MAX;
    int min = INT_MIN;
    bool flag = false;
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] >= '0' && s[i] <= '9')
        {

            if (flag)
            {
                if ((-1 * (ans * 1LL * 10) + (s[i] - '0')) < min)
                {
                    return ans;
                }

                ans = ((ans * 10) + (s[i] - '0'));
                ans= ans*-1;
                cout << ans << endl;
                flag = false;
            }
            else
            {
                if (((ans * 1LL * 10) + (s[i] - '0')) > max)
                {

                    return ans;
                }

                ans = (ans * 10) + (s[i] - '0');
            }
        }
        else if (s[i] == '-')
        {
            cout << "Enter in minue" << endl;
            if (ans == 0)
            {
                flag = true;
            }
            else
            {
                ans *= -1;
            }
        }
        else if (s[i] == ' ' || s[i] == '+')
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return ans;
}

int main()
{
    string s = "-21";
    cout << myAtoi(s);

    return 0;
}