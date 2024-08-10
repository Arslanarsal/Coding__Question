#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<ll> arr(4);
        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
        }

        int wins = 0;
        if ((arr[0] > arr[2] && arr[1] > arr[3]) || (arr[0] > arr[3] && arr[1] > arr[2]))
        {
            wins = 2;
        }
        else if ((arr[0] > arr[2] && arr[1] < arr[3]) || (arr[0] < arr[2] && arr[1] > arr[3]))
        {
            wins = 0;
        }
        else if ((arr[0] > arr[3] && arr[1] < arr[2]) || (arr[0] < arr[3] && arr[1] > arr[2]))
        {
            wins = 0;
        }
        else
        {

            if (arr[0] != arr[2] && arr[1] != arr[3])
            {
                if ((arr[0] == arr[3] && arr[1] > arr[2]) || (arr[0] > arr[3] && arr[1] == arr[2]))
                {
                    wins = 0;
                }
                else if ((arr[0] == arr[2] && arr[1] > arr[3]) || (arr[0] > arr[2] && arr[1] == arr[3]))
                {
                    wins = 0;
                }
            }
        }

        cout << wins << "\n";
    }

    return 0;
}
