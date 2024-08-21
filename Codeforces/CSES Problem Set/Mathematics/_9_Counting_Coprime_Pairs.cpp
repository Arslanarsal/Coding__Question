#include <bits/stdc++.h>
using namespace std;
#define int long long int

int n, maxvalue = 1e6 + 1; 
vector<int> arr;

int32_t main()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> divisiorOf(maxvalue);
    for (int i = 2; i < maxvalue; i++)
    {
        if (divisiorOf[i].empty())
        {
            divisiorOf[i].push_back(i);
            for (int j = i * 2; j < maxvalue; j += i)
            {
                divisiorOf[j].push_back(i);
            }
        }
    }

    vector<int> valueDivisibleBy(maxvalue), primeDivisorOf(maxvalue);
    
    for (int i = 0; i < n; i++)
    {
        for (int mask = 1; mask < (1 << divisiorOf[arr[i]].size()); mask++)
        {
            int combination = 1;
            int primedivisor = 0;
            for (int pos = 0; pos < divisiorOf[arr[i]].size(); pos++)
            {
                if ((1 << pos) & mask)
                {
                    combination *= divisiorOf[arr[i]][pos];
                    primedivisor++;
                }
            }
            valueDivisibleBy[combination]++;
            primeDivisorOf[combination] = primedivisor;
        }
    }

    int totalpair = (n * (n - 1)) / 2;
    int validPair = 0;
    for (int i = 1; i < maxvalue; i++)
    {
        if (primeDivisorOf[i] & 1)
        {
            validPair += valueDivisibleBy[i] * (valueDivisibleBy[i] - 1) / 2;
        }
        else
        {
            validPair -= valueDivisibleBy[i] * (valueDivisibleBy[i] - 1) / 2;
        }
    }

    cout << totalpair - validPair << endl;

    return 0;
}
