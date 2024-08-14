#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int aiza_moves = 0, bisma_moves = 0;

        // Count possible moves for Aiza and Bisma
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == 'A' && s[i - 1] == 'A' && s[i + 1] == 'A')
            {
                aiza_moves++;
            }
            if (s[i] == 'B' && s[i - 1] == 'B' && s[i + 1] == 'B')
            {
                bisma_moves++;
            }
        }

        if (aiza_moves > bisma_moves)
        {
            cout << "aiza\n";
        }
        else
        {
            cout << "bisma\n";
        }
    }
    return 0;
}
