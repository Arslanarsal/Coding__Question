#include <bits/stdc++.h>
using namespace std;

string solve(int A, int B)
{
    // X * 2 + Y * 4 = 2 * A
    // X * 2 + Y * 1 = B
    // 3 * Y = 2 * A - B
    // Y = (2 * A - B)/3

    // X + Y * 2 = A
    // 4 * X + 2 * Y = 2 * B
    // -3 * X = A - 2 * B
    // X = (2 * B - A) / 3

    if ((2 * A - B) % 3 || (2 * A - B) < 0 || (2 * B - A) % 3 || (2 * B - A) < 0)
        return "NO\n";
    return "YES\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        cout << solve(A, B) << "\n";
    }
}